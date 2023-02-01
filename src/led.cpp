#include "led.h"
#include "fsl_clock.h"
#include "fsl_port.h"
#include "fsl_gpio.h"
#include "board.h"

void  led::init (void)
{
    switch (reinterpret_cast<uint32_t>(port))
    {
        case PORTA_BASE:
            CLOCK_EnableClock(kCLOCK_PortA); 
            gpio = GPIOA;
            break;
        case PORTB_BASE:
            CLOCK_EnableClock(kCLOCK_PortB); 
            gpio = GPIOB;
            break;
        case PORTC_BASE:
            CLOCK_EnableClock(kCLOCK_PortC); 
            gpio = GPIOC;
            break;
        case PORTD_BASE:
            CLOCK_EnableClock(kCLOCK_PortD); 
            gpio = GPIOD;
            break;
        default:
            break;
    }

    PORT_SetPinMux(port, led_pin, kPORT_MuxAsGpio);

    GPIO_WritePinOutput(gpio, led_pin, LOGIC_LED_OFF);
    gpio->PDDR |= (1U << led_pin);
}

void led::toggle()
{
    GPIO_TogglePinsOutput(gpio, 1U << led_pin);
}

void led::set(bool level)
{
    if (level)
    {
        GPIO_ClearPinsOutput(gpio, 1U << led_pin);
    }
    else
    {
        GPIO_SetPinsOutput(gpio, 1U << led_pin);
    }
}