#ifndef INDUSTRIAL_METER_H
#define INDUSTRIAL_METER_H

#include "Meter.h"

class IndustrialMeter : public Meter {
public:
    IndustrialMeter(const std::string& id, int pulsesPerKWh);
};

#endif