#include "Armed.h"
#include "Panic.h"
#include "DisarmedIndicating.h"

#include "io_defs.h"

const long DELAY_BEFORE_ARMED = 20 * SECONDS;


Armed::Armed(Fsm* fsm, ASi* asi):State(fsm), m_asi(asi),
m_disarm_sw(ARMED, LOW, asi),
  m_zone_1(Zone(Switch(ZONE_1, HIGH, asi), Led(ZONE_LED_1, HIGH, asi), ZONE_1)),
  m_zone_2(Zone(Switch(ZONE_2, HIGH, asi), Led(ZONE_LED_2, HIGH, asi), ZONE_2)),
  m_zone_3(Zone(Switch(ZONE_3, HIGH, asi), Led(ZONE_LED_3, HIGH, asi), ZONE_3)),
  m_zone_4(Zone(Switch(ZONE_4, HIGH, asi), Led(ZONE_LED_4, HIGH, asi), ZONE_4))
{
  m_zones[ZONE_1] = &m_zone_1;
  m_zones[ZONE_2] = &m_zone_2;
  m_zones[ZONE_3] = &m_zone_3;
  m_zones[ZONE_4] = &m_zone_4;
}

Armed*
Armed::Instance(Fsm* fsm, ASi* asi)
{
    static Armed Armed(fsm, asi);
    return &Armed;
}

void
Armed::execute()
{
    if(m_disarm_sw.isOn())
    {
        m_fsm->setState(DisarmedIndicating::Instance(m_fsm, m_asi));
        return;
    }

    for(auto zone: m_zones){
        if(zone->check()){
             zone->indicate_violation();
             m_fsm->setState(Panic::Instance(m_fsm, m_asi));
             return;
        }
    }
}

void
Armed::reset()
{
}
