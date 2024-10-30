#ifndef DISARMED_INDICATING_H
#define DISARMED_INDICATING_H

#include "Blinker.h"
#include "Fsm.h"
#include "PrecisionTimer.h"
#include "Switch.h"

/** \brief DisarmedIndicating
 *
 * While being in this state, the siren output is active during ACTIVE_PERIOD useconds
 *
 * Previous state: Armed
 * Next states: Disarmed, Armed
 *
 */


class DisarmedIndicating : public State
{
public:
    DisarmedIndicating(Fsm* fsm, ASi* asi);

    static DisarmedIndicating* Instance(Fsm* fsm, ASi* asi);

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
};
#endif //DISARMED_INDICATING_H
