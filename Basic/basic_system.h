
#ifndef BSP_INC_BSP_SYSTEM_INIT_H_
#define BSP_INC_BSP_SYSTEM_INIT_H_

#include "stm32l4xx_hal.h"

/**
 * Init the system clock to 70MHz
 */
void basic_init_clock(void);

/**
 * Init GPIO to low power consumption.
 * Configure pins as
        * Analog
        * Input
        * Output
        * EVENT_OUT
        * EXTI
        * Free pins are configured automatically as Analog (this feature is enabled through
        * the Code Generation settings)
 */
void basic_init_gpio(void);


#endif /* BSP_INC_BSP_SYSTEM_INIT_H_ */
