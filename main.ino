#include ".\src\FSM.h"
#include ".\src\Control\Heater.h"
#include ".\src\Control\TempReader.h"
#include ".\src\Repository.h"
#include ".\src\Control\WebServer.h"
#include ".\src\ServiceProvider.h"

PotStill::Repository* repository;
Control::Heater* heater;
Control::TempReader* tempReader;
Control::WebServer* webServer;
PotStill::ServiceProvider* provider;
StateMachine::FSM* display;

void setup()
{
  // Setup serial port
  Serial.begin(115200);  
  repository = new PotStill::Repository();
  tempReader = new Control::TempReader();
  heater = new Control::Heater(tempReader, repository);
  webServer = new Control::WebServer(tempReader, heater);
  Serial.println("Starting5...");
  provider = new PotStill::ServiceProvider(heater, repository, webServer, tempReader); 
  Serial.println("Starting6...");
  display = new StateMachine::FSM(provider);
  Serial.println("Starting7...");
}

void loop(void) 
{ 
  unsigned long now = millis(); 
  display->Loop(now);
  heater->Loop(now);
  tempReader->Loop(now);
  webServer->Loop(now);
}