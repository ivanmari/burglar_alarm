#include "Init.h"
#include "Disarmed.h"

#include "io_defs.h"


Init::Init(Fsm* fsm, ASi* asi):State(fsm), m_asi(asi)
{}

Init*
Init::Instance(Fsm* fsm, ASi* asi)
{
    static Init Init(fsm, asi);
    return &Init;
}

void
Init::execute()
{
    m_asi->getPlatform()->setPinMode(ARMED, PIN_OUTPUT);

    m_fsm->setState(Disarmed::Instance(m_fsm, m_asi));
    return;
}

void
Init::reset()
{
}
