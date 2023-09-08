#ifndef __LCDDISPLAY__H__
#define __LCDDISPLAY__H__

#include "./Interfaces/ILcdDisplay.h"

class LiquidCrystal;
class LiquidCrystal_I2C;

namespace PotStill
{
    class LcdDisplay : public Interfaces::ILcdDisplay
    {
        //LiquidCrystal* _lcd;
        LiquidCrystal_I2C* _lcd; 
        public:
        LcdDisplay();
        void AddArrows();
        void Print(const char * msg);
        void Clear();
        void SetCursor(int col, int row);
        void Backlight(bool state);
        void Print(unsigned long value);
        void Print(int value);
    };
}
#endif  //!__LCDDISPLAY__H__