/* uart.c */
#include "../_bsp/bsp.h"

#ifdef ESP32

#include "../_hal/uart.h"
#include "driver/uart.h"
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

void uart_init() {
    uart_config_t uart_config = {
        .baud_rate = 115200,
        .data_bits = UART_DATA_8_BITS,
        .parity = UART_PARITY_DISABLE,
        .stop_bits = UART_STOP_BITS_1,
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE
    };
    uart_param_config(UART_NUM_0, &uart_config);
    uart_driver_install(UART_NUM_0, 256, 0, 0, NULL, 0);
}

void uart_print(const char *fmt, ...) {
    char buffer[128];
    va_list args;
    va_start(args, fmt);
    vsnprintf(buffer, sizeof(buffer), fmt, args);
    va_end(args);
    uart_write_bytes(UART_NUM_0, buffer, strlen(buffer));
}

#endif

#ifdef MSP432

#include "uart.h"

/* Definición única del puntero de función para UART */
void (*uartSendCallback)(const char*) = 0;

void uartInit(void) {
    /* Si se requiere inicializar hardware UART, se puede hacer aquí.
       En este ejemplo, la inicialización se realiza en el main. */
}

void uartSend(const char* message) {
    if(uartSendCallback != 0) {
        uartSendCallback(message);
    }
}
#endif
