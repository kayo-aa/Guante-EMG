#include <WiFi.h>
#include <WebServer.h>

  const char* ssid     = "ssid";
  const char* password = "password";
  
  bool useStaticIP = true;
  
  IPAddress ip(192, 168, 1, 200);
  IPAddress gateway(192, 168, 1, 1);
  IPAddress subnet(255, 255, 255, 0);

  WebServer server(80);

  
void setup() {
  
  Serial.begin(115200);
  
  ConnectWiFi_STA(useStaticIP);
  
  InitServer();

}

void loop() {
  server.handleClient();
}


void ConnectWiFi_STA(bool doIUseStaticIP)
{
   Serial.println("");
   WiFi.mode(WIFI_STA);
   WiFi.begin(ssid, password);
   if(doIUseStaticIP) WiFi.config(ip, gateway, subnet);
   while (WiFi.status() != WL_CONNECTED) 
   { 
     delay(100);  
     Serial.print('.'); 
   }
}

void InitServer()
{
   // Ruteo para '/'
   server.on("/", handleRoot);
 
   // Ruteo para '/inline' usando función lambda
   server.on("/inline", []() {
      server.send(200, "text/plain", "Esto tambien funciona");
   });
 
   // Ruteo para URI desconocida
   server.onNotFound(handleNotFound);
 
   // Iniciar servidor
   server.begin();
   Serial.println("HTTP server started");
}

void handleRoot() 
{
   server.send(200, "text/plain", "Hola mundo!");
}
 
// Funcion que se ejecutara en URI desconocida
void handleNotFound() 
{
   server.send(404, "text/plain", "Not found");
}
