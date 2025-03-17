/* adc.c */
#include "../_bsp/bsp.h"

#ifdef ESP32
#include "../_hal/adc.h"
#include "driver/adc.h"

void adc_init() {
    adc1_config_width(ADC_WIDTH_BIT_12);
    adc1_config_channel_atten(ADC1_CHANNEL_6, ADC_ATTEN_DB_11);
    adc1_config_channel_atten(ADC1_CHANNEL_5, ADC_ATTEN_DB_11);
    adc1_config_channel_atten(ADC1_CHANNEL_4, ADC_ATTEN_DB_11);
}

int adc_read1() {
    return adc1_get_raw(ADC1_CHANNEL_6);
}

int adc_read2() {
    return adc1_get_raw(ADC1_CHANNEL_5);
}

int adc_read3() {
    return adc1_get_raw(ADC1_CHANNEL_4);
}

#endif

#ifdef MSP432
#include "adc.h"

int valorADC = 0;
bool adcActivo = false;

void inicializarADC(void) {
    // Configuramos el pin del ADC
    pinMode(PIN_ADC, INPUT);
    pinMode(AUX_PIN, INPUT_PULLUP); // Activa la resistencia pull-up interna


}

void tareaADC(void) {
    if (adcActivo) {
        valorADC = analogRead(PIN_ADC);
    }
}


#endif