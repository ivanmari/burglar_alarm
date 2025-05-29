#ifndef DISARMED_INDICATING_H
#define DISARMED_INDICATING_H

#include <BarePoller.h>
#include "Fsm.h"
#include "PrecisionTimer.h"
#include "Switch.h"
#include "Ipc.h"

/** \brief DisarmedIndicating
 *
 * While being in this state, the siren output indicates the state change to Disarmed
 *
 * Previous state: Armed
 * Next states: Disarmed
 *
 */


class DisarmedIndicating : public State
{
public:
    DisarmedIndicating(Fsm* fsm, ASi* asi, Ipc* ipc);

    static DisarmedIndicating* Instance(Fsm* fsm, ASi* asi, Ipc* ipc);

    void execute();
    void reset();
#ifdef X86_PLAT
    std::string getName() const
    {
        return "DisarmedIndicating";
    }
#endif // X86_PLAT
private:

    ASi* m_asi;
    Blinker m_blinker;
    PrecisionTimer m_periodTimer;
    Ipc* m_ipc;
};
#endif //DISARMED_INDICATING_H
