#include "io_defs.h"
#ifndef X86_PLAT
#include "ArduinoPlat.h"
ArduinoPlat plat;
#else
#include "sim/X86Platform.h"
X86Platform plat;
#endif // X86_PLAT 

#include "Init.h"
#include "AlarmedZonesCleared.h"
#include "ASi.h"
#include "SimpleQueue.h"
#include "io_defs.h"
#include "Ipc.h"

SimpleQueue SimpleQueue(128);
ASi asi(&plat, &SimpleQueue);
Fsm fsm_core;
Fsm fsm_ui;
Ipc ipc;


void setup() {
#ifndef X86_PLAT
  Serial.begin(115200);
 #endif // X86_PLAT
  fsm_core.setState(Init::Instance(&fsm_core, &asi, &ipc));
  fsm_ui.setState(AlarmedZonesCleared::Instance(&fsm_ui, &asi, &ipc));
#ifndef X86_PLAT
  Serial.print("Alarm Start");
 #endif // X86_PLAT

}

void loop() 
{
   fsm_core.run();
   fsm_ui.run();
}
