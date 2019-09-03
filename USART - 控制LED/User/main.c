#include "stm32f10x.h"
#include "bsp_led.h"
#include "bsp_usart.h"

int main(void)
{
    uint8_t ch;

    /*初始化USART 配置模式为 115200 8-N-1，中断接收*/
    USART_Config();
    LED_GPIO_Config();

    printf("这是一个串口控制RGB灯的程序");

    while(1)
    {
        ch = getchar();
        printf("ch = %c \n",ch);

        switch(ch)
        {
            case '1':LED_RED;
                break;
            default:LED_RGBOFF;
                break;
        }
    }
}

