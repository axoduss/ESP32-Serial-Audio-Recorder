#include <driver/i2s.h>

// Configurazione I2S
const i2s_port_t I2S_PORT = I2S_NUM_0;
const int BLOCK_SIZE = 128;
// Pin I2S (Modifica in base al tuo cablaggio)
const int I2S_WS = 5;
const int I2S_SD = 4;
const int I2S_SCK = 6;


void i2s_install() {
  // Configurazione I2S
  i2s_config_t i2s_config = {
    .mode = (i2s_mode_t)(I2S_MODE_MASTER | I2S_MODE_RX),
    .sample_rate = 24000, // 16kHz (Qualità sufficiente per voce)
    .bits_per_sample = I2S_BITS_PER_SAMPLE_16BIT,
    .channel_format = I2S_CHANNEL_FMT_ONLY_LEFT,
    .communication_format = I2S_COMM_FORMAT_I2S,
    .intr_alloc_flags = ESP_INTR_FLAG_LEVEL1,
    .dma_buf_count = 8,
    .dma_buf_len = BLOCK_SIZE,
    .use_apll = false,
    .tx_desc_auto_clear = false,
    .fixed_mclk = 0
  };

  i2s_driver_install(I2S_PORT, &i2s_config, 0, NULL);

 }

 void i2s_setpin() {

    i2s_pin_config_t pin_config = {
    .bck_io_num = I2S_SCK,
    .ws_io_num = I2S_WS,
    .data_out_num = I2S_PIN_NO_CHANGE,
    .data_in_num = I2S_SD
  };

  i2s_set_pin(I2S_PORT, &pin_config);
}


void setup() {
  // Usa una velocità seriale molto alta
  Serial.begin(921600); 
  delay(1000);

  // Set up I2S
  i2s_install();
  i2s_setpin();

}


void loop() {
  int16_t samples[BLOCK_SIZE];
  size_t bytes_read;

  // Leggi dall'I2S
  i2s_read(I2S_PORT, &samples, sizeof(samples), &bytes_read, portMAX_DELAY);

  // Invia i byte grezzi alla seriale
  // Nota: samples è int16_t, quindi sono già 2 byte per campione
  if (bytes_read > 0) {
    Serial.write((uint8_t*)samples, bytes_read);
  }
}