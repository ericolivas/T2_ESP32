/* tasks.h */
#ifndef TASKS_H
#define TASKS_H
#include "../_bsp/bsp.h"

#ifdef ESP32
void task_button(void *pvParameters);
void task_adc(void *pvParameters);
#endif

#ifdef MPS432

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Puntero a función para imprimir mensajes.
 *
 * Se utiliza para imprimir mensajes desde las tareas en C puro.
 * Debe asignarse en el main (C++) a una función que use Serial.
 */
extern void (*printSerial)(const char*);

/* Prototipos de las funciones de tarea */
void tareaBoton(void);
void tareaConsola(void);

#ifdef __cplusplus
}
#endif
#endif

#endif