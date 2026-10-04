#include <iostream>

#include "Pulse.h"
#include "PulseCounter.h"

int main() {

    PulseCounter counter;

    Pulse pulse;

    counter.recordPulse(pulse);
    counter.recordPulse(pulse);
    counter.recordPulse(pulse);

    if (counter.getTotalPulses() == 3) {
        std::cout << "Pulse Counter Test: PASS\n";
    }
    else {
        std::cout << "Pulse Counter Test: FAIL\n";
    }

    return 0;
}