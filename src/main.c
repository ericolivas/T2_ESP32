/* main.c */
#include "../_bsp/bsp.h"


#ifdef ESP32

#include "../_rtos/tasks.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void app_main() {
    bsp_init();
    xTaskCreate(task_button, "Button Task", 2048, NULL, 1, NULL);
    xTaskCreate(task_adc, "ADC Task", 2048, NULL, 1, NULL);
}
#endif

#ifdef MSP432

#include "Energia.h"
#include "TaskScheduler.h"
#include "bsp.h"    // Inicialización y control de hardware (pines, LEDs)
#include "adc.h"    // Funciones y variables del ADC
#include "gpio.h"   // Funciones para manejo de GPIO
#include "tasks.h"  // Funciones de tareas (tareaBoton y tareaConsola)
#include "uart.h"   // Módulo UART con callback

// Declaraciones de funciones
void setup();
void loop();
void serialSend(const char* mensaje);

// Definición de tareas del Scheduler
Task tareaBotonTask(100, TASK_FOREVER, &tareaBoton);
Task tareaADCTask(500, TASK_FOREVER, &tareaADC);
Task tareaConsolaTask(1000, TASK_FOREVER, &tareaConsola);
Scheduler scheduler;

/* Función de impresión para Serial */
void serialSend(const char* mensaje) {
    Serial.println(mensaje);
}

void setup() {
    /* Inicializa el BSP, ADC y UART */
    inicializarBSP();
    inicializarADC();
    uartInit();
    
    /* Inicializa la comunicación Serial */
    Serial.begin(9600);
    Serial.println("Sistema inicializado");
    
    /* Asigna los callbacks para impresión */
    printSerial = serialSend;       // Para las tareas en C puro
    uartSendCallback = serialSend;  // Para el módulo UART
    
    /* Configuración y activación del Scheduler */
    scheduler.init();
    scheduler.addTask(tareaBotonTask);
    scheduler.addTask(tareaADCTask);
    scheduler.addTask(tareaConsolaTask);
    tareaBotonTask.enable();
    tareaADCTask.enable();
    tareaConsolaTask.enable();
}

void loop() {
    scheduler.execute();
}
#endif