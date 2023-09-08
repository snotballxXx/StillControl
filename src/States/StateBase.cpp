#include <arduino.h>
#include "StateBase.h"
#include "../Interfaces/ILcdDisplay.h"

#define CALL_BUTTON_UPDATE(b)  if (b != NULL) b->Update()

using namespace StateMachine;

StateBase::StateBase(Interfaces::IStateMachine* fsm, 
            Utils::Debounce* okButton,
            Utils::Debounce* leftButton,
            Utils::Debounce* rightButton,
            Interfaces::IServiceProvider* provider) :
        _provider(provider),
        _leftButton(leftButton),
        _rightButton(rightButton),
        _okButton(okButton),
        _fsm(fsm),
        _lastDisplayTime(0),
        _dataChange(true),
        _editMode(false)
{
    memset(_title, 0, sizeof(_title));
}

void StateBase::DisplayTitle()
{
    Interfaces::ILcdDisplay* lcd = _provider->GetLcdDisplay();
    lcd->SetCursor(0, 0);
    lcd->Print(_title);   
}

void StateBase::EnterState()
{
    _leftButton->SetCallback(this);
    _rightButton->SetCallback(this);
    _okButton->SetCallback(this);

    Clear();
    DisplayTitle();
    _dataChange = true;
}

void StateBase::Loop(unsigned long now)
{
    CALL_BUTTON_UPDATE(_leftButton);
    CALL_BUTTON_UPDATE(_rightButton);
    CALL_BUTTON_UPDATE(_okButton);
}

void StateBase::LeaveState()
{
    _leftButton->SetCallback(NULL);
    _rightButton->SetCallback(NULL);
    _okButton->SetCallback(NULL);
    Clear();
}

void StateBase::Clear()
{     
    Interfaces::ILcdDisplay* lcd = _provider->GetLcdDisplay();
    lcd->Clear();
}