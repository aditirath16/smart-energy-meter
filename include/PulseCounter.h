#ifndef PULSE_COUNTER_H
#define PULSE_COUNTER_H

#include "Pulse.h"

class PulseCounter {
private:
    int totalPulses;

public:
    PulseCounter();

    void recordPulse(const Pulse& pulse);

    int getTotalPulses() const;

    void reset();
};

#endif