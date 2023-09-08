#ifndef MARK_TIME_H
#define MARK_TIME_H

#include "./StateBase.h" 

namespace StateMachine
{
    class MarkTime : public StateBase
    {
        int _newValue;
        public:
        MarkTime(Interfaces::IStateMachine* fsm,
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