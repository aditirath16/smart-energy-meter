#include "Meter.h"

Meter::Meter(const std::string& id,
             const std::string& type,
             int pulsesPerKWh)
    : meterId(id),
      meterType(type),
      pulsesPerKWh(pulsesPerKWh) {
}

std::string Meter::getMeterId() const {
    return meterId;
}

std::string Meter::getMeterType() const {
    return meterType;
}

int Meter::getPulsesPerKWh() const {
    return pulsesPerKWh;
}