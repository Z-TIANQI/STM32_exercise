#include "stm32f10x.h"
#include "bsp_led.h"
#include "bsp_dma_mtp.h"

extern uint8_t SendBuff[SENDBUFF_SIZE];

void Delay(__IO uint32_t nCount)	 //简单的延时函数
{
	for(; nCount != 0; nCount--);
}

int main(void)
{
    uint16_t i = 0;
    // LED端口初始化
    LED_GPIO_Config();
    // 初始化USART
    USART_Config();
    // 配置使用DMA模式
    USARTx_DMA_Config();

    // 填充将要发送的数据
    for(i = 0; i < SENDBUFF_SIZE; i++)
    {
        SendBuff[i] = 'P';
    }

    // USART1 向 DMA 发出 TX 请求
    USART_DMACmd(DEBUG_USARTx, USART_DMAReq_Tx, ENABLE);

    while(1)
    {
    }
}

