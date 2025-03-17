/* gpio.c */
#include "../_bsp/bsp.h"

#ifdef ESP32

#include "../_hal/gpio.h"
#include "driver/gpio.h"

void gpio_init() {
    gpio_set_direction(LED_PIN, GPIO_MODE_OUTPUT);
    gpio_set_direction(BUTTON_PIN, GPIO_MODE_INPUT);
    gpio_set_pull_mode(BUTTON_PIN, GPIO_PULLUP_ONLY); 
    gpio_set_direction(AUX_PIN1, GPIO_MODE_INPUT);
    gpio_set_pull_mode(AUX_PIN1, GPIO_PULLUP_ONLY);
    gpio_set_direction(AUX_PIN2, GPIO_MODE_INPUT);
    gpio_set_pull_mode(AUX_PIN2, GPIO_PULLUP_ONLY);
    gpio_set_direction(AUX_PIN3, GPIO_MODE_INPUT);
    gpio_set_pull_mode(AUX_PIN3, GPIO_PULLUP_ONLY);
}

void gpio_write(int pin, int value) {
    gpio_set_level(pin, value);
}

int gpio_read(int pin) {
    return gpio_get_level(pin);
}
#endif

#ifdef MSP432
#include "gpio.h"

/**
 * @brief Configura el modo de un pin GPIO usando las funciones de Energia.
 */
void gpioPinMode(uint8_t pin, gpio_pin_mode_t mode) {
    switch (mode) {
        case GPIO_INPUT:
            pinMode(pin, INPUT);
            break;
        case GPIO_INPUT_PULLUP:
            pinMode(pin, INPUT_PULLUP);
            break;
        case GPIO_OUTPUT:
            pinMode(pin, OUTPUT);
            break;
        default:
            // En caso de un modo no reconocido, se configura como entrada por defecto.
            pinMode(pin, INPUT);
            break;
    }
}

/**
 * @brief Escribe un valor digital en un pin GPIO.
 */
void gpioDigitalWrite(uint8_t pin, bool value) {
    digitalWrite(pin, value ? HIGH : LOW);
}

/**
 * @brief Lee el valor digital de un pin GPIO.
 */
bool gpioDigitalRead(uint8_t pin) {
    return (digitalRead(pin) == HIGH);
}

#endif