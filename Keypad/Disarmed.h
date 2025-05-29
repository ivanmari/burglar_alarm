#ifndef DISARMED_H
#define DISARMED_H

#include "../Fsm.h"
#include <BarePoller.h>

/** \brief Disarmed
 *
 * While being in this state, the keys are polled periodically.
 * Once a correct pwd is introduced, the level or pulse is generated and
 * the machine transitions to Armed
 * If * is pressed, the machine transitions to Programming
 * A timeout occurs if 
 *
 *
 * Previous state: none
 * Next states: Armed, Programming
 *
 */


class Disarmed : public State
{
public:
    Disarmed(Fsm* fsm, ASi* asi);

    static Disarmed* Instance(Fsm* fsm, ASi* asi);

    void execute();
    void reset();
#ifdef X86_PLAT
    std::string getName() const
    {
		return "Disarmed";
	    }
#endif // X86_PLAT
private:

    ASi* m_asi;
    PrecisionTimer m_delay;
    PrecisionTimer m_input_timeout;
};
#endif //DISARMED_H
