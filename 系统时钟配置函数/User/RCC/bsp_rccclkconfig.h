#ifndef __BSP_RCCCLKCONFIG_H
#define __BSP_RCCCLKCONFIG_H

#include "stm32f10x.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_flash.h"

void HSE_SetSysClk(uint32_t RCC_PLLMul_x);
void MCO_GPIO_Config(void);

#endif /* __BSP_RCCCLKCONFIG_H */