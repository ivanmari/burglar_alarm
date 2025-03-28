#include "Programming.h"
#include "Disarmed.h"

#include "io_defs.h"

const long long DELAY_BEFORE_ARMED = 20 * SECONDS;


Programming::Programming(Fsm* fsm, ASi* asi):State(fsm), m_asi(asi), 
m_sw(VIBRATION_SENSOR_1, HIGH, asi),
m_disarm_sw(DISARM, HIGH, asi),
m_delay(asi->getPlatform(), DELAY_BEFORE_ARMED)
{}

Programming*
Programming::Instance(Fsm* fsm, ASi* asi)
{
    static Programming Programming(fsm, asi);
    return &Programming;
}

void
Programming::execute()
{

}

void
Programming::reset()
{
}
