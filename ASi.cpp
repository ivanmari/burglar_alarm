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
    m_platform->setPin(SIREN, LOW);
    m_platform->setPinMode(SIREN, PIN_OUTPUT);

    m_platform->setPinMode(ZONE_GPIO_1, PIN_INPUT);
    m_platform->setPinMode(ZONE_GPIO_2, PIN_INPUT);
    m_platform->setPinMode(ZONE_GPIO_3, PIN_INPUT);
    m_platform->setPinMode(ZONE_GPIO_4, PIN_INPUT);

    m_platform->setPinMode(ZONE_LED_1, PIN_OUTPUT);
    m_platform->setPinMode(ZONE_LED_2, PIN_OUTPUT);
    m_platform->setPinMode(ZONE_LED_3, PIN_OUTPUT);
    m_platform->setPinMode(ZONE_LED_4, PIN_OUTPUT);

    m_platform->setPin(ZONE_LED_1, LOW);
    m_platform->setPin(ZONE_LED_2, LOW);
    m_platform->setPin(ZONE_LED_3, LOW);
    m_platform->setPin(ZONE_LED_4, LOW);
}

void
ASi::soundSiren()
{
  m_platform->setPin(SIREN, HIGH);
  
}

void
ASi::turnOffSiren()
{
  m_platform->setPin(SIREN, LOW);
  
}

Platform*
ASi::getPlatform() const
{
    return m_platform;
}
