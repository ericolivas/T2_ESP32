/* tasks.c */
#include "../_rtos/tasks.h"
#include "../_hal/gpio.h"
#include "../_hal/adc.h"
#include "../_hal/uart.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

volatile int system_on = 0;

void task_button(void *pvParameters) {
    int last_state = 1;

    while (1) {
        int state = gpio_read(BUTTON_PIN);
        if (state == 0 && last_state == 1) {
            system_on = !system_on;
            gpio_write(LED_PIN, system_on);
            vTaskDelay(pdMS_TO_TICKS(50));
        }
        last_state = state;
        vTaskDelay(pdMS_TO_TICKS(10));
    }
}

void task_adc(void *pvParameters) {
    while (1) {
        if (system_on) {
            if (gpio_read(AUX_PIN) == 0) {
                int value = adc_read();
                uart_print("ADC Value: %d\n", value);
            } else {
                uart_print("No Disponible\n");
            }
        }
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}