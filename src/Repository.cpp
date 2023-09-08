#include <arduino.h>
#include <EEPROM.h>
#include "Repository.h"
#include "Constants.h"

using namespace PotStill;

Repository::Repository()
{  
    int magicNumber = EEPROM.read(MAGIC_NUMBER_ADDR);

//    Serial.print("MagicNumber-");
//    Serial.println(magicNumber);

    if (magicNumber == MAGIC_NUMBER)
    {
//        Serial.println("reading eeprom");  
        _lowerThreshold = ReadWord(LOWER_THRESHOLD_ADDR);
        _upperThreshold = ReadWord(UPPER_THRESHOLD_ADDR);
        _markTime = ReadWord(MARK_TIME_ADDR);
        _spaceTime = ReadWord(SPACE_TIME_ADDR);
    }
    else
    {
        _lowerThreshold = DEFAULT_VALUE_LOWER_THRESHOLD;
        _upperThreshold = DEFAULT_VALUE_UPPER_THRESHOLD;
        _markTime = DEFAULT_VALUE_MARK_TIME;
        _spaceTime = DEFAULT_VALUE_SPACE_TIME; 

        EEPROM.write(MAGIC_NUMBER_ADDR, MAGIC_NUMBER);
        WriteWord(LOWER_THRESHOLD_ADDR, _lowerThreshold);
        WriteWord(UPPER_THRESHOLD_ADDR, _upperThreshold);
        WriteWord(MARK_TIME_ADDR, _markTime);
        WriteWord(SPACE_TIME_ADDR, _spaceTime);       
    }

/*    Serial.print("lower-");
    Serial.println(_lowerThreshold);
    Serial.print("upper-");
    Serial.println(_upperThreshold);    */ 
}

int Repository::ReadWord(int baseAddress)
{
    return (EEPROM.read(baseAddress + 1) << 8) | EEPROM.read(baseAddress);
}

void Repository::WriteWord(int baseAddress, int value)
{
    EEPROM.write(baseAddress, value & 0x000000FF);
    EEPROM.write(baseAddress + 1, value >> 8);    
}

void Repository::SetLowerThreshold(int value)
{
    _lowerThreshold = value; 
    WriteWord(LOWER_THRESHOLD_ADDR, value);
}  

void Repository::SetUpperThreshold(int value)
{
    _upperThreshold = value; 
    WriteWord(UPPER_THRESHOLD_ADDR, value);
}

void Repository::SetMarkTime(int value)
{
    _markTime = value; 
    WriteWord(MARK_TIME_ADDR, value);
}

void Repository::SetSpaceTime(int value)
{
    _spaceTime = value; 
    WriteWord(SPACE_TIME_ADDR, value);
}