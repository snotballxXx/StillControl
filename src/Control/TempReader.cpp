#include <arduino.h>
#include "TempReader.h"
#include "../Constants.h"
#include "../Interfaces/IRepository.h"

using namespace Control;

TempReader::TempReader() :
    _currentTemp(0.0),
    _lastReadTime(0)
{
    _thermocouple = new MAX6675(THERMO_CLK, THERMO_CS, THERMO_DO);
}

void TempReader::Loop(unsigned long now)
{
  if (_lastReadTime < (now - THERMO_READ_TIME_INTERVAL))
  {
    _lastReadTime = now;  
    _currentTemp = _thermocouple->readCelsius();
    Serial.println(_currentTemp);
  }    
}