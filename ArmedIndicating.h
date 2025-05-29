#ifndef ARMED_INDICATING_H
#define ARMED_INDICATING_H

#include <BarePoller.h>
#include "Fsm.h"
#include "PrecisionTimer.h"
#include "Switch.h"
#include "Ipc.h"

/** \brief ArmedIndicating
 *
 * While being in this state, the siren output is active during ACTIVE_PERIOD useconds
 * This is the cortesy beep that indicates the system is armed
 *
 * Previous state: Init
 * Next states: Armed
 *
 */


class ArmedIndicating : public State
{
public:
    ArmedIndicating(Fsm* fsm, ASi* asi, Ipc* ipc);

    static ArmedIndicating* Instance(Fsm* fsm, ASi* asi, Ipc* ipc);

    void execute();
    void reset();
#ifdef X86_PLAT
    std::string getName() const
    {
        return "ArmedIndicating";
    }
#endif // X86_PLAT
private:

    ASi* m_asi;
    Blinker m_blinker;
    PrecisionTimer m_periodTimer;
    Ipc* m_ipc;
};
#endif //ARMED_INDICATING_H
