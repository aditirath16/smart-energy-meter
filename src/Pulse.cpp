#include "Pulse.h"

Pulse::Pulse(int value)
    : pulseValue(value) {
}

int Pulse::getValue() const {
    return pulseValue;
}