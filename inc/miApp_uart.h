#ifndef _UART_H_
#define _UART_H_
/**
 * enum: menu_t 
 * Enum with the menus ids.
 */
typedef enum{menu1,menu2, menu3,none} menu_t;
/**
 * @brief Delay rate of menu's refresh.
 * 
 */
void miApp_uart_init();
/**
 * @brief Task that navigates around the available menues.
 * 
 * @param opcion Initial menu to be set.
 */
void miApp_uart_task(menu_t *opcion);
#endif
