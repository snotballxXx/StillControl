#include <arduino.h>
#include "./Debounce.h"

using namespace Utils;

Debounce::Debounce(int pin, int time) : 
    _pin(pin),
    _debounceTime(time),
    _callbackObject(NULL),
    _lastStateChangeTime(0),
    _stateChangeInProgress(false),
    _callBackInvoked(false)
{
    pinMode(_pin, INPUT_PULLUP);
}

void Debounce::Update()
{
    int state = digitalRead(_pin);
    unsigned long now = millis();

    if (state == HIGH && _callBackInvoked)
        _callBackInvoked = false;

    if (!_stateChangeInProgress && state == LOW && !_callBackInvoked)
    {
        _stateChangeInProgress = true;
        _lastStateChangeTime = now;
    }

    if (_stateChangeInProgress)
    {
        if ((_lastStateChangeTime + _debounceTime) < now)
        {           
            if (state == LOW && _callbackObject != NULL)       
            {
                _callBackInvoked = true;  
                _callbackObject->ButtonPressedCallback(_pin);
            }
                   
            _stateChangeInProgress = false;                      
        }
    }
}

void Debounce::SetCallback(IButtonPressCallBack* cb)
{
    _callbackObject = cb;
    _stateChangeInProgress = false;
}