#include <iostream>

#include "PeakDetector.h"

int main() {

    PeakDetector detector(0.004);

    bool highValue = detector.isPeak(0.005);
    bool normalValue = detector.isPeak(0.002);

    if (highValue == true && normalValue == false) {
        std::cout << "Peak Detector Test: PASS\n";
    }
    else {
        std::cout << "Peak Detector Test: FAIL\n";
    }

    return 0;
}