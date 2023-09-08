#ifndef FSM_H
#define FSM_H

#include "./Interfaces/IStateMachine.h"
#include "Constants.h"

namespace Interfaces
{
    class IServiceProvider;
}

namespace Utils
{
    class Debounce;
}

namespace StateMachine
{
    class FSM : public Interfaces::IStateMachine
    {
        Interfaces::IState* _currentState;
        Interfaces::IState* _states[STATE_COUNT];

        Utils::Debounce* _okButton;
        Utils::Debounce* _leftButton;
        Utils::Debounce* _rightButton;
        Utils::Debounce* _upButton;
        Utils::Debounce* _downButton;

        public:
        FSM(Interfaces::IServiceProvider* serviceProvider);
        virtual void ChangeState(int stateId);   
        virtual void Loop(unsigned long now);
    };
}
#endif