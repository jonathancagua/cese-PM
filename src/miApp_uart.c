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

static char menu_option;
static menu_t menu_shown = none;
static bool_t bt_1 = false;
static bool_t bt_2 = false;
static bool_t bt_3 = false;
static bool_t bt_4 = false;
static delay_t myDelay;


/**
 * @brief Print of the main menu of battery charger.
 * 
 */
static void miApp_uart_menu();
/**
 * @brief Print of the charger's configuration menu.
 * 
 */
static void miApp_uart_submenu();
/**
 * @brief Print of the battery's monitoring menu.
 * 
 */
static void miApp_uart_submenu2();

static inline void clrscr(){
	printf("\e[1;1H\e[2J");
}

void miApp_uart_init(){
	delayConfig( &myDelay, 500 );
}

static void miApp_uart_menu(){
	clrscr();
	printf("            CARGADOR DE BATERIA \n\r");
	printf("------------------------------------------\n\r");
	printf("a. Configurador de Cargadores.\n\r");
	printf("b. Monitor de Baterias.\n\r");
	printf(" Please enter an option from the main menu: \n\r");
	menu_shown = menu1;
}

static void miApp_uart_submenu(){
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

static void miApp_uart_submenu2(){
	clrscr();
	uint16_t voltaje;

	printf("            Monitor de Baterias \n\r");
	printf("------------------------------------------\n\r");
	printf(" Estado del Cargador\n\r" );
	voltaje = miApp_battery_read(battery1);
	printf("V.Cargador 1: %d mV.\n\r", voltaje );
	voltaje = miApp_battery_read(battery2);
	printf("V.Cargador 2: %d mV.\n\r", voltaje);
	voltaje = miApp_battery_read(battery3);
	printf("V.Cargador 3: %d mV.\n\r", voltaje);
	voltaje = miApp_battery_read(battery4);
	printf("V.Cargador 4: %d mV.\n\r", voltaje);
	printf("1. Go Back.\n\r");
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
				miApp_activator_set(activator1,bt_1);
				bt_1 ^= 1;
			}
			else if('2' == menu_option ){
				menu_shown = none;
				miApp_activator_set(activator2,bt_2);
				bt_2 ^= 1;
			}
			else if('3' == menu_option){
				menu_shown = none;
				miApp_activator_set(activator3,bt_3);
				bt_3 ^= 1;
			}
			else if('4' == menu_option ){
				menu_shown = none;
				miApp_activator_set(activator4,bt_4);
				bt_4 ^= 1;
			}
			else if('5' == menu_option){
				*opcion = menu1;
			}
			break;
		case menu3:
			if(*opcion != menu_shown || delayRead(&myDelay)){
				miApp_uart_submenu2();
			}
			scanf(" %c",&menu_option);
			if('1' == menu_option){
				*opcion = menu1;
			}
			break;

	}
}
