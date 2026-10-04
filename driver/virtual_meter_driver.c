#include <stdio.h>

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

int main(void) {

    for (int i = 0; i < 10; i++) {
        meter_pulse_interrupt();
    }

    printf("Virtual Meter Driver\n");
    printf("--------------------\n");
    printf("Pulses received: %d\n", get_pulse_count());

    return 0;
}