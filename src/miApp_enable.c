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
}activator;

activator act_array[lastActivator];

static bool_t inicializado = false;

bool_t miApp_activator_set(activator_t activator , bool_t value){
	bool_t resp = false;
	if(lastActivator<activator1) return resp;
	if(lastActivator > activator){
		gpioWrite(act_array[activator].gpio,value);
		resp = true;
	}
	return resp;
}

bool_t miApp_activator_add(gpioMap_t gpio , activator_t activator){
	bool_t resp = false;
	if(gpio>LED3 || gpio<LEDR || activator<activator1){
		return resp;
	}
	if( lastActivator > activator && !act_array[activator].enable){
		act_array[activator].gpio = gpio;
		act_array[activator].enable = true;
		resp = true;
		gpioInit( gpio, GPIO_OUTPUT );
		gpioWrite( gpio, 0 );
	}
	return resp;
}

bool_t miApp_activator_init(){
	if(inicializado)
		return false;
	memset(act_array,0,sizeof(act_array));
	inicializado = true;
	return true;
}
