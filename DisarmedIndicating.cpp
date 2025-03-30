#include "DisarmedIndicating.h"
#include "Init.h"

#include "io_defs.h"

const long int PANIC_PERIOD = 330 * MILLISECONDS;
const long int SIREN_OFF = 100 * MILLISECONDS;
const long int SIREN_ON = 100 * MILLISECONDS;

DisarmedIndicating::DisarmedIndicating(Fsm* fsm, ASi* asi):State(fsm), m_asi(asi), m_periodTimer(asi->getPlatform(), PANIC_PERIOD), m_blinker(asi->getPlatform(), SIREN, SIREN_ON, SIREN_OFF, true)
{}

DisarmedIndicating*
DisarmedIndicating::Instance(Fsm* fsm, ASi* asi)
{
    static DisarmedIndicating DisarmedIndicating(fsm, asi);
    return &DisarmedIndicating;
}

void
DisarmedIndicating::execute()
{
    m_periodTimer.start();
    
    m_blinker.execute();

    if(m_periodTimer.expired())
    {
        m_blinker.reset();
        m_periodTimer.reset();
        m_fsm->setState(Init::Instance(m_fsm, m_asi));
        return;
    }
}

void
DisarmedIndicating::reset()
{
}
