#ifndef COMMERCIAL_METER_H
#define COMMERCIAL_METER_H

#include "Meter.h"

class CommercialMeter : public Meter {
public:
    CommercialMeter(const std::string& id, int pulsesPerKWh);
};

#endif