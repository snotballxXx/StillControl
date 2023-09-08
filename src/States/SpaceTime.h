#ifndef SPACE_TIME_H
#define SPACE_TIME_H

#include "./StateBase.h" 

namespace StateMachine
{
    class SpaceTime : public StateBase
    {
        int _newValue;
        public:
        SpaceTime(Interfaces::IStateMachine* fsm,
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