// Switch.h
#ifndef ZONE_H
#define ZONE_H

#include "Led.h"
#include "Switch.h"

/** \brief Zone
 *
 * This class represents Zone in the system.
 * The zone is associated with a Switch and an indicator LED
 *
 * \param
 * \param
 * \return
 *
 */


class Zone
{
public:
    
    Zone(Switch zone_sw, Led zone_led, int zone_id);

    bool check();

    void indicate_violation();

private:
    Switch m_zone_sw;
    Led m_zone_led;
    int m_zone_id;
};

#endif //SWITCH_H
