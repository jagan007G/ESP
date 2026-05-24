#include "speaker.h"
#include "audio_driver.h"
#include "esp_log.h"

void speaker_write(int16_t *buffer, size_t data_len) {
    size_t bytes_written = 0;
    i2s_chan_handle_t tx = audio_driver_get_tx_handle();
    if (!tx) return;

    i2s_channel_write(tx, buffer, data_len, &bytes_written, 1000);
}
