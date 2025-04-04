#include "Ipc.h"

#ifdef X86_PLAT
#include <iostream>
#endif // X86_PLAT

Ipc::Ipc(): m_alarmed_zones(0),
    m_core_alarm_code(0)
{}

char
Ipc::getAlarmedZones() const
{
    return m_alarmed_zones;
}

char
Ipc::getCoreAlarmCode() const
{
    return m_core_alarm_code;
}

void
Ipc::setAlarmedZones(char val)
{
    m_alarmed_zones = val;
}

void
Ipc::setCoreAlarmCode(char code)
{
    #ifdef X86_PLAT
    std::cout << "IPC alarm set: " << (int) code << std::endl;
    #endif // X86_PLAT
    if(ALRM_CLEARED == code)
    {
        m_core_alarm_code = 0;
    }
    else
    {
        m_core_alarm_code |= code ;
    }
}

// void
// Ipc::clearCoreAlarmCode(char code)
// {
//     m_core_alarm_code &= ~code;
// }

void
Ipc::clearAlarmedZones()
{
    m_alarmed_zones = 0;
}

void
Ipc::reset()
{
    m_alarmed_zones = 0;
    m_core_alarm_code = 0;
}

