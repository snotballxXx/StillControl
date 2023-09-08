#include <arduino.h>
#include "MarkTime.h"
#include "../Constants.h"
#include "../Interfaces/ILcdDisplay.h"
#include "../Interfaces/IRepository.h"

using namespace StateMachine;

const char Line1[]  = "   Mark Time";
const char Line2[]  = "    %d ms";

MarkTime::MarkTime(Interfaces::IStateMachine* fsm, 
            Utils::Debounce* okButton,
            Utils::Debounce* leftButton,
            Utils::Debounce* rightButton,
            Interfaces::IServiceProvider* provider) : StateBase(fsm, 
                okButton,
                leftButton,
                rightButton,
                provider)
{
}

void MarkTime::Loop(unsigned long now)
{
    _leftButton->Update();
    _rightButton->Update();
    _okButton->Update();

    if (!_dataChange)
        return;

    Interfaces::ILcdDisplay* lcd = _provider->GetLcdDisplay();

    char line[16]; 
    lcd->SetCursor(0, 1);   
    sprintf(line, Line2, _newValue);      
    lcd->Print(line);
    if (_editMode)
        lcd->AddArrows();
    
    _lastDisplayTime = now;
    _dataChange = false;
} 

void MarkTime::EnterState()
{
    _leftButton->SetCallback(this);
    _rightButton->SetCallback(this);
    _okButton->SetCallback(this);        

    _lastDisplayTime = millis() - DISPLAY_UPDATE_EVERY_X_MILLI;

    Clear();

    _newValue = _provider->GetRepository()->GetMarkTime();
    _dataChange = true;
    _editMode = false;

    Interfaces::ILcdDisplay* lcd = _provider->GetLcdDisplay();
    lcd->SetCursor(0, 0);   
    lcd->Print(Line1);     
}

void MarkTime::ButtonPressedCallback(int id)
{
    switch (id)
    {
        case LEFT_BUTTON:
            if (_editMode)
            {        
                _newValue += MARKSPACE_TIME_INCREMENT;
                _dataChange = true; 
            }          
            else
            {
                _fsm->ChangeState(UPPER_THRESHOLD_STATE);
            }
        break;
        case RIGHT_BUTTON:
            if (_editMode)
            {
                _newValue -= MARKSPACE_TIME_INCREMENT;

                if (_newValue <= 50)
                {
                    _newValue += MARKSPACE_TIME_INCREMENT;
                    return;
                }            
                _dataChange = true;            
            }
            else
            {
                _fsm->ChangeState(SPACE_TIME_STATE);
            }     
        break;

        case OK_BUTTON:
            _provider->GetRepository()->SetMarkTime(_newValue);
            _editMode = !_editMode;
            _dataChange = true;
        break;                           
    }
}