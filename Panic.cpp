#include "Panic.h"
#include "Armed.h"
#include "DisarmedIndicating.h"

#include "io_defs.h"

const long SECONDS = 1000000;
const long MILLISECONDS = 1000;
const long int PANIC_PERIOD = 5 * SECONDS;
const long int SIREN_OFF = 500 * MILLISECONDS;
const long int SIREN_ON = 500 * MILLISECONDS;

Panic::Panic(Fsm* fsm, ASi* asi):State(fsm),
m_asi(asi), m_periodTimer(asi->getPlatform(), PANIC_PERIOD),
m_blinker(asi->getPlatform(), SIREN, SIREN_ON, SIREN_OFF, true),
m_disarm_sw(DISARM, HIGH, asi)
{}

Panic*
Panic::Instance(Fsm* fsm, ASi* asi)
{
    static Panic Panic(fsm, asi);
    return &Panic;
}

void
Panic::execute()
{
    m_periodTimer.start();
    
    m_blinker.execute();

    if(m_periodTimer.expired())
    {
        m_blinker.reset();
        m_periodTimer.reset();
        m_fsm->setState(Armed::Instance(m_fsm, m_asi));
        return;
    }

    if(m_disarm_sw.isOn())
    {
        m_blinker.reset();
        m_periodTimer.reset();
        m_fsm->setState(DisarmedIndicating::Instance(m_fsm, m_asi));
        return;
    }
}

void
Panic::reset()
{
}
