#include "stm32f10x.h"
#include "bsp_led.h"
#include "bsp_dma_mtm.h"

extern const uint32_t aSRC_Const_Buffer[BUFFER_SIZE];
extern uint32_t aDST_Buffer[BUFFER_SIZE];

void Delay(__IO uint32_t nCount)	 //简单的延时函数
{
	for(; nCount != 0; nCount--);
}

int main(void)
{
    // 存放比较结果变量
    uint8_t status =  0;

    LED_YELLOW;
    Delay(0xffffff);

    // LED端口初始化
    LED_GPIO_Config();
    // DMA传输配置
    MtM_DMA_Config();

    // 等待 DMA 传输完成
    //while(DMA_GetFlagStatus(DMAx_FLAG_TCx) == RESET);

    // 比较源数据与传输后的数据
    status = Buffercmp(aSRC_Const_Buffer, aDST_Buffer, BUFFER_SIZE);
    
    if(status == 0)
    {
        LED_RED;
    }
    else
    {
        LED_GREEN;
    }
    

    while(1)
    {
    }
}

