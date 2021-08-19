
#include "miApp_uart.h"
#include "miApp_analogicos.h"
#include "miApp_enable.h"
#include "sapi.h"
#include "main.h"

/*****************************************************************************
 * Private types/enumerations/variables
 ****************************************************************************/

#define TICKRATE_HZ (1000)	/* 1000 ticks per second */

/*****************************************************************************
 * Public types/enumerations/variables
 ****************************************************************************/

/*****************************************************************************
 * Private functions
 ****************************************************************************/

/*****************************************************************************
 * Public functions
 ****************************************************************************/


bool_t miApp_main_batteries_init();
bool_t miApp_main_activators_init();

int main(void){
	bool_t resp = false;
	menu_t estado = menu1;
	SystemCoreClockUpdate();
	Board_Init();
	boardInit();
	/* Enable and setup SysTick Timer at a periodic rate */
	SysTick_Config(SystemCoreClock / TICKRATE_HZ);

	miApp_uart_init();
	resp = miApp_battery_init();
	resp &= miApp_activator_init();
	resp &= miApp_main_batteries_init();
	resp &= miApp_main_activators_init();

	while(resp){
		miApp_uart_task(&estado);
			//atenderError();
	}
	atenderError();
}

bool_t miApp_main_batteries_init(){
	bool_t resp = miApp_battery_add(CH1,battery1);
	resp &= miApp_battery_add(CH2,battery2);
	resp &= miApp_battery_add(CH3,battery3);
	resp &= miApp_battery_add(CH4,battery4);
	return(resp);
}
bool_t miApp_main_activators_init(){
	bool_t resp = miApp_activator_add(LEDR,activator1);
	resp &= miApp_activator_add(LEDG,activator2);
	resp &= miApp_activator_add(LED1,activator3);
	resp &= miApp_activator_add(LEDB,activator4);
	return(resp);
}


// No se implementa la atención del error, se deja colgado con el while(1)
void atenderError()
{
	while(1);
}





