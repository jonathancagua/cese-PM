#ifndef _ANALOGICOS_H_
#define _ANALOGICOS_H_
#include <stdint.h>
#include <string.h>
#include "sapi.h"
#define CH4	3U
typedef enum{bateria1,bateria2,bateria3,bateria4,lastBateria} bateria_t;
uint16_t miApp_bateria_read(bateria_t bateria);
bool_t miApp_bateria_add(adcMap_t canal , bateria_t bateria);
bool_t miApp_bateria_init();
#endif
