#include "Init.h"
#include "ArmedIndicating.h"
#include "io_defs.h"

#ifdef X86_PLAT
#include "sim/EEPROM.h"
Eeprom EEPROM;
#else
#include <EEPROM.h>
#endif


Init::Init(Fsm* fsm, ASi* asi, Ipc* ipc):State(fsm), m_asi(asi), m_ipc(ipc), m_armed_sw(asi->getPlatform(), ARMED, LOW)
{}

Init*
Init::Instance(Fsm* fsm, ASi* asi, Ipc* ipc)
{
    static Init Init(fsm, asi, ipc);
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
        m_ipc->setCoreAlarmCode(ALRM_CLEARED);//TODO Should be cleared by explicit user command
        m_fsm->setState(ArmedIndicating::Instance(m_fsm, m_asi, m_ipc));
        return;
    }
}

void
Init::reset()
{
}
