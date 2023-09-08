#ifndef __ISERVICEPROVIDER__H__
#define __ISERVICEPROVIDER__H__

namespace Interfaces
{
    class IHeater;
    class IRepository;
    class ILcdDisplay;
    class IWebServer;
    class ITempReader;

    class IServiceProvider 
    {
        public:
        virtual IHeater* GetHeater() = 0;
        virtual IRepository* GetRepository() = 0;
        virtual ILcdDisplay* GetLcdDisplay() = 0;
        virtual IWebServer* GetWebServer() = 0;
        virtual ITempReader* GetTempReader() = 0;
    };
}
#endif  //!__ISERVICEPROVIDER__H__