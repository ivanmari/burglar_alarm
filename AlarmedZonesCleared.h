#ifndef ALARMED_ZONES_CLEARED_H
#define ALARMED_ZONES_CLEARED_H

#include "Fsm.h"
#include "Ipc.h"
#include "ASi.h"
#include "Blinker.h"

class AlarmedZonesCleared : public State
{
public:
    AlarmedZonesCleared(Fsm* fsm, ASi* asi, Ipc* ipc);

    static AlarmedZonesCleared* Instance(Fsm* m_fsm, ASi* asi, Ipc* ipc);

    void execute();
    void reset();

#ifdef X86_PLAT
    std::string getName() const
    {
        return "AlarmedZonesCleared";
    }
#endif // X86_PLAT

private:
    ASi* m_asi;
    Ipc* m_ipc;
};
#endif //ALARMED_ZONES_CLEARED_H
