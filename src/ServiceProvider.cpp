#include "ServiceProvider.h"
#include "LcdDisplay.h"

using namespace PotStill;

ServiceProvider::ServiceProvider(Interfaces::IHeater* heater, Interfaces::IRepository* repo, Interfaces::IWebServer* webServer, Interfaces::ITempReader* tempReader) :
    _repo(repo),
    _heater(heater),
    _webServer(webServer),
    _tempReader(tempReader)
{
    _lcd = new LcdDisplay();
    _lcd->Clear();
}