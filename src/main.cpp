#include <iostream>

#include "MeterFactory.h"
#include "Pulse.h"
#include "PulseCounter.h"
#include "EnergyAggregator.h"
#include "SlidingWindow.h"
#include "PeakDetector.h"
#include "Logger.h"

int main() {

    // Create a residential meter using the Factory
    auto meter = MeterFactory::createMeter(
        "Residential",
        "MTR001",
        1000
    );

    if (!meter) {
        std::cout << "Invalid meter type\n";
        return 1;
    }

    // Create processing modules
    PulseCounter counter;

    EnergyAggregator aggregator(
        meter->getPulsesPerKWh()
    );

    SlidingWindow window(3);

    PeakDetector detector(0.004);

    // Simulate 10 incoming meter pulses
    for (int i = 0; i < 10; i++) {

        Pulse pulse;

        counter.recordPulse(pulse);

        aggregator.addPulses(
            pulse.getValue()
        );

        double energy =
            aggregator.getEnergyKWh();

        window.addValue(energy);
    }

    // Calculate recent energy average
    double average =
        window.getWindowAverage();

    // Determine consumption status
    std::string status;

    if (detector.isPeak(average)) {
        status = "HIGH CONSUMPTION";
    }
    else {
        status = "NORMAL CONSUMPTION";
    }

    // Display results
    std::cout << "Smart Energy Meter System\n";
    std::cout << "--------------------------\n";

    std::cout << "Meter ID: "
              << meter->getMeterId()
              << "\n";

    std::cout << "Meter Type: "
              << meter->getMeterType()
              << "\n";

    std::cout << "Total Pulses: "
              << counter.getTotalPulses()
              << "\n";

    std::cout << "Total Energy: "
              << aggregator.getEnergyKWh()
              << " kWh\n";

    std::cout << "Window Size: "
              << window.getSize()
              << "\n";

    std::cout << "Window Average: "
              << average
              << " kWh\n";

    std::cout << "Status: "
              << status
              << "\n";

    // Save results to log
    Logger::log(
        "Meter MTR001 processed 10 pulses"
    );

    Logger::log(
        "Total energy: " +
        std::to_string(
            aggregator.getEnergyKWh()
        ) +
        " kWh"
    );

    Logger::log(
        "Status: " + status
    );

    return 0;
}