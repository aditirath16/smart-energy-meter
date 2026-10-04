#include <iostream>

#include "SlidingWindow.h"

int main() {

    SlidingWindow window(3);

    window.addValue(1.0);
    window.addValue(2.0);
    window.addValue(3.0);

    double average = window.getWindowAverage();

    if (window.getSize() == 3 && average == 2.0) {
        std::cout << "Sliding Window Test: PASS\n";
    }
    else {
        std::cout << "Sliding Window Test: FAIL\n";
    }

    return 0;
}