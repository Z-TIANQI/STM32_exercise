#include "stm32f10x.h"
#include "bsp_led.h"
#include "bsp_usart.h"
#include "bsp_spi.h"
#include <string.h>


uint8_t readBuff[4096];
uint8_t writeBuff[4096];

int main(void)
{ 
	uint32_t id;
	uint16_t i;
	
  	LED_GPIO_Config();
  
  	LED_BLUE;
  	/* 串口初始化 */
	USART_Config();
	
	printf("\r\n 这是一个SPI-FLASH读写测试例程 \r\n");
	
	SPI_FLASH_Init();	 
 
  	id = SPI_Read_ID();

	printf("\r\n id =0x%x \r\n",id);
	
	SPI_Erase_Sector(0);
	
	for(i=0;i<25;i++)
	{
		writeBuff[i]=i+25;
	}
	
	SPI_Write_Data(0,writeBuff,25);
	
	SPI_Read_Data(0,readBuff,4096);
	
	for(i=0;i<4096;i++)
	{
		printf("0x%x ",readBuff[i]);
		if(i%10 == 0)
			printf("\r\n");
	}
	
  	while (1)
  	{      
  	}
}

