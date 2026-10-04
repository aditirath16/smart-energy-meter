#ifndef SLIDING_WINDOW_H
#define SLIDING_WINDOW_H

#include <vector>

class SlidingWindow {
private:
    std::vector<double> values;
    int windowSize;

public:
    SlidingWindow(int size);

    void addValue(double value);

    double getWindowSum() const;

    double getWindowAverage() const;

    int getSize() const;
};

#endif