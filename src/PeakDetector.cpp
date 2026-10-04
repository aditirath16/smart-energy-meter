#include "PeakDetector.h"

PeakDetector::PeakDetector(double threshold)
    : threshold(threshold) {
}

bool PeakDetector::isPeak(double value) const {
    return value > threshold;
}

double PeakDetector::getThreshold() const {
    return threshold;
}