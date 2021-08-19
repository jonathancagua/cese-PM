#ifndef _ANALOGICOS_H_
#define _ANALOGICOS_H_
#include <stdint.h>
#include <string.h>
#include "sapi.h"
#define CH4	3U
typedef struct __attribute__((__packed__))
{
	adcMap_t canal;
	bool_t enable;
}battery;

/**
 * enum: battery_t
 * Enum with the batteries ids.
 */
typedef enum{battery1,battery2,battery3,battery4,lastBattery} battery_t;
/**
 * @brief Read a specific battery's ADC channel value.
 * 
 * @param battery Value of the battery's instance that is going to be read.
 * @return uint16_t Value of the actual read or 0 if no value could be readed.
 */
uint16_t miApp_battery_read(battery_t battery);
/**
 * @brief Add an ADC channel to an specific enabled battery's instance.
 * 
 * @param canal The channel that is going to be added.
 * @param battery Value of the desired battery's instance.
 * @return bool_t False if no ADC channel was added. 
 */
bool_t miApp_battery_add(adcMap_t canal , battery_t battery);
/**
 * @brief Initialize the battery's array instance and enable the ADC.
 * 
 * @return bool_t False if the battery's array instace was already initialize.
 */
bool_t miApp_battery_init();
#endif
