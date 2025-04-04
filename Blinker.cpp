#include "Blinker.h"
#include "Armed.h"

#include "io_defs.h"

Blinker::Blinker(Platform *plat, int output_pin, long int time_on, long int time_off, bool active_level) : m_plat(plat),
                                                                                                           m_active_level(active_level),
                                                                                                           m_output_pin(output_pin),
                                                                                                           m_blinkOnTimer(plat, time_on),
                                                                                                           m_blinkOffTimer(plat, time_off)
{
    m_plat->setPinMode(m_output_pin, PIN_OUTPUT);
}

Blinker::Blinker() : m_output_pin(0),
                    m_active_level(false),
                    m_blinkOnTimer(0, 0),
                    m_blinkOffTimer(0, 0)
{
}

void Blinker::execute()
{
    if (m_blinkOffTimer.stopped() && m_blinkOnTimer.stopped())
    {
        m_blinkOnTimer.start();
    }

    if (m_blinkOnTimer.running())
    {
        if (m_blinkOnTimer.expired())
        {
            m_blinkOffTimer.start();
            m_blinkOnTimer.reset();
        }
        else
        {
            m_plat->setPin(m_output_pin, m_active_level);
        }
    }

    if (m_blinkOffTimer.running())
    {
        if (m_blinkOffTimer.expired())
        {
            m_blinkOnTimer.start();
            m_blinkOffTimer.reset();
        }
        else
        {
            m_plat->setPin(m_output_pin, !m_active_level);
        }
    }
}

void Blinker::reset()
{
    m_blinkOnTimer.reset();
    m_blinkOffTimer.reset();
    m_plat->setPin(m_output_pin, !m_active_level);
}
