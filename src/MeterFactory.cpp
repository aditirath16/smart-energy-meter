#include "MeterFactory.h"

#include "ResidentialMeter.h"
#include "IndustrialMeter.h"
#include "CommercialMeter.h"

std::unique_ptr<Meter> MeterFactory::createMeter(
    const std::string& type,
    const std::string& id,
    int pulsesPerKWh
) {

    if (type == "Residential") {
        return std::make_unique<ResidentialMeter>(
            id,
            pulsesPerKWh
        );
    }

    if (type == "Industrial") {
        return std::make_unique<IndustrialMeter>(
            id,
            pulsesPerKWh
        );
    }

    if (type == "Commercial") {
        return std::make_unique<CommercialMeter>(
            id,
            pulsesPerKWh
        );
    }

    return nullptr;
}