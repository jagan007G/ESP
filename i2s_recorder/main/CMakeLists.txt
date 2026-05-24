idf_component_register(SRCS "i2s_recorder_main.c" "audio_driver.c" "sdcard.c" "microphone.c" "speaker.c"
                    PRIV_REQUIRES esp_driver_i2s fatfs
                    INCLUDE_DIRS ${IDF_PATH}/examples/peripherals/i2s/common
)

