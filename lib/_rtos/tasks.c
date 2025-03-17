/* tasks.c */
#include "../_bsp/bsp.h"

#ifdef ESP32

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
            if ((gpio_read(AUX_PIN1) != 0) && (gpio_read(AUX_PIN2) != 0) && (gpio_read(AUX_PIN3) != 0)){
                uart_print("No hay dispositivos conectados\n");
            }
            else{
                if (gpio_read(AUX_PIN1) == 0) {
                    int value = adc_read1();
                    uart_print("ADC Value 1: %d\n", value);
                    vTaskDelay(pdMS_TO_TICKS(5)); 
                }else {
                    uart_print("ADC Value 1: --\n");
                }
                if (gpio_read(AUX_PIN2) == 0) {
                    int value = adc_read2();
                    uart_print("ADC Value 2: %d\n", value);
                    vTaskDelay(pdMS_TO_TICKS(5)); 
                }else {
                    uart_print("ADC Value 2: --\n");
                }
                if (gpio_read(AUX_PIN3) == 0) {
                    int value = adc_read3();
                    uart_print("ADC Value 3: %d\n", value);
                    vTaskDelay(pdMS_TO_TICKS(5)); 
                }else {
                    uart_print("ADC Value 3: --\n");
                }
            }
            
        }
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}
#endif

#ifdef MSP432

#include "tasks.h"
#include "gpio.h"   // Para gpioDigitalRead()
#include "bsp.h"    // Para setColorRGB() y definiciones de pines
#include "adc.h"    // Para acceder a 'valorADC' y 'adcActivo'
#include <Energia.h>  // Para millis()
#include <stdio.h>    // Para snprintf()

/* Definición única del puntero para impresión */
void (*printSerial)(const char*) = 0;

/* Variables internas para el manejo de la tarea del botón */
static bool sistemaEncendido = false;
static bool estadoAnterior = true;  // Asumimos HIGH (true) como estado inicial (pull-up)
static unsigned long tiempoUltimoCambio = 0;
static const unsigned long tiempoRebote = 50;   // Tiempo de anti-rebote en ms
static int contadorPulsaciones = 0;

void tareaBoton(void) {
    bool estadoActual = gpioDigitalRead(PIN_BOTON);
    
    /* Detecta flanco descendente (de HIGH a LOW) y verifica el anti-rebote */
    if (!estadoActual && estadoAnterior && ((millis() - tiempoUltimoCambio) > tiempoRebote)) {
        contadorPulsaciones++;
        sistemaEncendido = (contadorPulsaciones % 2 != 0);  // Encendido en pulsaciones impares
        adcActivo = sistemaEncendido;                     // Activa o desactiva la lectura del ADC
        tiempoUltimoCambio = millis();
        
        if (printSerial != 0) {
            if (sistemaEncendido) {
                printSerial("Sistema ENCENDIDO");
            } else {
                printSerial("Sistema APAGADO");
            }
        }
        
        /* Controla el LED RGB: verde si encendido, apagado si no */
        if (sistemaEncendido) {
            setColorRGB(false, true, false);
        } else {
            setColorRGB(false, false, false);
        }
    }
    estadoAnterior = estadoActual;
}

void tareaConsola(void) {
    int estadoAUX = digitalRead(AUX_PIN); // Leer el estado del pin AUX
    
    if (adcActivo) {
        if (estadoAUX == HIGH) { // AUX_PIN conectado a GND, permite lectura del ADC
                printSerial("No Disponible");
            } else {
                char bufferADC[30];
                snprintf(bufferADC, sizeof(bufferADC), "Valor ADC: %d", valorADC);
                printSerial(bufferADC);
            }
        } 
    }
#endif