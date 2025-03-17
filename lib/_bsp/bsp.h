/* bsp.h */
#ifndef BSP_H
#define BSP_H

#define ESP32
//#define MSP432

#ifdef ESP32
void bsp_init(void);
#endif

#ifdef MSP432

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <Energia.h>  // Se requiere para funciones de pines (pinMode, digitalWrite, etc.)

// Definiciones de pines para el BSP
#define PIN_BOTON    P1_1    // Botón con resistencia pull-up interna
#define PIN_LED_ROJO P2_0    // LED rojo
#define PIN_LED_VERDE P2_1   // LED verde
#define PIN_LED_AZUL P2_2    // LED azul

/**
 * @brief Inicializa el Board Support Package.
 *
 * Configura los pines de entrada/salida.
 */
void inicializarBSP(void);

/**
 * @brief Controla el estado del LED RGB.
 *
 * @param rojo  Estado del LED rojo: true para encender, false para apagar.
 * @param verde Estado del LED verde: true para encender, false para apagar.
 * @param azul  Estado del LED azul: true para encender, false para apagar.
 */
void setColorRGB(bool rojo, bool verde, bool azul);

#ifdef __cplusplus
}
#endif
#endif

#endif