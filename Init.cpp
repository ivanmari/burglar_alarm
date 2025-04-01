#include "Init.h"
#include "ArmedIndicating.h"
#include "io_defs.h"

#ifdef X86_PLAT
#include "sim/EEPROM.h"
Eeprom EEPROM;
#else
#include <EEPROM.h>
#endif


Init::Init(Fsm* fsm, ASi* asi):State(fsm), m_asi(asi), m_armed_sw(ARMED, LOW, asi)
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
    m_asi->turnOffSiren();
    
    if(m_armed_sw.isOn())
    {
        for(auto i = 0; i < MAX_ZONES_COUNT; i++){
            EEPROM.update(i, 0);
        }
        m_fsm->setState(ArmedIndicating::Instance(m_fsm, m_asi));
        return;
    }
}

void
Init::reset()
{
}
