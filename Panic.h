#ifndef PANIC_H
#define PANIC_H

#include "Blinker.h"
#include "Fsm.h"
#include "PrecisionTimer.h"
#include "Switch.h"

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
    Panic(Fsm* fsm, ASi* asi);

    static Panic* Instance(Fsm* fsm, ASi* asi);

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
};
#endif //PANIC_H
