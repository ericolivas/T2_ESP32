/* gpio.h */
#ifndef GPIO_H
#define GPIO_H
#include "../_bsp/bsp.h"

#ifdef ESP32
#define LED_PIN 2
#define BUTTON_PIN 18
#define AUX_PIN1 21
#define AUX_PIN2 22
#define AUX_PIN3 23

void gpio_init(void);
void gpio_write(int pin, int value);
int gpio_read(int pin);
#endif

#ifdef MSP432

#ifdef __cplusplus
extern "C" {
#endif

#include <Energia.h>
#include <stdbool.h>

/**
 * @brief Modos de configuración para un pin GPIO.
 */
typedef enum {
    GPIO_INPUT,         // Entrada sin resistencia interna
    GPIO_INPUT_PULLUP,  // Entrada con resistencia pull-up interna
    GPIO_OUTPUT         // Salida digital
} gpio_pin_mode_t;

/**
 * @brief Configura el modo de un pin GPIO.
 * 
 * @param pin  Número del pin a configurar.
 * @param mode Modo en el que se configurará el pin:
 *             GPIO_INPUT, GPIO_INPUT_PULLUP o GPIO_OUTPUT.
 */
void gpioPinMode(uint8_t pin, gpio_pin_mode_t mode);

/**
 * @brief Escribe un valor digital en un pin GPIO.
 * 
 * @param pin   Número del pin en el que se escribe.
 * @param value true para establecer HIGH, false para LOW.
 */
void gpioDigitalWrite(uint8_t pin, bool value);

/**
 * @brief Lee el valor digital de un pin GPIO.
 * 
 * @param pin Número del pin a leer.
 * @return true si el valor leído es HIGH, false si es LOW.
 */
bool gpioDigitalRead(uint8_t pin);

#ifdef __cplusplus
}
#endif
#endif

#endif