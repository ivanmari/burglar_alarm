#include "ASi.h"
#include "Led.h"

Led::Led(int m_pin, bool level, ASi* asi):m_pin(m_pin), m_active_level(level),
     m_platform(asi->getPlatform()) {}

void
Led::on()
{
    m_platform->setPin(m_pin, m_active_level);
}


void
Led::off()
{
    m_platform->setPin(m_pin, !m_active_level);
}