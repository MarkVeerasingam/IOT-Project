#include "driver/adc.h"
#include "driver/dac.h"

#define BUFFER_SIZE 1024  // size of the circular buffer
#define DELAY_TIME 50  // delay time in milliseconds

// circular buffer to store the samples of the audio signal
int16_t buffer[BUFFER_SIZE];

// index of the next sample to be written to the buffer
int16_t bufferWriteIndex = 0;

// index of the next sample to be read from the buffer
int16_t bufferReadIndex = 0;

void setup() {
  // Initialize ADC and DAC
  adc1_config_width(ADC_WIDTH_BIT_12);
  adc1_config_channel_atten(ADC1_CHANNEL_0, ADC_ATTEN_DB_11);
  dac_output_enable(DAC_CHANNEL_1);
}

void loop() {
  // Read input audio signal on ADC0
  int16_t val = adc1_get_raw(ADC1_CHANNEL_0);

  // Add the sample to the circular buffer
  buffer[bufferWriteIndex] = val;
  bufferWriteIndex = (bufferWriteIndex + 1) % BUFFER_SIZE;

  // Read the delayed sample from the circular buffer
  int16_t delayedVal = buffer[bufferReadIndex];
  bufferReadIndex = (bufferReadIndex + 1) % BUFFER_SIZE;

  // Output the audio signal with a delay on DAC0
  dac_output_voltage(DAC_CHANNEL_1, delayedVal);
}
