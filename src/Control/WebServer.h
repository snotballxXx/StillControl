#ifndef __WEB_SERVER__H__
#define __WEB_SERVER__H__

#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include "../Interfaces/IWebServer.h"

namespace Interfaces
{
    class ITempReader;
    class IHeater;
}

namespace Control
{    
    class WebServer : public Interfaces::IWebServer
    {
        Interfaces::ITempReader* _tempReader;
        Interfaces::IHeater* _heater;
        ESP8266WebServer* _webserver;
        String _ipAddress;

        public:
        WebServer(Interfaces::ITempReader* tempReader, Interfaces::IHeater* heater);
        void Loop(unsigned long now);

        static void MetricsPage();
        static void RootPage();
        static void NotfoundPage();
        static WebServer* _instance;

        String GetIpAddress() { return _ipAddress; };
    };
}
#endif  //!__WEB_SERVER__H__