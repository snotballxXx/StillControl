#include <arduino.h>
#include "WebServer.h"
#include "../Constants.h"
#include "../Interfaces/ITempReader.h"
#include "../Interfaces/IHeater.h"

using namespace Control;

WebServer* WebServer::_instance = nullptr;

WebServer::WebServer(Interfaces::ITempReader* tempReader, Interfaces::IHeater* heater) :
    _tempReader(tempReader),
    _heater(heater),
    _ipAddress("N/C")
{
    _webserver = new ESP8266WebServer(WEB_PORT);

    _instance = this;
    //Begin WiFi
    Serial.print("Begin WiFi");
    WiFi.begin(WIFI_SSID, WIFI_PASS);
    while (WiFi.status() != WL_CONNECTED) 
    { 
      Serial.print(".");
      delay(100); 
    }

    // WiFi Connected
    _ipAddress = WiFi.localIP().toString();

    Serial.println(_ipAddress);
    // Start Web Server
    _webserver->on("/", RootPage);
    _webserver->on("/metrics", MetricsPage);
    _webserver->onNotFound(NotfoundPage);
    _webserver->begin();    
}

void WebServer::Loop(unsigned long now)
{
    _webserver->handleClient();
}

// Handle Metrics
void WebServer::MetricsPage() 
{ 
  String temperature = "# HELP temperature_centigrade_float current temperature\n# TYPE temperature_centigrade_float gauge\ntemperature_centigrade_float " + String(_instance->_tempReader->GetTemp()) + "\n";
  String state = "# HELP output_state_int current state of the output\n# TYPE output_state_int gauge\noutput_state_int " + String(_instance->_heater->IsHeaterOn() ? HIGH : LOW);
  temperature.concat(state);
  
  _instance->_webserver->send(200, "text/plain", temperature.c_str()); 
}

void WebServer::RootPage() 
{ 
  _instance->_webserver->send(200, "text/plain", String(_instance->_tempReader->GetTemp()).c_str()); 
}

// Handle 404
void WebServer::NotfoundPage()
{ 
  _instance->_webserver->send(404, "text/plain", "404: Not found"); 
}