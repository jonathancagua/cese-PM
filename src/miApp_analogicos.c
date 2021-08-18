/*
 * miApp_analogicos.c
 *
 *  Created on: Aug 11, 2021
 *      Author: jonathancagua
 */
#include "miApp_analogicos.h"

typedef struct __attribute__((__packed__))
{
	adcMap_t canal;
	bool_t enable;
}battery;

battery adc_array[lastBattery];

static bool_t inicializado = false;

uint16_t miApp_battery_read(battery_t battery){
	if(battery<battery1) return  0;
	uint16_t value = 0;
	if(lastBattery > battery){
		value = adcRead(adc_array[battery].canal);
		value = ((value * 3300)/1024);
	}
	return(value);
}

bool_t miApp_battery_add(adcMap_t canal , battery_t battery){
	bool_t resp = false;
	if(canal<CH1 || canal>CH4 || battery<battery1) return resp;
	if(lastBattery > battery && !adc_array[battery].enable){
		adc_array[battery].canal = canal;
		adc_array[battery].enable = true;
		resp = true;
	}
	return resp;
}

bool_t miApp_battery_init(){
	if(inicializado)
		return false;
	adcInit(ADC_ENABLE);
	memset(adc_array,0,sizeof(adc_array));
	inicializado = true;
	return true;
}
