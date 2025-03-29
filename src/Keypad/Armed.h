#ifndef ARMED_H
#define ARMED_H

#include "Fsm.h"
#include "PrecisionTimer.h"
#include "Switch.h"

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
    Armed(Fsm* fsm, ASi* asi);

    static Armed* Instance(Fsm* fsm, ASi* asi);

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
    PrecisionTimer m_delay;
    PrecisionTimer m_input_timeout;
};
#endif //ARMED_H
