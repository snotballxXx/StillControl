#ifndef __PUMP__H__
#define __PUMP__H__

#include "../Interfaces/IHeater.h"

namespace Interfaces
{
    class IRepository;
    class ITempReader;
}

namespace Control
{    
    class Heater : public Interfaces::IHeater
    {
        Interfaces::ITempReader* _tempReader;
        Interfaces::IRepository* _repository;
        bool _heaterOn;
        bool _inMark;
        unsigned long _lastSwitchTime;

        public:
        Heater(Interfaces::ITempReader* tempReader, Interfaces::IRepository* repository);
        void Loop(unsigned long now);
        bool IsHeaterOn() { return _heaterOn; };
    };
}
#endif  //!__PUMP__H__