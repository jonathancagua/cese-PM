#ifndef _ANALOGICOS_H_
#define _ANALOGICOS_H_
#include <stdint.h>
#include <string.h>
#include "sapi.h"
#define CH4	3U
/**
 * enum: bateria_t
 * Enum with the batteries ids.
 */
typedef enum{bateria1,bateria2,bateria3,bateria4,lastBateria} bateria_t;
/**
 * @brief Read a specific battery's ADC channel value.
 * 
 * @param bateria Value of the battery's instance that is going to be read.
 * @return uint16_t Value of the actual read or 0 if no value could be readed.
 */
uint16_t miApp_bateria_read(bateria_t bateria);
/**
 * @brief Add an ADC channel to an specific enabled battery's instance.
 * 
 * @param canal The channel that is going to be added.
 * @param bateria Value of the desired battery's instance.
 * @return bool_t False if no ADC channel was added. 
 */
bool_t miApp_bateria_add(adcMap_t canal , bateria_t bateria);
/**
 * @brief Initialize the battery's array instance and enable the ADC.
 * 
 * @return bool_t False if the battery's array instace was already initialize.
 */
bool_t miApp_bateria_init();
#endif
