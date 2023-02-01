#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
#include "board.h"
#include "pin_mux.h"
#include "fsl_common.h"
#include <cstdio>

#include "led.h"
#include "clock.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/

/*!
 * @brief Main function
 */
int main(void)
{

    /* Init board hardware. */
    BOARD_InitPins();
    BOARD_BootClockRUN();
    BOARD_InitDebugConsole();

    printf("Hello frdm fidget! \r\n");

    // On-board LEDs
    led red(RED_LED_PIN_IDX, PORTB);
    led green(GREEN_LED_PIN_IDX, PORTB);
    led blue(BLUE_LED_PIN_IDX, PORTD);

    // Clock
    clock sysClock;

    red.init();
    green.init();
    blue.init();

    // pit_init();
    sysClock.init();
    sysClock.start();

    while (1)
    {
        red.set(true);

        sysClock.wait_for(1000);

        red.set(false);

        sysClock.wait_for(1000);

        green.set(true);

        sysClock.wait_for(1000);

        green.set(false);

        sysClock.wait_for(1000);

        blue.set(true);

        sysClock.wait_for(1000);

        blue.set(false);

        sysClock.wait_for(1000);
    }
}
