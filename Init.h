#ifndef INIT_H
#define INIT_H

#include "Fsm.h"
#include "PrecisionTimer.h"
#include "Switch.h"

/** \brief INIT
 *
 * While being in this state, the zones are polled periodically.
 * Once a switch is active, a transition to Panic is triggered
 *
 *
 * Previous state: none
 * Next states: Panic, DisInit
 *
 */


class Init : public State
{
public:
    Init(Fsm* fsm, ASi* asi);

    static Init* Instance(Fsm* fsm, ASi* asi);

    void execute();
    void reset();
#ifdef X86_PLAT
    std::string getName() const
    {
        return "Init";
    }
#endif // X86_PLAT
private:

    ASi* m_asi;
    Switch m_armed_sw;
};
#endif //Init_H
