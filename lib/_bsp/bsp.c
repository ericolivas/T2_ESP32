/* bsp.c */
#include "../_bsp/bsp.h"

#ifdef ESP32

#include "../_hal/gpio.h"
#include "../_hal/adc.h"
#include "../_hal/uart.h"

void bsp_init(void) {
    gpio_init();
    adc_init();
    uart_init();
}
#endif

#ifdef MSP432
void inicializarBSP(void) {
    // Configuración del botón (entrada con pull-up)
    pinMode(PIN_BOTON, INPUT_PULLUP);
    
    // Configuración de los pines de los LEDs RGB como salidas
    pinMode(PIN_LED_ROJO, OUTPUT);
    pinMode(PIN_LED_VERDE, OUTPUT);
    pinMode(PIN_LED_AZUL, OUTPUT);
    
    // Apaga todos los LEDs al inicio
    setColorRGB(false, false, false);
    
    // NOTA: La inicialización del Serial se realiza en el archivo principal,
    // ya que en un módulo C puro no se puede usar el objeto Serial.
}

void setColorRGB(bool rojo, bool verde, bool azul) {
    digitalWrite(PIN_LED_ROJO, rojo ? HIGH : LOW);
    digitalWrite(PIN_LED_VERDE, verde ? HIGH : LOW);
    digitalWrite(PIN_LED_AZUL, azul ? HIGH : LOW);
}
#endif