#ifndef ARMED_H
#define ARMED_H

#include "Fsm.h"
#include "PrecisionTimer.h"
#include "Zone.h"
#include "Ipc.h"
#include "io_defs.h"

/** \brief Armed
 *
 * While being in this state, the zones are polled periodically.
 * Once a switch is active, a transition to Panic is triggered
 *
 *
 * Previous state: none
 * Next states: Panic, Disarmed
 *
 */


class Armed : public State
{
public:
    Armed(Fsm* fsm, ASi* asi, Ipc* ipc);

    static Armed* Instance(Fsm* fsm, ASi* asi, Ipc* ipc);

    void execute();
    void reset();
#ifdef X86_PLAT
    std::string getName() const
    {
        return "Armed";
    }
#endif // X86_PLAT
private:

    ASi* m_asi;
    Zone m_zone_1;
    Zone m_zone_2;
    Zone m_zone_3;
    Zone m_zone_4;
    Zone* m_zones[MAX_ZONES_COUNT];
    Switch m_disarm_sw;
    Ipc* m_ipc;
};
#endif //ARMED_H
