#ifndef IO_DEFS
#define IO_DEFS

const int TOSC = 15;
const int ARMED = 9;
const int PROGRAMMING_LED = 12;
const int DISARMED_LED = 11;
const int ARMED_LED = 10;
const int BUZZER = 13;


const int SIREN = 0;

const long SECONDS = 1000000;
const long MILLISECONDS = 1000;



//Constants that depend on the platform

#ifdef X86_PLAT
const bool HIGH = true;
const bool LOW = false;

const int SECONDS = 1000000;
const int MILLISECONDS = 1000;
#else

#include <Arduino.h>


void initIO();

#endif // x86_PLAT




#endif //IO_DEFS
