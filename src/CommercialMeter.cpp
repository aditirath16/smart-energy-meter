#include "CommercialMeter.h"

CommercialMeter::CommercialMeter(
    const std::string& id,
    int pulsesPerKWh
)
    : Meter(id, "Commercial", pulsesPerKWh) {
}