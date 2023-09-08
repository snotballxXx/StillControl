#include <arduino.h>
#include "FSM.h"
#include "./Interfaces/IState.h"
#include "./Interfaces/IServiceProvider.h"
#include "./States/DisplayState.h"
#include "./Utilities/Debounce.h"
#include "Constants.h"
#include "./States/LowerThreshold.h"
#include "./States/UpperThreshold.h"
#include "./States/MarkTime.h"
#include "./States/SpaceTime.h"

using namespace StateMachine;

FSM::FSM(Interfaces::IServiceProvider* serviceProvider)
{
    _okButton    = new Utils::Debounce(OK_BUTTON, DEBOUNCE_TIME);
    _leftButton  = new Utils::Debounce(LEFT_BUTTON, DEBOUNCE_TIME);
    _rightButton = new Utils::Debounce(RIGHT_BUTTON, DEBOUNCE_TIME);

    _states[DISPLAY_STATE]               = new DisplayState(this, _okButton, _leftButton, _rightButton, serviceProvider);
    _states[LOWER_THRESHOLD_STATE]       = new LowerThreshold(this, _okButton, _leftButton, _rightButton, serviceProvider);
    _states[UPPER_THRESHOLD_STATE]       = new UpperThreshold(this, _okButton, _leftButton, _rightButton, serviceProvider);
    _states[MARK_TIME_STATE]             = new MarkTime(this, _okButton, _leftButton, _rightButton, serviceProvider);
    _states[SPACE_TIME_STATE]            = new SpaceTime(this, _okButton, _leftButton, _rightButton, serviceProvider);

    _currentState = _states[DISPLAY_STATE];
    _currentState->EnterState();
}

void FSM::ChangeState(int stateId)
{
    _currentState->LeaveState();
    _states[stateId]->EnterState();
    _currentState = _states[stateId];
}

void FSM::Loop(unsigned long now)
{
    _currentState->Loop(now);
}