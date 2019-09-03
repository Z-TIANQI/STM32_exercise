#include "bsp_systick.h"

#if 0
static __INLINE uint32_t SysTick_Config(uint32_t ticks)
{ 
  // 判断 ticks 的值是否大于 2^24 ,大于则不符合规则。
  if (ticks > SysTick_LOAD_RELOAD_Msk)  return (1);           

  // 初始化 reload 寄存器的值。                                          
  SysTick->LOAD  = (ticks & SysTick_LOAD_RELOAD_Msk) - 1;      

  // 配置中断优先级，为15，默认为最低优先级。
  NVIC_SetPriority (SysTick_IRQn, (1<<__NVIC_PRIO_BITS) - 1);  

  // 初始化 counter 值为0
  SysTick->VAL   = 0;

  // 配置 systick 的时钟为 72M
  // 配置中断，Msk为1
  // 配置 systick
  SysTick->CTRL  = SysTick_CTRL_CLKSOURCE_Msk |   // 时钟源选择位， 0=AHB/8， 1=处理器时钟 AHB
                   SysTick_CTRL_TICKINT_Msk   |   // 1=SysTick 倒数计数到 0 时产生 SysTick 异常请求， 0=数到 0 时 无动作。
                   SysTick_CTRL_ENABLE_Msk;       // SysTick 定时器的使能位
  return (0);                                                  
}
#endif

void Systick_Delay_us(uint32_t us)
{
    uint32_t i;
    SysTick_Config(72);

    for(i = 0; i <= us; i++)
    {
				// systick 的 counter 从 reload 值往下递减到 0 的时候， CTRL 寄存器的位 16:countflag 会置 1，且读取该位的值可清 0
        while(!((SysTick->CTRL) & (1<<16)));
    }
		
		// 关闭定时器，SysTick->CTRL 清零
    SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;

}

void Systick_Delay_ms(uint32_t ms)
{
    uint32_t i;
    SysTick_Config(72000);

    for(i = 0; i <= ms; i++)
    {
        while(!((SysTick->CTRL) & (1<<16)));
    }

    SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;

}