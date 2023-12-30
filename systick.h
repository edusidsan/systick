#ifndef _SYSTICK_H_
#define _SYSTICK_H_

#include <stdint.h>
#include <stdbool.h>
#include <assert.h>
#include "stm32f4xx_hal.h"


/*  Time constants  */
// #define MICROSECS   (1)
#define MILISECS    (1)
#define SECONDS     (1000 * MILISECS)
#define MINUTES     (60 * SECONDS)
#define HOURS       (60 * MINUTES)

/*  Default tick type */
typedef uint32_t tick_t;

/* Initialize systick with a microsecs base time    */
void initSystick(tick_t interval_us);

extern volatile tick_t sys_tick_counter; /* NEVER access this variable directly */

/* Inline aux functions */

/*  Get actual time of system in microsecs */
static inline tick_t getSystick(void)
{
    return (tick_t)HAL_GetTick();
}

/*  Returns interval, in microsecs, between now and some time in past */
static inline tick_t getSystickInterval(tick_t initial_tick)
{
    return (getSystick() - initial_tick);
}

/*  Returns true if interval has been completed */
static inline tick_t isSystickPassed(tick_t waiting_time, tick_t initial_tick)
{
    return (getSystickInterval(initial_tick) >= waiting_time);
}


/*  MACRO to run a 'stat' function periodically */
#define RUN_EVERY(period, stat) do{static tick_t t = 0; if(isSystickPassed(period,t)){t+=period;stat;}}while(0);
#endif
