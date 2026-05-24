#include <stdio.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "esp_vfs_fat.h"

#include "audio_pin_config.h"
#include "audio_driver.h"
#include "microphone.h"
#include "speaker.h"
#include "sdcard.h"
#include "wav_header.h"

static const char *TAG = "main";

void record_to_sd(const char *filename) {
    ESP_LOGI(TAG, "Opening file for recording: %s", filename);
    FILE *f = fopen(filename, "wb");
    if (!f) {
        ESP_LOGE(TAG, "Failed to open file for writing");
        return;
    }

    // Write placeholder header
    wav_header_t header;
    memset(&header, 0, sizeof(wav_header_t));
    fwrite(&header, sizeof(wav_header_t), 1, f);

    int16_t *buffer = malloc(AUDIO_BUFFER_SIZE);
    size_t total_bytes = 0;
    
    ESP_LOGI(TAG, "Recording %d seconds...", RECORD_TIME_SEC);
    int chunks = (RECORD_TIME_SEC * SAMPLE_RATE * 4) / AUDIO_BUFFER_SIZE; // *4 for stereo 16bit
    
    for (int i = 0; i < chunks; i++) {
        size_t r = microphone_read(buffer, AUDIO_BUFFER_SIZE);
        if (r > 0) {
            fwrite(buffer, 1, r, f);
            total_bytes += r;
        }
    }
    ESP_LOGI(TAG, "Recording Done.");

    // Update Header
    fseek(f, 0, SEEK_SET);
    generate_wav_header(&header, total_bytes, SAMPLE_RATE);
    fwrite(&header, sizeof(wav_header_t), 1, f);

    fclose(f);
    free(buffer);
}

void play_from_sd(const char *filename) {
    ESP_LOGI(TAG, "Playing file: %s", filename);
    FILE *f = fopen(filename, "rb");
    if (!f) {
        ESP_LOGE(TAG, "Failed to open file for reading");
        return;
    }

    fseek(f, sizeof(wav_header_t), SEEK_SET); // Skip header

    int16_t *buffer = malloc(AUDIO_BUFFER_SIZE);
    size_t r;

    while ((r = fread(buffer, 1, AUDIO_BUFFER_SIZE, f)) > 0) {
        speaker_write(buffer, r);
    }
    ESP_LOGI(TAG, "Playback Done.");

    fclose(f);
    free(buffer);
}

void app_main(void) {
    if (sd_card_mount() != ESP_OK){
        ESP_LOGE(TAG, "SD mount failed");
    };
    if (audio_driver_init() != ESP_OK){
        ESP_LOGE(TAG, "AUDIO init failed");
    };
    

    int file_index = 0;

    while (1) 
    {
        char filename[64];

        sprintf(filename, MOUNT_POINT"/rec_%d.wav", file_index);

        ESP_LOGI(TAG, "Recording File: %s", filename);

        record_to_sd(filename);

        ESP_LOGI(TAG, "Audio Saved");

        vTaskDelay(pdMS_TO_TICKS(3000));

        play_from_sd(filename);

        ESP_LOGI(TAG, "WAIT 3sec");

        vTaskDelay(pdMS_TO_TICKS(3000));

        file_index++;
    }
}
