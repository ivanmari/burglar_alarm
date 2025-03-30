// Led.h
#ifndef LED_H
#define LED_H

#include "ASi.h"
#include "PrecisionTimer.h"

/** \brief Led
 *
 * This class represents a LED, with its port number and a ptr to the Platform to set or reset.
 * 
 * \param
 * \param
 * \return
 *
 */


class Led
{
public:

    Led(int m_pin, bool level, ASi* asi);

    void on();
    void off();

private:
    int m_pin;
    bool m_active_level;
    Platform* m_platform;
};

#endif //LED_H
