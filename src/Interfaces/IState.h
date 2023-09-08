#ifndef ISTATE_H
#define ISTATE_H

namespace Interfaces
{
    class IState
    {
        public:
        virtual void EnterState() = 0;
        virtual void LeaveState() = 0;
        virtual void Loop(unsigned long now) = 0;
    };
}
#endif