#include "bsp_led.h"

int LED_GPIO_Config(void)
{
  	GPIO_InitTypeDef GPIO_InitStruct;

  	RCC_APB2PeriphClockCmd(LED_G_GPIO_CLK, ENABLE); // 设置时钟

  	GPIO_InitStruct.GPIO_Pin = LED_G_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(LED_G_GPIO_PORT, &GPIO_InitStruct);     // 初始化GPIO


    
}