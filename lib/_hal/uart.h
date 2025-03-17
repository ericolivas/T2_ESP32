/* uart.h */
#ifndef UART_H
#define UART_H
#include "../_bsp/bsp.h"

#ifdef ESP32
void uart_init(void);
void uart_print(const char *fmt, ...);
#endif

#ifdef MSP432

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>

/**
 * @brief Puntero a función para enviar mensajes por UART.
 * 
 * Debe asignarse en el main (C++) a una función que envíe el mensaje por Serial.
 */
extern void (*uartSendCallback)(const char*);

/**
 * @brief Inicializa el módulo UART.
 *
 * La inicialización real (por ejemplo, Serial.begin) se realiza en el main.
 */
void uartInit(void);

/**
 * @brief Envía un mensaje por UART utilizando el callback.
 *
 * @param message Mensaje a enviar.
 */
void uartSend(const char* message);

#ifdef __cplusplus
}
#endif
#endif

#endif