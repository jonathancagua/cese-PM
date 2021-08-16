
#ifndef _ACTIVADOR_H_
#define _ACTIVADOR_H_
#include <stdint.h>
#include <string.h>
#include "sapi.h"
typedef enum{activador1,activador2,activador3,activador4,lastActivador} activador_t;
bool_t miApp_activador_set(activador_t activador , bool_t value);
bool_t miApp_activador_add(gpioMap_t gpio , activador_t activador);
bool_t miApp_activador_init();
#endif
