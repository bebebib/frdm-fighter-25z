#include "MKL25Z4.h"

#define RED_LED_PIN_IDX   18
#define GREEN_LED_PIN_IDX 19
#define BLUE_LED_PIN_IDX 1

class led
{
    private:
        uint32_t led_pin;

        PORT_Type * port; 

        GPIO_Type * gpio;
    
    public:
        // Constructor  
        led(uint32_t _led_pin, PORT_Type * _port) : 
            led_pin(_led_pin),
            port(_port) {         
        }

        void init (void);

        void set (bool level);

        void toggle (void);

};