#ifndef METER_FACTORY_H
#define METER_FACTORY_H

#include <memory>
#include <string>

#include "Meter.h"

class MeterFactory {
public:
    static std::unique_ptr<Meter> createMeter(
        const std::string& type,
        const std::string& id,
        int pulsesPerKWh
    );
};

#endif