#ifndef ISTATEMACHINE_H
#define ISTATEMACHINE_H

namespace Interfaces 
{
    class IState;

    class IStateMachine
    {
        public:
        virtual void ChangeState(int stateId) = 0;
        virtual void Loop(unsigned long now) = 0;
    };
}
#endif
