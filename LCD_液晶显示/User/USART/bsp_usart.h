#ifndef __USART_H
#define	__USART_H


#include "stm32f10x.h"
#include "stm32f10x_usart.h"
#include "stm32f10x_gpio.h"
#include <stdio.h>

/** 
  * 串口宏定义，不同的串口挂载的总线和IO不一样，移植时需要修改这几个宏
	* 1-修改总线时钟的宏，uart1挂载到apb2总线，其他uart挂载到apb1总线
	* 2-修改GPIO的宏
  */
	
// 串口1-USART1
#define  USARTx                   USART1
#define  USART_CLK                RCC_APB2Periph_USART1
#define  USART_APBxClkCmd         RCC_APB2PeriphClockCmd
#define  USART_BAUDRATE           115200

// USART GPIO 引脚宏定义
#define  USART_GPIO_CLK           (RCC_APB2Periph_GPIOA)
#define  USART_GPIO_APBxClkCmd    RCC_APB2PeriphClockCmd
    
#define  USART_TX_GPIO_PORT       GPIOA   
#define  USART_TX_GPIO_PIN        GPIO_Pin_9
#define  USART_RX_GPIO_PORT       GPIOA
#define  USART_RX_GPIO_PIN        GPIO_Pin_10

#define  USART_IRQ                USART1_IRQn
#define  USART_IRQHandler         USART1_IRQHandler

void USART_Config(void);
void Usart_SendByte( USART_TypeDef * pUSARTx, uint8_t ch);
void Usart_SendString( USART_TypeDef * pUSARTx, char *str);
void Usart_SendHalfWord( USART_TypeDef * pUSARTx, uint16_t ch);

#endif /* __USART_H */
