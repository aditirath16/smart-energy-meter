#include "virtual_meter_driver.h"

static int pulse_count = 0;

void meter_pulse_interrupt(void) {
    pulse_count++;
}

int get_pulse_count(void) {
    return pulse_count;
}

void reset_pulse_count(void) {
    pulse_count = 0;
}