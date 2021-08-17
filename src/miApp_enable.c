/*
 * miApp_enable.c
 *
 *  Created on: Aug 15, 2021
 *      Author: jonathancagua
 */

#include "miApp_enable.h"

typedef struct __attribute__((__packed__))
{
	gpioMap_t gpio;
	bool_t enable;
}activador;

activador act_array[lastActivador];

static bool_t inicializado = false;

bool_t miApp_activador_set(activador_t activador , bool_t value){
	if(lastActivador > activador){
		gpioWrite(act_array[activador].gpio,value);
	}
	return(true);
}

bool_t miApp_activador_add(gpioMap_t gpio , activador_t activador){
	bool_t resp = false;
	if(!act_array[activador].enable){
		act_array[activador].gpio = gpio;
		act_array[activador].enable = true;
		resp = true;
		gpioInit( gpio, GPIO_OUTPUT );
		gpioWrite( gpio, 0 );
	}
	return resp;
}

bool_t miApp_activador_init(){
	if(inicializado)
		return false;
	memset(act_array,0,sizeof(act_array));
	inicializado = true;
	return false;
}
