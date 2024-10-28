#ifndef IO_DEFS
#define IO_DEFS

const int TOSC = 15;

#ifdef X86_PLAT

const int ARMED = 8;
const int VIBRATION_SENSOR_1 = 9;
const int VIBRATION_SENSOR_2 = 10;
const int VIBRATION_SENSOR_3 = 11;
const int SIREN = 12;

const bool HIGH = true;
const bool LOW = false;

#else

#include <Arduino.h>

const int DISARM = 7;
const int ARMED = 8;
const int VIBRATION_SENSOR_1 = 9;
const int VIBRATION_SENSOR_2 = 10;
const int VIBRATION_SENSOR_3 = 11;
const int SIREN = 13;

void initIO();

#endif // x86_PLAT


#endif //IO_DEFS
