#ifndef PEAK_DETECTOR_H
#define PEAK_DETECTOR_H

class PeakDetector {
private:
    double threshold;

public:
    PeakDetector(double threshold);

    bool isPeak(double value) const;

    double getThreshold() const;
};

#endif