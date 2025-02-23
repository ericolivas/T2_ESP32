/* gpio.h */
#ifndef GPIO_H
#define GPIO_H

#define LED_PIN 16
#define BUTTON_PIN 18
#define AUX_PIN 4

void gpio_init(void);
void gpio_write(int pin, int value);
int gpio_read(int pin);

#endif