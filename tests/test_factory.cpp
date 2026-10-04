#include <iostream>
#include <memory>

#include "MeterFactory.h"

int main() {

    auto meter = MeterFactory::createMeter(
        "Residential",
        "TEST001",
        1000
    );

    if (meter &&
        meter->getMeterType() == "Residential" &&
        meter->getMeterId() == "TEST001") {

        std::cout << "Factory Test: PASS\n";
    }
    else {
        std::cout << "Factory Test: FAIL\n";
    }

    return 0;
}