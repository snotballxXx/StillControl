#include <arduino.h>
#include "DisplayState.h"
#include "../Constants.h"
#include "../Interfaces/IWebServer.h"
#include "../Interfaces/ITempReader.h"
#include "../Interfaces/IHeater.h"
#include "../Interfaces/ILcdDisplay.h"

using namespace StateMachine;

const char Line1[]  = "%4.2f%cC, %s";
const char Line2[]  = "IP %s";

DisplayState::DisplayState(Interfaces::IStateMachine* fsm, 
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

void DisplayState::Loop(unsigned long now)
{
    _leftButton->Update();
    _rightButton->Update();

    if ((_lastDisplayTime + DISPLAY_UPDATE_EVERY_X_MILLI) > now)
        return;

    Interfaces::ILcdDisplay* lcd = _provider->GetLcdDisplay();

    char line[16];
    sprintf(line, Line1, _provider->GetTempReader()->GetTemp(), (char)223, _provider->GetHeater()->IsHeaterOn() ? "on" : "off");
    lcd->SetCursor(0, 0);   
    lcd->Print(line);   
    _lastDisplayTime = now;
} 

void DisplayState::EnterState()
{
    _leftButton->SetCallback(this);
    _rightButton->SetCallback(this);

    _lastDisplayTime = millis() - DISPLAY_UPDATE_EVERY_X_MILLI;

    Clear();    
    
    char ip[16];
    char line[16];
    Interfaces::ILcdDisplay* lcd = _provider->GetLcdDisplay();
    lcd->SetCursor(0, 1);  
    _provider->GetWebServer()->GetIpAddress().toCharArray(ip, 16);
    sprintf(line, Line2, ip);      
    lcd->Print(line);
}

void DisplayState::ButtonPressedCallback(int id)
{
    if (id == LEFT_BUTTON)
    {
        _fsm->ChangeState(SPACE_TIME_STATE);
        return;
    }

    if (id == RIGHT_BUTTON)
    {
        _fsm->ChangeState(LOWER_THRESHOLD_STATE);
        return;
    }
}