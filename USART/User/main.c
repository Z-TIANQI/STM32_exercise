#include "stm32f10x.h"
#include "bsp_led.h"
#include "bsp_usart.h"

void Delay(uint32_t count)
{
    for(; count != 0; count--);
}

int main(void)
{
    /*初始化USART 配置模式为 115200 8-N-1，中断接收*/
    USART_Config();
//    Usart_SendByte(DEBUG_USARTx, 100);
//    Usart_SendHalfWord(DEBUG_USARTx, 0xff56);

//    uint8_t a[10] = {1,2,3,4,5,6,7,8,9,10};
//    Usart_SendArray(DEBUG_USARTx, a, 10);

//    Usart_SendString( DEBUG_USARTx,"呼呼呼呼 \n");

    while(1)
    {
        // GPIO_SetBits(LED_G_GPIO_PORT, LED_G_GPIO_PIN);
        // Delay(0xFFFFF);
        // GPIO_ResetBits(LED_G_GPIO_PORT, LED_G_GPIO_PIN);
        // Delay(0xFFFFF);
    }


}

