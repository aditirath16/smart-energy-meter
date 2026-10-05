#include <iostream>
#include <string>

#include "MeterFactory.h"
#include "Pulse.h"
#include "PulseCounter.h"
#include "EnergyAggregator.h"
#include "SlidingWindow.h"
#include "PeakDetector.h"
#include "Logger.h"

extern "C" {
#include "../driver/virtual_meter_driver.h"
}

int main() {
    const int WINDOW_SIZE = 3;

    auto meter = MeterFactory::createMeter("Residential", "MTR001", 0);
    if (!meter) {
        std::cout << "Invalid meter type\n";
        return 1;
    }

    PulseCounter counter;
    EnergyAggregator aggregator(meter->getPulsesPerKWh());
    SlidingWindow window(WINDOW_SIZE);
    PeakDetector detector(0.004);

    // ---------- Scenario 1: normal (1 pulse per interval) ----------
    reset_pulse_count();

    for (int i = 0; i < 10; i++) {
        meter_pulse_interrupt();
        int driverPulseCount = get_pulse_count();

        while (driverPulseCount > counter.getTotalPulses()) {
            Pulse pulse;
            counter.recordPulse(pulse);
            aggregator.addPulses(pulse.getValue());

            double intervalEnergy =
                static_cast<double>(pulse.getValue()) / meter->getPulsesPerKWh();
            window.addValue(intervalEnergy);

            driverPulseCount = get_pulse_count();
        }
    }

    int normalDriverPulses = get_pulse_count();
    int normalTotalPulses = counter.getTotalPulses();
    double normalAverage = window.getWindowAverage();
    std::string normalStatus =
        detector.isPeak(normalAverage) ? "HIGH CONSUMPTION" : "NORMAL CONSUMPTION";

    // ---------- Scenario 2: high (varied pulses per interval) ----------
    reset_pulse_count();
    SlidingWindow highWindow(WINDOW_SIZE);
    int pulseIntervals[] = {1, 1, 2, 6, 5};

    for (int interval : pulseIntervals) {
        for (int i = 0; i < interval; i++) {
            meter_pulse_interrupt();
        }
        double intervalEnergy =
            static_cast<double>(interval) / meter->getPulsesPerKWh();
        highWindow.addValue(intervalEnergy);
    }

    int highDriverPulses = get_pulse_count();
    double highAverage = highWindow.getWindowAverage();
    std::string highStatus =
        detector.isPeak(highAverage) ? "HIGH CONSUMPTION" : "NORMAL CONSUMPTION";

    // ---------- Output ----------
    std::cout << "Smart Energy Meter System\n";
    std::cout << "--------------------------\n";
    std::cout << "Meter ID: " << meter->getMeterId() << "\n";
    std::cout << "Meter Type: " << meter->getMeterType() << "\n";
    std::cout << "Peak Threshold: " << detector.getThreshold() << " kWh\n";

    std::cout << "\n[Normal Consumption Test]\n";
    std::cout << "Driver Pulses: " << normalDriverPulses << "\n";
    std::cout << "Total Pulses: " << normalTotalPulses << "\n";
    std::cout << "Total Energy: " << aggregator.getEnergyKWh() << " kWh\n";
    std::cout << "Window Size: " << WINDOW_SIZE << "\n";
    std::cout << "Window Average: " << normalAverage << " kWh\n";
    std::cout << "Status: " << normalStatus << "\n";

    std::cout << "\n[High Consumption Test]\n";
    std::cout << "Pulse intervals: 1, 1, 2, 6, 5\n";
    std::cout << "Driver Pulses: " << highDriverPulses << "\n";
    std::cout << "Window Size: " << WINDOW_SIZE << "\n";
    std::cout << "Window Average: " << highAverage << " kWh\n";
    std::cout << "Status: " << highStatus << "\n";

    Logger::log("Normal test: " + normalStatus);
    Logger::log("High test average: " + std::to_string(highAverage) + " kWh");
    Logger::log("High test: " + highStatus);

    return 0;
}
