/*
 * uart.c
 *
 *  Created on: Aug 2, 2021
 *      Author: jonathancagua
 */

#include "miApp_uart.h"
#include "miApp_analogicos.h"
#include "miApp_enable.h"
#include "sapi.h"

char menu_option;
menu_t menu_shown = none;
bool_t bt_1 = false;
bool_t bt_2 = false;
bool_t bt_3 = false;
bool_t bt_4 = false;
#define clrscr() printf("\e[1;1H\e[2J")
delay_t myDelay;
void miApp_uart_init(){
	delayConfig( &myDelay, 500 );
}

void miApp_uart_menu(){
	clrscr();
	printf("            CARGADOR DE BATERIA \n\r");
	printf("------------------------------------------\n\r");
	printf("a. Configurador de Cargadores.\n\r");
	printf("b. Monitor de Baterias.\n\r");
	printf("c. Save and quit.\n\r");
	printf(" Please enter an option from the main menu: \n\r");
	menu_shown = menu1;
}

void miApp_uart_submenu(){
	clrscr();
	printf("            Configurador de Cargadores \n\r");
	printf("------------------------------------------\n\r");
	printf(" Estado del Cargador\n\r" );
	printf("1. Cargador 1: %s .\n\r", bt_1 ? "enable" : "disable" );
	printf("2. Cargador 2: %s .\n\r", bt_2 ? "enable" : "disable" );
	printf("3. Cargador 3: %s .\n\r", bt_3 ? "enable" : "disable" );
	printf("4. Cargador 4: %s .\n\r", bt_4 ? "enable" : "disable" );
	printf("5. Save and quit.\n\r");
	printf(" Please enter an option from the main menu: \n\r");
	menu_shown = menu2;
}

void miApp_uart_submenu2(){
	clrscr();
	uint16_t voltaje;

	printf("            Monitor de Baterias \n\r");
	printf("------------------------------------------\n\r");
	printf(" Estado del Cargador\n\r" );
	voltaje = miApp_bateria_read(bateria1);
	printf("1. V.Cargador 1: %d .\n\r", voltaje );
	voltaje = miApp_bateria_read(bateria2);
	printf("2. V.Cargador 2: %d .\n\r", voltaje);
	voltaje = miApp_bateria_read(bateria3);
	printf("3. V.Cargador 3: %d .\n\r", voltaje);
	voltaje = miApp_bateria_read(bateria4);
	printf("4. V.Cargador 4: %d .\n\r", voltaje);
	printf("5. Save and quit.\n\r");
	printf(" Please enter an option from the main menu: \n\r");
	menu_shown = menu3;
}

void miApp_uart_task(menu_t *opcion){

	switch((uint8_t)*opcion){
		case menu1:
			if(*opcion != menu_shown){
				miApp_uart_menu();
			}
			menu_option = getchar();
			if('a' == menu_option){
				*opcion = menu2;
			}
			if('b' == menu_option){
				*opcion = menu3;
			}
			break;
		case menu2:
			if(*opcion != menu_shown){
				miApp_uart_submenu();
			}
			scanf(" %c",&menu_option);
			if('1' == menu_option){
				menu_shown = none;
				bt_1 ^= 1;
				miApp_activador_set(activador1,bt_1);
			}
			else if('2' == menu_option ){
				menu_shown = none;
				bt_2 ^= 1;
				miApp_activador_set(activador2,bt_2);
			}
			else if('3' == menu_option){
				menu_shown = none;
				bt_3 ^= 1;
				miApp_activador_set(activador3,bt_3);
			}
			else if('4' == menu_option ){
				menu_shown = none;
				bt_4 ^= 1;
				miApp_activador_set(activador4,bt_4);
			}
			break;
		case menu3:
			if(*opcion != menu_shown || delayRead(&myDelay)){
				miApp_uart_submenu2();
			}

			break;

	}
}
