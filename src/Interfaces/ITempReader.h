#ifndef __ITEMP_READER__H__
#define __ITEMP_READER__H__

namespace Interfaces
{
    class ITempReader 
    {
        public:
        virtual void Loop(unsigned long now) = 0;
        virtual float GetTemp() = 0;
    };
}

#endif  //!__ITEMP_READER__H__