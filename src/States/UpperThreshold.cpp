#include <arduino.h>
#include "UpperThreshold.h"
#include "../Constants.h"
#include "../Interfaces/ILcdDisplay.h"
#include "../Interfaces/IRepository.h"

using namespace StateMachine;

const char Line1[]  = "Upper Threshold";
const char Line2[]  = "      %d%cC";

UpperThreshold::UpperThreshold(Interfaces::IStateMachine* fsm, 
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

void UpperThreshold::Loop(unsigned long now)
{
    _leftButton->Update();
    _rightButton->Update();
    _okButton->Update();

    if (!_dataChange)
        return;

    Interfaces::ILcdDisplay* lcd = _provider->GetLcdDisplay();

    char line[16];
    lcd->SetCursor(0, 0);   
    lcd->Print(Line1);   

    lcd->SetCursor(0, 1);   
    sprintf(line, Line2, _newValue, (char)223);      
    lcd->Print(line);
    if (_editMode)
        lcd->AddArrows();
    
    _lastDisplayTime = now;
    _dataChange = false;
} 

void UpperThreshold::EnterState()
{
    _leftButton->SetCallback(this);
    _rightButton->SetCallback(this);
    _okButton->SetCallback(this);        

    _lastDisplayTime = millis() - DISPLAY_UPDATE_EVERY_X_MILLI;

    Clear();

    _newValue = _provider->GetRepository()->GetUpperThreshold();
    _dataChange = true;
    _editMode = false;
}

void UpperThreshold::ButtonPressedCallback(int id)
{
    switch (id)
    {
        case LEFT_BUTTON:
            if (_editMode)
            {
                _newValue++;
                if (_newValue >= MAX_UPPER_THRESHOLD)
                {
                    _newValue--;
                    return;
                }

                _dataChange = true;
            }
            else
            {
                _fsm->ChangeState(LOWER_THRESHOLD_STATE);
            }

        break;
        case RIGHT_BUTTON:
            if (_editMode)
            {
                _newValue--;

                if (_newValue <= MIN_UPPER_THRESHOLD || _newValue <= _provider->GetRepository()->GetLowerThreshold())
                {
                    _newValue++;
                    return;
                }            
                _dataChange = true;
            }
            else
            {
                _fsm->ChangeState(MARK_TIME_STATE);
            }        
           
        break;

        case OK_BUTTON:
            _provider->GetRepository()->SetUpperThreshold(_newValue);
            _editMode = !_editMode;
            _dataChange = true;
        break;
    }
}