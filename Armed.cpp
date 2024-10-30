#include "Armed.h"
#include "Panic.h"
#include "DisarmedIndicating.h"

#include "io_defs.h"


Armed::Armed(Fsm* fsm, ASi* asi):State(fsm), m_asi(asi), m_sw(VIBRATION_SENSOR_1, HIGH, asi), m_disarm_sw(DISARM, HIGH, asi)
{}

Armed*
Armed::Instance(Fsm* fsm, ASi* asi)
{
    static Armed Armed(fsm, asi);
    return &Armed;
}

void
Armed::execute()
{
    if(m_sw.isOn())
    {
        m_fsm->setState(Panic::Instance(m_fsm, m_asi));
        return;
    }

    if(m_disarm_sw.isOn())
    {
        m_fsm->setState(DisarmedIndicating::Instance(m_fsm, m_asi));
        return;
    }
}

void
Armed::reset()
{
}
