#ifndef ENERGY_AGGREGATOR_H
#define ENERGY_AGGREGATOR_H

class EnergyAggregator {
private:
    int totalPulses;
    int pulsesPerKWh;

public:
    EnergyAggregator(int pulsesPerKWh);

    void addPulses(int pulses);

    double getEnergyKWh() const;

    int getTotalPulses() const;
};

#endif