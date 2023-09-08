#include <arduino.h>
#include "LcdDisplay.h"
#include <Wire.h>
#include <LiquidCrystal.h>
#include <LiquidCrystal_I2C.h>
#include "Constants.h"
#include "./Utilities/CustomerChars.h"

using namespace PotStill;

LcdDisplay::LcdDisplay()
{
    _lcd = new LiquidCrystal_I2C(0x27, 16, 2);
    _lcd->init();
    _lcd->backlight();

  // Create new characters:
  _lcd->createChar(0, UpArrow);
  _lcd->createChar(1, DownArrow);    
}

void LcdDisplay::Print(const char * msg)
{
    char message[16] = {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};
    int length = strlen(msg);

    for (int i = 0; i < length && i < 16; i++)
        message[i] = msg[i];

    _lcd->print(message);
}

void LcdDisplay::AddArrows()
{
  _lcd->setCursor(0, 1);
  _lcd->write(byte(0));
  _lcd->setCursor(15, 1);
  _lcd->write(byte(1));    
}

void LcdDisplay::Print(unsigned long value)
{
    _lcd->print(value);
}

void LcdDisplay::Print(int value)
{
    _lcd->print(value);
}

void LcdDisplay::Clear()
{
    _lcd->clear();
}

void LcdDisplay::SetCursor(int col, int row)
{
    _lcd->setCursor(col, row);
}

void LcdDisplay::Backlight(bool state)
{
    if (state)
        _lcd->backlight();
    else
        _lcd->noBacklight();  
}