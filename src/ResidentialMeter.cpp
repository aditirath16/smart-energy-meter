#include "ResidentialMeter.h"

ResidentialMeter::ResidentialMeter(
    const std::string& id,
    int pulsesPerKWh
)
    : Meter(id, "Residential", pulsesPerKWh) {
}