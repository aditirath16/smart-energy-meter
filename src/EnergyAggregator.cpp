#include "EnergyAggregator.h"

EnergyAggregator::EnergyAggregator(int pulsesPerKWh)
    : totalPulses(0),
      pulsesPerKWh(pulsesPerKWh) {
}

void EnergyAggregator::addPulses(int pulses) {
    totalPulses += pulses;
}

double EnergyAggregator::getEnergyKWh() const {
    return static_cast<double>(totalPulses) / pulsesPerKWh;
}

int EnergyAggregator::getTotalPulses() const {
    return totalPulses;
}