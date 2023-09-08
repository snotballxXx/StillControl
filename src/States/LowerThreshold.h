#ifndef LOWER_THRESHOLD_H
#define LOWER_THRESHOLD_H

#include "./StateBase.h" 

namespace StateMachine
{
    class LowerThreshold : public StateBase
    {
        int _newValue;
        public:
        LowerThreshold(Interfaces::IStateMachine* fsm,
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