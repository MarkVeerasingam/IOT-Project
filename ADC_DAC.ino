#include "driver/adc.h"
#include "driver/dac.h"

const adc1_channel_t adcChannel = ADC1_CHANNEL_0; // ADC channel to read from
const dac_channel_t dacChannel = DAC_CHANNEL_1; // DAC channel to write to

// Initialize volume control variable (range: 0-255)
int volume = 128;

void setup() {
  // Initialize ADC and DAC
  adc1_config_width(ADC_WIDTH_BIT_12);
  adc1_config_channel_atten(adcChannel, ADC_ATTEN_DB_11);
  dac_output_enable(dacChannel);
}

void loop() {
  // Read input audio signal on ADC0
  int val = adc1_get_raw(adcChannel);

  // Adjust volume
  val = val * volume / 255;

  // Output the audio signal on DAC0
  dac_output_voltage(dacChannel, val);
}
