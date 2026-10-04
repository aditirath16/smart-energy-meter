#ifndef PULSE_H
#define PULSE_H

class Pulse {
private:
    int pulseValue;

public:
    Pulse(int value = 1);

    int getValue() const;
};

#endif