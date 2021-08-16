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
}baterias;
baterias adc_array[lastBateria];

static bool_t inicializado = false;
uint16_t miApp_bateria_read(bateria_t bateria){
	uint16_t value = 0;
	if(lastBateria > bateria){
		value = adcRead(adc_array[bateria].canal);
	}
	return(value);
}
bool_t miApp_bateria_add(adcMap_t canal , bateria_t bateria){
	bool_t resp = false;
	if(!adc_array[bateria].enable){
		adc_array[bateria].canal = canal;
		adc_array[bateria].enable = true;
		resp = true;
	}
	return resp;
}

bool_t miApp_bateria_init(){
	if(inicializado)
		return false;
	adcInit(ADC_ENABLE);
	memset(adc_array,0,sizeof(adc_array));
	inicializado = true;
	return false;
}
