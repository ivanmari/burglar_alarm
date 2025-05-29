#include "Armed.h"
#include "Panic.h"
#include "DisarmedIndicating.h"

#include "io_defs.h"

const long DELAY_BEFORE_ARMED = 20 * SECONDS;


Armed::Armed(Fsm* fsm, ASi* asi, Ipc* ipc):State(fsm), m_asi(asi),
m_disarm_sw(asi->getPlatform(), ARMED, HIGH),
  m_zone_1(Zone(Switch(asi->getPlatform(), ZONE_GPIO_1, HIGH), Led(ZONE_LED_1, HIGH, asi), ZONE_1)),
  m_zone_2(Zone(Switch(asi->getPlatform(), ZONE_GPIO_2, HIGH), Led(ZONE_LED_2, HIGH, asi), ZONE_2)),
  m_zone_3(Zone(Switch(asi->getPlatform(), ZONE_GPIO_3, HIGH), Led(ZONE_LED_3, HIGH, asi), ZONE_3)),
  m_zone_4(Zone(Switch(asi->getPlatform(), ZONE_GPIO_4, HIGH), Led(ZONE_LED_4, HIGH, asi), ZONE_4)),
  m_ipc(ipc)
{
  m_zones[ZONE_1] = &m_zone_1;
  m_zones[ZONE_2] = &m_zone_2;
  m_zones[ZONE_3] = &m_zone_3;
  m_zones[ZONE_4] = &m_zone_4;
}

Armed*
Armed::Instance(Fsm* fsm, ASi* asi, Ipc* ipc)
{
    static Armed Armed(fsm, asi, ipc);
    return &Armed;
}

void
Armed::execute()
{
    if(m_disarm_sw.isOn())
    {
        m_fsm->setState(DisarmedIndicating::Instance(m_fsm, m_asi, m_ipc));
        return;
    }

    for(auto zone: m_zones){
        if(zone->check()){
             m_ipc->setCoreAlarmCode(AlarmCodes::ALRM_ZONE_VIOLATION);
             m_ipc->setAlarmedZones(zone->getId());
             m_fsm->setState(Panic::Instance(m_fsm, m_asi, m_ipc));
             return;
        }
    }
}

void
Armed::reset()
{
}
