#include "IndustrialMeter.h"

IndustrialMeter::IndustrialMeter(
    const std::string& id,
    int pulsesPerKWh
)
    : Meter(id, "Industrial", pulsesPerKWh) {
}