#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>


const char* ssid     = "TeleCentro-1ecd";
const char* password = "GJY5KTZZATNK";
const char* hostname = "ESP8266_1";


IPAddress ip(192, 168, 1, 200);
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 255, 0);

/*END CONFIG*/

ESP8266WebServer server(80);


void handleRoot() 
{
   server.send(200, "text/plain", "Hola mundo!");
}

void handleNotFound() 
{
    server.send(404, "text/plain", "");

}

void InitServer()
{
   // Ruteo para '/'
   server.on("/", handleRoot);
 
   // Ruteo para '/inline' usando función lambda
   server.on("/content", []() {
      server.send(200, "text/json", "{\"valor\": \"90%\"}");
   });
 
   // Ruteo para URI desconocida
   server.onNotFound(handleNotFound);
 
   // Iniciar servidor
   server.enableCORS(true);
   server.begin();
   Serial.println("HTTP server started");
}


void ConnectWiFi_STA(bool useStaticIP = false)
{
   Serial.println("");
   WiFi.mode(WIFI_STA);
   WiFi.begin(ssid, password);
   if(useStaticIP) WiFi.config(ip, gateway, subnet);
   while (WiFi.status() != WL_CONNECTED) 
   { 
     delay(100);  
     Serial.print('.'); 
   }
 
   Serial.println("");
   Serial.print("Iniciado STA:\t");
   Serial.println(ssid);
   Serial.print("IP address:\t");
   Serial.println(WiFi.localIP());
}

void ConnectWiFi_AP(bool useStaticIP = false)
{ 
   Serial.println("");
   WiFi.mode(WIFI_AP);
   while(!WiFi.softAP(ssid, password))
   {
     Serial.println(".");
     delay(100);
   }
   if(useStaticIP) WiFi.softAPConfig(ip, gateway, subnet);

   Serial.println("");
   Serial.print("Iniciado AP:\t");
   Serial.println(ssid);
   Serial.print("IP address:\t");
   Serial.println(WiFi.softAPIP());
}


void setup() {
   
   
   Serial.begin(115200);
   
   ConnectWiFi_STA();
 
   InitServer();

}

void loop() {
  server.handleClient();
}
