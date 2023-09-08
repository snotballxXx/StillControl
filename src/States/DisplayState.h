#ifndef DISPLAYSTATE_H
#define DISPLAYSTATE_H

#include "./StateBase.h" 

namespace StateMachine
{
    class DisplayState : public StateBase
    {
        public:
        DisplayState(Interfaces::IStateMachine* fsm,
            Utils::Debounce* okButton,
            Utils::Debounce* leftButton,
            Utils::Debounce* rightButton,
            Interfaces::IServiceProvider* provider);

        void EnterState();
        void Loop(unsigned long now);    
        void ButtonPressedCallback(int id);
    };
}
#endif