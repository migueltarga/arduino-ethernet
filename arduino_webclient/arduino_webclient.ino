#include <UIPEthernet.h>

uint8_t mac[6] = {0x00,0x01,0x02,0x03,0x04,0x05};
EthernetClient client;

int sensor1 = 5;
int sensor2 = 10;
String data;

void setup() { 

  	Serial.begin(9600);

	if (Ethernet.begin(mac) == 0) {
		Serial.println("Falha na configuração DHCP"); 
	} else {
                Serial.println("ok");
}
  
  data = "";
}

void loop(){
  
String data = "sensor1=" + String(sensor1) + "&sensor2=" + String(sensor2);        

	if (client.connect("192.168.0.101",80)) {
                Serial.println("-> Conectado");
		client.print("POST /sensor/add.php?"+String(data));
            	client.println(); 
                client.stop();
} 
	if (client.connected()) { 
		client.stop();
	}
	delay(1000);
}