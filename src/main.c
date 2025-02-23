/* main.c */
#include "../_bsp/bsp.h"
#include "../_rtos/tasks.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void app_main() {
    bsp_init();
    xTaskCreate(task_button, "Button Task", 2048, NULL, 1, NULL);
    xTaskCreate(task_adc, "ADC Task", 2048, NULL, 1, NULL);
    //xTaskCreate(task_uart, "UART Task", 2048, NULL, 1, NULL);
}