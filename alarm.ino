#include "io_defs.h"
#ifndef X86_PLAT
#include "ArduinoPlat.h"
ArduinoPlat plat;
#else
#include "x86/X86Platform.h"
X86Platform plat;
#endif // X86_PLAT 

#include "Armed.h"
#include "ASi.h"
#include "SimpleQueue.h"
#include "io_defs.h"


SimpleQueue SimpleQueue(128);
ASi asi(&plat, &SimpleQueue);
Fsm fsm;


void setup() {
  Serial.begin(115200);
  fsm.setState(Armed::Instance(&fsm, &asi));
  Serial.print("Alarm Start");
}

void loop() 
{
   fsm.run();
}
