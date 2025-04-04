#include "Zone.h"

#ifdef X86_PLAT
#include "sim/EEPROM.h"
#else
#include <EEPROM.h>
#endif


Zone::Zone(Switch zone_sw, Led zone_led, int zone_id):m_zone_sw(zone_sw), m_zone_led(zone_led), m_zone_id(zone_id)
{
}

bool Zone::check()
{
    return m_zone_sw.isOn();
}

void Zone::indicateViolation()
{
    m_zone_led.on();
    EEPROM.write(m_zone_id, 1);
}

int Zone::getId(){
  return m_zone_id;
}

void Zone::reset()
{
    m_zone_led.off();
    EEPROM.update(m_zone_id, 0);
}
