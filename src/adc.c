/* adc.c */
#include "../_hal/adc.h"
#include "driver/adc.h"

void adc_init() {
    adc1_config_width(ADC_WIDTH_BIT_12);
    adc1_config_channel_atten(ADC1_CHANNEL_6, ADC_ATTEN_DB_11);
}

int adc_read() {
    return adc1_get_raw(ADC1_CHANNEL_6);
}