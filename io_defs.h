#ifndef IO_DEFS
#define IO_DEFS

const int ARMED = 8; //Level
const int ZONE_GPIO_1 = 9;
const int ZONE_GPIO_2 = 10;
const int ZONE_GPIO_3 = 11;
const int ZONE_GPIO_4 = 12;
const int ZONE_LED_1 = 2;
const int ZONE_LED_2 = 3;
const int ZONE_LED_3 = 4;
const int ZONE_LED_4 = 5;

const int ZONE_1 = 0;
const int ZONE_2 = 1;
const int ZONE_3 = 2;
const int ZONE_4 = 3;
const int MAX_ZONES_COUNT = 4;

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
