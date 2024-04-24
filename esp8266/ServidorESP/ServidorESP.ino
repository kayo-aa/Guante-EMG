#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
/**El ESP va a recibirun solo dato. Si se quiere recibir el de la eeprom, debe ser antes de realizar una medicion.
 * Si luego de eso se mide la mano, la medicion no se va a visualizar.
 * Lo otro que puede pasar es que el usuario primero mida. De ser así, automaticamente se envian los datos a 
 * la página. Si se desea visualizar la eeprom, tampoco se va a poder.
 * Para remediar esto, el usuario debe actualizar la página.
 * 
*/

const char *ssid = "ProyectosTecnologicos";
const char *password = "proy.Tec";
const char *hostname = "ESP8266_1";
float datosGuante;
String JSON = "{";

IPAddress ip(192, 168, 1, 200);
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 255, 0);

/*END CONFIG*/

ESP8266WebServer server(80);

void createJSON()
{
  int i = 0;
  Serial.println("Entre a la funcion json");
  while (i < 5)
  {
    if (Serial.available())
    {
      datosGuante = Serial.parseFloat();
      JSON.concat("'");
      
      switch(i){
        case 0:
          JSON.concat("a");
          break;
        case 1:
          JSON.concat("b");
          break;
        case 2:
          JSON.concat("c");
          break;
        case 3:
          JSON.concat("d");
          break;
        case 4:
          JSON.concat("e");
          break;
      }
      
      JSON.concat("': ");
      JSON.concat(datosGuante);
      JSON.concat(", ");
      i++;
    }
  }
}

void handleNotFound()
{
  server.send(404, "text/plain", "");
}

void InitServer()
{
  createJSON();
  Serial.print(JSON);
  // Ruteo para uri '/' usando función lambda
  server.on("/", [](){
    server.send(200, "text/json", JSON);
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
  if (useStaticIP)
    WiFi.config(ip, gateway, subnet);
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
  while (!WiFi.softAP(ssid, password))
  {
    Serial.println(".");
    delay(100);
  }
  if (useStaticIP)
    WiFi.softAPConfig(ip, gateway, subnet);

  Serial.println("");
  Serial.print("Iniciado AP:\t");
  Serial.println(ssid);
  Serial.print("IP address:\t");
  Serial.println(WiFi.softAPIP());
}

void setup()
{
  Serial.begin(57600);

  Serial.setTimeout(50);
  ConnectWiFi_STA();
  
  int j = 0;
  while(j < 2){
    float datoBasura = 0;
    datoBasura = Serial.parseFloat();
    if(datoBasura == 200){
      j++;
    }
  }

  InitServer();
}

void loop()
{
  server.handleClient();
}
