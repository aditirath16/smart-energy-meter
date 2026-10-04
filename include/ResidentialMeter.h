#ifndef RESIDENTIAL_METER_H
#define RESIDENTIAL_METER_H

#include "Meter.h"

class ResidentialMeter : public Meter {
public:
    ResidentialMeter(const std::string& id, int pulsesPerKWh);
};

#endif