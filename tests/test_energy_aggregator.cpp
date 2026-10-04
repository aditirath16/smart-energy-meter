#include <iostream>

#include "EnergyAggregator.h"

int main() {

    EnergyAggregator aggregator(1000);

    aggregator.addPulses(1000);

    double energy = aggregator.getEnergyKWh();

    if (energy == 1.0) {
        std::cout << "Energy Aggregator Test: PASS\n";
    }
    else {
        std::cout << "Energy Aggregator Test: FAIL\n";
    }

    return 0;
}