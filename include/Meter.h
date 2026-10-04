#ifndef METER_H
#define METER_H

#include <string>

class Meter {
private:
    std::string meterId;
    std::string meterType;
    int pulsesPerKWh;

public:
    Meter(const std::string& id,
          const std::string& type,
          int pulsesPerKWh);

    std::string getMeterId() const;
    std::string getMeterType() const;
    int getPulsesPerKWh() const;
};

#endif