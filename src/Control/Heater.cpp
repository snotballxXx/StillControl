#include <arduino.h>
#include "Heater.h"
#include "../Constants.h"
#include "../Interfaces/ITempReader.h"
#include "../Interfaces/IRepository.h""

using namespace Control;

Heater::Heater(Interfaces::ITempReader* tempReader, Interfaces::IRepository* repository) :
    _tempReader(tempReader),
    _repository(repository),
    _heaterOn(false),
    _lastSwitchTime(0),
    _inMark(false)
{
    pinMode(HEATER_OUTPUT, OUTPUT);
    digitalWrite(HEATER_OUTPUT, LOW);
}

void Heater::Loop(unsigned long now)
{
    int markPeriod = _repository->GetMarkTime();
    int spacePeriod = _repository->GetSpaceTime();

    unsigned long compareValue = _inMark ? markPeriod : spacePeriod;

    if (_lastSwitchTime < (now - compareValue))
    {
        int lowerThreshold = _repository->GetLowerThreshold();
        int upperThreshold = _repository->GetUpperThreshold();

        _lastSwitchTime = now;
        _inMark = !_inMark;
        int outputState;

        //if in range pulse heater
        float currentTemp = _tempReader->GetTemp();
        if (currentTemp > lowerThreshold && currentTemp < upperThreshold)
        {
          outputState = _inMark ? HIGH : LOW;
        }
        else if (currentTemp < lowerThreshold)
        {
          outputState = HIGH;
        }
        else
        {
          outputState = LOW;
        }

        digitalWrite(HEATER_OUTPUT, outputState); 
        _heaterOn = outputState == HIGH;   
    } 
}