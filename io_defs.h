#ifndef IO_DEFS
#define IO_DEFS

const int TOSC = 15;
const int DISARM = 7;
const int ARMED = 10;
const int VIBRATION_SENSOR_1 = 11;
const int VIBRATION_SENSOR_2 = 10;
const int VIBRATION_SENSOR_3 = 12;
const int SIREN = 13;


//Constants that depend on the platform

#ifdef X86_PLAT
const bool HIGH = true;
const bool LOW = false;
#else

#include <Arduino.h>

void initIO();

#endif // x86_PLAT




#endif //IO_DEFS
