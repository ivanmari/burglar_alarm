#ifndef IPC_H
#define IPC_H

#include "Platform.h"

enum AlarmCodes
{
    ALRM_CLEARED = 0,
    ALRM_ZONE_VIOLATION = 1,
    ALRM_TAMPERING = 2,
    ALRM_CIRCUIT_FAILURE = 4,
    ALRM_GENERAL_FAILURE = 8,

};

/** \brief Interprocess Communication
 *
 *  This class serves as the communication link between the running Finite State Machines
 *
 *
 */


class Ipc
{
public:

    Ipc();

    virtual char getAlarmedZones() const;
    virtual char getCoreAlarmCode() const;

    virtual void setAlarmedZones(char val);
    virtual void setCoreAlarmCode(char code);
    virtual void clearAlarmedZones();

    void reset();

private:

    char m_alarmed_zones;
    char m_core_alarm_code;
};
#endif //IPC_H
