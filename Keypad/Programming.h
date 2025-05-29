#ifndef PROGRAMMING_H
#define PROGRAMMING_H

#include "../Fsm.h"
#include <BarePoller.h>

/** \brief Programming
 *
 * While being in this state, the zones are polled periodically.
 * Once a switch is active, a transition to Panic is triggered
 *
 *
 * Previous state: none
 * Next states: Panic, Disarmed
 *
 */


class Programming : public State
{
public:
    Programming(Fsm* fsm, ASi* asi);

    static Programming* Instance(Fsm* fsm, ASi* asi);

    void execute();
    void reset();
#ifdef X86_PLAT
    std::string getName() const
    {
        return "Programming";
    }
#endif // X86_PLAT
private:

    ASi* m_asi;
    PrecisionTimer m_delay;
};
#endif //PROGRAMMING_H
