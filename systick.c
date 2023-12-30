#include "systick.h"
#include "system_stm32f4xx.h"

volatile tick_t sys_tick_counter = 1;
volatile tick_t sys_tick_base    = 0;

// void SysTick_Handler()
// void HAL_IncTick()
// {
//     /* Increments tick counter */
//     sys_tick_counter += sys_tick_base;
// }

void initSystick(tick_t interval_us)
{
    assert (0 < interval_us);

    uint32_t freq_systick;

    /* Store interrupts interval and initialize counter */
    sys_tick_base    = interval_us;
    sys_tick_counter = 1;

    // /* Configures Systick intevals  */
    // freq_systick = 1000000UL / interval_us;
    // /* Set systick realod value to generate interrupt */
    // // if(SysTick_Config(SystemCoreClock/(freq_systick)))
    // if(HAL_SYSTICK_Config(SystemCoreClock/(freq_systick)))
    // {
    //     while(1)
    //     {

    //     }
    // }
}
