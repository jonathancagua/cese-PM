
#ifndef _ACTIVADOR_H_
#define _ACTIVADOR_H_
#include <stdint.h>
#include <string.h>
#include "sapi.h"
/**
 * enum: activador_t
 * Enum with activator's id.
 */
typedef enum{activador1,activador2,activador3,activador4,lastActivador} activador_t;
/**
 * @brief Write a gpio value state to the respective activator's gpio instance.
 * 
 * @param activador Value of the desired activator.
 * @param value Gpio value to be write.
 * @return bool_t True if the value was write successfully in the activator's gpio instance. 
 */
bool_t miApp_activador_set(activador_t activador , bool_t value);
/**
 * @brief Add a gpio value to an enabled activator's gpio instance.
 * 
 * @param gpio Value to be added in the activator's instance.
 * @param activador Value of the desired activator.
 * @return bool_t False if no gpio value was added to an activator's instance.
 */
bool_t miApp_activador_add(gpioMap_t gpio , activador_t activador);
/**
 * @brief Initialize an activator's array instance.
 * 
 * @return bool_t False if the activator's array instance it's already initialize. 
 */
bool_t miApp_activador_init();
#endif
