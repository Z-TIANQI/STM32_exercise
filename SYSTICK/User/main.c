#include "stm32f10x.h"
#include "bsp_led.h"
#include "bsp_systick.h"

int main(void)
{
    // 
    LED_GPIO_Config();

    while(1)
    {
        GPIO_SetBits(LED_G_GPIO_PORT, LED_G_GPIO_PIN);
        Systick_Delay_ms(500);
        GPIO_ResetBits(LED_G_GPIO_PORT, LED_G_GPIO_PIN);
        Systick_Delay_ms(500);
    }
}

