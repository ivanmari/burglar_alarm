#include "io_defs.h"
#ifndef X86_PLAT
#include "ArduinoPlat.h"
ArduinoPlat plat;
#else
#include "sim/X86Platform.h"
X86Platform plat;
#endif // X86_PLAT 

#include "Init.h"
#include "ASi.h"
#include "SimpleQueue.h"
#include "io_defs.h"


SimpleQueue SimpleQueue(128);
ASi asi(&plat, &SimpleQueue);
Fsm fsm;


void setup() {
#ifndef X86_PLAT
  Serial.begin(115200);
 #endif // X86_PLAT
  fsm.setState(Init::Instance(&fsm, &asi));
#ifndef X86_PLAT
  Serial.print("Alarm Start");
 #endif // X86_PLAT

}

void loop() 
{
   fsm.run();
}
