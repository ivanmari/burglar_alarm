#include "ArmedIndicating.h"
#include "Armed.h"

#include "io_defs.h"

const long int PANIC_PERIOD = 110 * MILLISECONDS;
const long int SIREN_OFF = 100 * MILLISECONDS;
const long int SIREN_ON = 100 * MILLISECONDS;

ArmedIndicating::ArmedIndicating(Fsm* fsm, ASi* asi):State(fsm), m_asi(asi), m_periodTimer(asi->getPlatform(), PANIC_PERIOD), m_blinker(asi->getPlatform(), SIREN, SIREN_ON, SIREN_OFF, true)
{}

ArmedIndicating*
ArmedIndicating::Instance(Fsm* fsm, ASi* asi)
{
    static ArmedIndicating ArmedIndicating(fsm, asi);
    return &ArmedIndicating;
}

void
ArmedIndicating::execute()
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
}

void
ArmedIndicating::reset()
{
}
