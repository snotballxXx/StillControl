#ifndef __TEMP_READER__H__
#define __TEMP_READER__H__

#include "../Interfaces/ITempReader.h"
#include <max6675.h>

namespace Interfaces
{
    class IRepository;
    class IStateMachine;
}

namespace Control
{    
    class TempReader : public Interfaces::ITempReader
    {
        Interfaces::IRepository* _repo;
        MAX6675* _thermocouple;
        unsigned long _lastReadTime;
        float _currentTemp;

        public:
        TempReader();
        void Loop(unsigned long now);
        float GetTemp() { return _currentTemp; };
    };
}
#endif  //!__TEMP_READER__H__