#include "AlarmedZonesActive.h"
#include "AlarmedZonesCleared.h"
#include "io_defs.h"
const long int LED_ON_TIME = 500 * MILLISECONDS;;
const long int LED_OFF_TIME = 500 * MILLISECONDS;;

AlarmedZonesActive::AlarmedZonesActive(Fsm *fsm, ASi *asi, Ipc *ipc) : State(fsm),
                                                                       m_blinker_1(asi->getPlatform(), ZONE_LED_1, LED_ON_TIME, LED_OFF_TIME, HIGH),
                                                                       m_blinker_2(asi->getPlatform(), ZONE_LED_2, LED_ON_TIME, LED_OFF_TIME, HIGH),
                                                                       m_blinker_3(asi->getPlatform(), ZONE_LED_3, LED_ON_TIME, LED_OFF_TIME, HIGH),
                                                                       m_blinker_4(asi->getPlatform(), ZONE_LED_4, LED_ON_TIME, LED_OFF_TIME, HIGH),

                                                                       m_asi(asi),
                                                                       m_ipc(ipc)
{
    m_blinkers[ZONE_1] = &m_blinker_1;
    m_blinkers[ZONE_2] = &m_blinker_2;
    m_blinkers[ZONE_3] = &m_blinker_3;
    m_blinkers[ZONE_4] = &m_blinker_4;
}

AlarmedZonesActive *
AlarmedZonesActive::Instance(Fsm *fsm, ASi *asi, Ipc *ipc)
{
    static AlarmedZonesActive instance(fsm, asi, ipc);
    return &instance;
}

void AlarmedZonesActive::execute()
{
    if (AlarmCodes::ALRM_CLEARED == m_ipc->getCoreAlarmCode())
    {
        m_fsm->setState(AlarmedZonesCleared::Instance(m_fsm, m_asi, m_ipc));
        reset();
        return;
    }

    for (auto i = 0; i < MAX_ZONES_COUNT; i++)
    {
        if (m_ipc->getAlarmedZones() == i)
        {
            m_blinkers[i]->execute();
        }
        else
        {
            m_blinkers[i]->reset();
        }
    }
}

void AlarmedZonesActive::reset()
{
    for (auto &blinker : m_blinkers)
    {
        blinker->reset();
    }
}
