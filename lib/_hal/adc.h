/* adc.h */
#ifndef ADC_H
#define ADC_H
#include "../_bsp/bsp.h"

#ifdef ESP32
void adc_init(void);
int adc_read1(void);
int adc_read2(void);
int adc_read3(void);
#endif

#ifdef MSP432

#ifdef __cplusplus
extern "C" {
#endif

#include <Energia.h>

#define PIN_ADC A0
#define AUX_PIN 35 // P3.5 en el MSP432

// Variables globales del ADC
extern int valorADC;
extern bool adcActivo;

// Prototipos de funciones en C para el ADC
void inicializarADC(void);
void tareaADC(void);

#ifdef __cplusplus
}
#endif
#endif

#endif
