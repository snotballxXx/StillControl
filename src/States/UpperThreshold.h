#ifndef UPPER_THRESHOLD_H
#define UPPER_THRESHOLD_H

#include "./StateBase.h" 

namespace StateMachine
{
    class UpperThreshold : public StateBase
    {
        int _newValue;
        public:
        UpperThreshold(Interfaces::IStateMachine* fsm,
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