#ifndef __ILCDDISPLAY__H__
#define __ILCDDISPLAY__H__

namespace Interfaces
{
    class ILcdDisplay
    {
        public:
        virtual void Print(const char * msg) = 0;
        virtual void Print(unsigned long value) = 0;
        virtual void Print(int value) = 0;
        virtual void Clear() = 0;
        virtual void SetCursor(int col, int row) = 0;
        virtual void Backlight(bool state) = 0;
        virtual void AddArrows() = 0;
    };
}

#endif  //!__ILCDDISPLAY__H__