#ifndef IO_DEFS
#define IO_DEFS

const int TOSC = 15;
const int DISARM = 8;
const int ARMED = 9;
const int VIBRATION_SENSOR_1 = 10;
const int VIBRATION_SENSOR_2 = 11;
const int VIBRATION_SENSOR_3 = 12;
const int SIREN = 13;


//Constants that depend on the platform

#ifdef X86_PLAT
const bool HIGH = true;
const bool LOW = false;

const int SECONDS = 1000000;
const int MILLISECONDS = 1000;
#else

#include <Arduino.h>

const long SECONDS = 1000000;
const long MILLISECONDS = 1000;

void initIO();

#endif // x86_PLAT




#endif //IO_DEFS
