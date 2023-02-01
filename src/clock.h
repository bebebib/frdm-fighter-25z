#include "MKL25Z4.h"

#define TIC_DURATION 0.001

class clock
{
    private:
        uint32_t clock_freq;

        float clock_period;

        float timer_period = TIC_DURATION; // 1 ms

        uint32_t irq_cycles;

    public:
        // Constructor
        clock() = default;

        void init (void);

        void start (void);

        void wait_for (uint32_t ms);
};