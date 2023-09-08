#ifndef __IHEATER__H__
#define __IHEATER__H__

namespace Interfaces
{
    class IHeater 
    {
        public:
        virtual void Loop(unsigned long now) = 0;
        virtual bool IsHeaterOn() = 0;
    };
}

#endif  //!__IHEATER__H__