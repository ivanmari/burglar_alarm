#include "Zone.h"
#include <EEPROM.h>

Zone::Zone(Switch zone_sw, Led zone_led, int zone_id):m_zone_sw(zone_sw), m_zone_led(zone_led), m_zone_id(zone_id)
{
}

bool Zone::check()
{
    return m_zone_sw.isOn();
}

void Zone::indicate_violation()
{
    m_zone_led.on();
    EEPROM.write(m_zone_id, 1);
}
