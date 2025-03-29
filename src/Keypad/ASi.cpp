#include "ASi.h"
#include "Platform.h"
#include "io_defs.h"

#ifdef X86
#include <iomanip>
#include <iostream>
#include <bitset>
#endif

/*
    ASi: Actuator Sensor interface

*/

ASi::ASi(Platform* plat, SimpleQueue* SimpleQueue):m_platform(plat), m_SimpleQueue(SimpleQueue), m_rx_bit_buff(0), m_rx_bit_buff_count(0), m_frame_ready(false)
{
    m_platform->setPin(BUZZER, LOW);
    m_platform->setPinMode(ARMED, PIN_OUTPUT);
    m_platform->setPinMode(PROGRAMMING_LED, PIN_OUTPUT);
    m_platform->setPinMode(DISARMED_LED, PIN_OUTPUT);
    m_platform->setPinMode(ARMED_LED, PIN_OUTPUT);

}

void
ASi::beepOn()
{
  m_platform->setPin(BUZZER, HIGH);
  
}

void
ASi::beepOff()
{
  m_platform->setPin(BUZZER, LOW);
  
}

Platform*
ASi::getPlatform() const
{
    return m_platform;
}
