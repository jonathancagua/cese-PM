
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


bool_t miApp_main_baterias_init();
bool_t miApp_main_activadores_init();

int main(void){
	bool_t resp = false;
	menu_t estado = menu1;
	SystemCoreClockUpdate();
	Board_Init();
	boardInit();
	/* Enable and setup SysTick Timer at a periodic rate */
	SysTick_Config(SystemCoreClock / TICKRATE_HZ);
	uartConfig( UART_USB, 115200 );
	miApp_uart_init();
	resp = miApp_bateria_init();
	resp &= miApp_activador_init();
	resp &= miApp_main_baterias_init();
	resp &= miApp_main_activadores_init();

	while(1){
		miApp_uart_task(&estado);
			//atenderError();
	}
}

bool_t miApp_main_baterias_init(){
	bool_t resp = miApp_bateria_add(CH1,bateria1);
	resp &= miApp_bateria_add(CH2,bateria2);
	resp &= miApp_bateria_add(CH3,bateria3);
	resp &= miApp_bateria_add(CH4,bateria4);
	return(resp);
}
bool_t miApp_main_activadores_init(){
	bool_t resp = miApp_activador_add(LEDR,activador1);
	resp &= miApp_activador_add(LEDG,activador2);
	resp &= miApp_activador_add(LED1,activador3);
	resp &= miApp_activador_add(LEDB,activador4);
	return(resp);
}


// No se implementa la atención del error, se deja colgado con el while(1)
void atenderError()
{
	while(1);
}





