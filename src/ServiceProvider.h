#ifndef __SERVICEPROVIDER__H__
#define __SERVICEPROVIDER__H__

#include "./Interfaces/IServiceProvider.h"

namespace PotStill
{
    class ServiceProvider : public Interfaces::IServiceProvider
    {
        Interfaces::IHeater* _heater;
        Interfaces::ITempReader* _tempReader;
        Interfaces::IRepository* _repo;
        Interfaces::ILcdDisplay* _lcd;
        Interfaces::IWebServer* _webServer;

        public:
        ServiceProvider(Interfaces::IHeater* heater, Interfaces::IRepository* repo, Interfaces::IWebServer* webServer, Interfaces::ITempReader* tempReader);
        Interfaces::IHeater* GetHeater() { return _heater; };
        Interfaces::IRepository* GetRepository() { return _repo; };   
        Interfaces::ILcdDisplay* GetLcdDisplay() { return _lcd; }; 
        Interfaces::IWebServer* GetWebServer() { return _webServer; };
        Interfaces::ITempReader* GetTempReader() { return _tempReader; };
    };
}
#endif  //!__SERVICEPROVIDER__H__