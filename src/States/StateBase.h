#ifndef __STATEBASE__H__
#define __STATEBASE__H__

#include "../Interfaces/IState.h"
#include "../Utilities/Debounce.h"
#include "../Interfaces/IStateMachine.h"
#include "../Interfaces/IServiceProvider.h"
#include "../Interfaces/IStateMachine.h"


namespace StateMachine
{
    class StateBase : public Interfaces::IState, public Utils::IButtonPressCallBack
    {
        protected:
            Utils::Debounce* _okButton;
            Utils::Debounce* _leftButton;
            Utils::Debounce* _rightButton;
            Interfaces::IStateMachine* _fsm;
            Interfaces::IServiceProvider* _provider;

            char _title[16];
            void DisplayTitle();
            void Clear();
            unsigned long _lastDisplayTime;
            bool _dataChange;
            bool _editMode;
        public:
        StateBase(Interfaces::IStateMachine* fsm,
            Utils::Debounce* okButton,
            Utils::Debounce* leftButton,
            Utils::Debounce* rightButton,
            Interfaces::IServiceProvider* provider);

            void EnterState();
            void LeaveState();
            void Loop(unsigned long now);    
    };
}


#endif  //!__STATEBASE__H__