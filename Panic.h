#ifndef PANIC_H
#define PANIC_H

#include <BarePoller.h>
#include "Fsm.h"
#include "Ipc.h"

/** \brief Panic
 *
 * While being in this state, the siren output is active during ACTIVE_PERIOD useconds
 *
 * Previous state: Armed
 * Next states: Disarmed, Armed
 *
 */


class Panic : public State
{
public:
    Panic(Fsm* fsm, ASi* asi, Ipc* ipc);

    static Panic* Instance(Fsm* fsm, ASi* asi, Ipc* ipc);

    void execute();
    void reset();
#ifdef X86_PLAT
    std::string getName() const
    {
        return "Panic";
    }
#endif // X86_PLAT
private:

    ASi* m_asi;
    Blinker m_blinker;
    PrecisionTimer m_periodTimer;
    Switch m_disarm_sw;
    Ipc* m_ipc;
};
#endif //PANIC_H
