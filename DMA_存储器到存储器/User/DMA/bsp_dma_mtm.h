#ifndef __BSP_DMA_MTM_H
#define __BSP_DMA_MTM_H

#define MtM_DMA_CLK        RCC_AHBPeriph_DMA1
#define MtM_DMA_CHANNEL    DMA1_Channel6
#define DMAx_FLAG_TCx      DMA1_FLAG_TC6
#define BUFFER_SIZE        32


#include "stm32f10x.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_dma.h"

void MtM_DMA_Config(void);
uint8_t Buffercmp(const uint32_t* pBuffer, uint32_t* pBuffer1, uint16_t BufferLength);

#endif // !__BSP_DMA_MTM_H
