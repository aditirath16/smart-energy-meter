#include "SlidingWindow.h"

SlidingWindow::SlidingWindow(int size)
    : windowSize(size) {
}

void SlidingWindow::addValue(double value) {

    values.push_back(value);

    if (values.size() > windowSize) {
        values.erase(values.begin());
    }
}

double SlidingWindow::getWindowSum() const {

    double sum = 0.0;

    for (double value : values) {
        sum += value;
    }

    return sum;
}

double SlidingWindow::getWindowAverage() const {

    if (values.empty()) {
        return 0.0;
    }

    return getWindowSum() / values.size();
}

int SlidingWindow::getSize() const {
    return values.size();
}