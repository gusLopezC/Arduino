#include <SPI.h> 
#include <Dhcp.h>
#include <Dns.h>
#include <Ethernet2.h>
#include <EthernetClient.h>
#include <EthernetServer.h>
#include <EthernetUdp2.h>
#include <Twitter.h>
#include <util.h>

#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#define DHTTYPE DHT11  
const int DHTPin = 5;     // what digital pin we're connected to
DHT dht(DHTPin, DHTTYPE);


byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(192,168,1,70); 
EthernetServer server(80); 
 
void setup()
{
  Serial.begin(9600);
  Ethernet.begin(mac, ip);
  server.begin();
  Serial.print("server is at ");
  Serial.println(Ethernet.localIP());
}
 
void loop(){
  EthernetClient client = server.available(); 


  delay(2000);
 
   // Reading temperature or humidity takes about 250 milliseconds!
   float h = dht.readHumidity();
   float t = dht.readTemperature();
 
   if (isnan(h) || isnan(t)) {
      Serial.println("Failed to read from DHT sensor!");
      return;
   }

   
  
  if (client) {
    Serial.println("new client");
    boolean currentLineIsBlank = true;
    String cadena=""; 
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        Serial.write(c);
        cadena.concat(c);
         
        if (c == '\n' && currentLineIsBlank) {
 
            
            client.println("HTTP/1.1 200 OK");
            client.println("Content-Type: text/html");
            client.println();
 
            
            client.println("<html>");
            client.println("<head>");
            client.println("</head>");
            client.println("<body>");
            client.println("<h1 align='center'>Arduino Ethernet Shield</h1><h3 align='center'>Equipo 2</h3><h5 align='center'>Sensor de humedad DTH22</h5>");
           
            client.println("<div style='text-align:center;'>");
            client.println("<h5> Temperatura </h5>");
            client.print(t);
            client.println("<br/>");
            client.println("<h5> Humedad </h5>");
            client.print(h);
            client.println("<br/>");
            
            client.println("</body>");
            client.println("</html>");
            break;
        }
        if (c == '\n') {
          currentLineIsBlank = true;
        }
        else if (c != '\r') {
          currentLineIsBlank = false;
        }
      }
    }
    
    delay(1);
    client.stop();
  }
}
