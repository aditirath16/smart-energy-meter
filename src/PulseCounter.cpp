#include "PulseCounter.h"

PulseCounter::PulseCounter()
    : totalPulses(0) {
}

void PulseCounter::recordPulse(const Pulse& pulse) {
    totalPulses += pulse.getValue();
}

int PulseCounter::getTotalPulses() const {
    return totalPulses;
}

void PulseCounter::reset() {
    totalPulses = 0;
}