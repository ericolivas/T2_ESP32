/* gpio.c */
#include "../_hal/gpio.h"
#include "driver/gpio.h"

void gpio_init() {
    gpio_set_direction(LED_PIN, GPIO_MODE_OUTPUT);
    gpio_set_direction(BUTTON_PIN, GPIO_MODE_INPUT);
    gpio_set_pull_mode(BUTTON_PIN, GPIO_PULLUP_ONLY); 
    gpio_set_direction(AUX_PIN, GPIO_MODE_INPUT);
    gpio_set_pull_mode(AUX_PIN, GPIO_PULLUP_ONLY);
}

void gpio_write(int pin, int value) {
    gpio_set_level(pin, value);
}

int gpio_read(int pin) {
    return gpio_get_level(pin);
}
