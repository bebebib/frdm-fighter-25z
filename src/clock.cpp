#include "clock.h"
#include "fsl_clock.h"
#include "fsl_common.h"

extern "C" void PIT_IRQHandler(void);

static volatile uint32_t time = 0;

void clock::init (void)
{
    CLOCK_EnableClock(kCLOCK_Pit0);

    clock_freq = CLOCK_GetFreq(kCLOCK_BusClk);

    clock_period = 1 / static_cast<float>(clock_freq);

    // Function from kl25z reference manual
    irq_cycles = static_cast<uint32_t>(timer_period / clock_period - 1);

    (*PIT).MCR = PIT_MCR_MDIS(0);
    (*PIT).CHANNEL[0].LDVAL = PIT_LDVAL_TSV(irq_cycles);

    EnableIRQ(PIT_IRQn);
}

void clock::start (void)
{
    (*PIT).CHANNEL[0].TCTRL = PIT_TCTRL_TIE(1) | PIT_TCTRL_TEN(1);
}

void clock::wait_for(uint32_t ms)
{
    uint32_t temp_time = time + ms;
    while (time < temp_time)
    {}
}

void PIT_IRQHandler (void)
{
    // Clear interrupt
    (*PIT).CHANNEL[0].TFLG = 1;
    
    time++;
}