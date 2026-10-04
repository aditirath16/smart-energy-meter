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

        if (pulsesPerKWh <= 0) {
            pulsesPerKWh = 1000;
        }

        return std::make_unique<ResidentialMeter>(
            id,
            pulsesPerKWh
        );
    }

    if (type == "Commercial") {

        if (pulsesPerKWh <= 0) {
            pulsesPerKWh = 800;
        }

        return std::make_unique<CommercialMeter>(
            id,
            pulsesPerKWh
        );
    }

    if (type == "Industrial") {

        if (pulsesPerKWh <= 0) {
            pulsesPerKWh = 500;
        }

        return std::make_unique<IndustrialMeter>(
            id,
            pulsesPerKWh
        );
    }

    return nullptr;
}
