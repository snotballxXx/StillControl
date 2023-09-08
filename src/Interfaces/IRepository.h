#ifndef IREPOSITORY_H
#define IREPOSITORY_H

namespace Interfaces
{
    class IRepository
    {
        public:
            virtual int GetLowerThreshold() = 0;
            virtual void SetLowerThreshold(int value) = 0;

            virtual int GetUpperThreshold() = 0;
            virtual void SetUpperThreshold(int value) = 0;       

            virtual int GetMarkTime() = 0;
            virtual void SetMarkTime(int value) = 0;  

            virtual int GetSpaceTime() = 0;
            virtual void SetSpaceTime(int value) = 0;                                       
    };
}
#endif