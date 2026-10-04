#ifndef VIRTUAL_METER_DRIVER_H
#define VIRTUAL_METER_DRIVER_H

#ifdef __cplusplus
extern "C" {
#endif

void meter_pulse_interrupt(void);
int get_pulse_count(void);
void reset_pulse_count(void);

#ifdef __cplusplus
}
#endif

#endif