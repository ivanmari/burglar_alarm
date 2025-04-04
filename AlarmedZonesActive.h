#ifndef ALARMED_ZONES_ACTIVE_H
#define ALARMED_ZONES_ACTIVE_H

#include "Fsm.h"
#include "Ipc.h"
#include "Blinker.h"
#include "ASi.h"
#include "io_defs.h"

class AlarmedZonesActive : public State
{
public:
    AlarmedZonesActive(Fsm* fsm, ASi* asi, Ipc* ipc);

    static AlarmedZonesActive* Instance(Fsm* m_fsm, ASi* asi, Ipc* ipc);

    void execute();
    void reset();

#ifdef X86_PLAT
    std::string getName() const
    {
        return "AlarmedZonesActive";
    }
#endif // X86_PLAT

private:
 
    Blinker* m_blinkers[MAX_ZONES_COUNT];
    Blinker m_blinker_1, m_blinker_2, m_blinker_3, m_blinker_4;
    ASi* m_asi;
    Ipc* m_ipc;
};
#endif
