#ifndef INIT_H
#define INIT_H

#include "ASi.h"
#include "Fsm.h"
#include "PrecisionTimer.h"

/** \brief INIT
 *
 * State reached after keypad is turned ON.
 * HW initialization and EEPROM read occurs during this state
 *
 *
 * Previous state: none
 * Next states: Armed, Disarmed, Failure
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
};
#endif //Init_H
