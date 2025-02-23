/* bsp.c */
#include "../_bsp/bsp.h"
#include "../_hal/gpio.h"
#include "../_hal/adc.h"
#include "../_hal/uart.h"

void bsp_init(void) {
    gpio_init();
    adc_init();
    uart_init();
}