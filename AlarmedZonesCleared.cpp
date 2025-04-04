#include "AlarmedZonesCleared.h"
#include "AlarmedZonesActive.h"

AlarmedZonesCleared::AlarmedZonesCleared(Fsm* fsm, ASi* asi, Ipc* ipc): State(fsm),
    m_asi(asi),
    m_ipc(ipc)
{

}

AlarmedZonesCleared*
AlarmedZonesCleared::Instance(Fsm* fsm, ASi* asi, Ipc* ipc)
{
    static AlarmedZonesCleared instance(fsm, asi, ipc);
    return &instance;
}

void
AlarmedZonesCleared::execute()
{
    if(AlarmCodes::ALRM_CLEARED != m_ipc->getCoreAlarmCode()){
    	m_fsm->setState(AlarmedZonesActive::Instance(m_fsm, m_asi, m_ipc));
    }
}

void
AlarmedZonesCleared::reset()
{}