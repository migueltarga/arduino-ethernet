#include <UIPEthernet.h>
 
EthernetServer server = EthernetServer(80);

int sensor1 = 8;
int sensor2 = 9;
unsigned long timeS1 = 0, timeS2 = 0;
unsigned long dif;
long int nPessoas = 0;

 
void setup()
{
	pinMode(sensor1, INPUT);
	pinMode(sensor2, INPUT);

	Serial.begin(9600);

	uint8_t mac[6] = {0x00,0x01,0x02,0x03,0x04,0x05};
	IPAddress myIP(192,168,0,25);
	Ethernet.begin(mac,myIP);
	server.begin();
}
 
void loop()
{
	if (!digitalRead(sensor1))
	{
    	timeS1 = millis(); 
    }
    if (!digitalRead(sensor2))
    {
    	timeS2 = millis(); 
    }

    dif = timeS2 - timeS1;

    dif = timeS2 - timeS1;
    if(dif >= 500 && dif <= 1500)
    {
       timeS1 = timeS2 = 0;
       nPessoas++;
   }

	size_t size;
 
	if (EthernetClient client = server.available())
	{
 		while((size = client.available()) > 0)
 		{
			uint8_t* msg = (uint8_t*)malloc(size);
			size = client.read(msg,size);
			Serial.write(msg,size);
			free(msg);
		}
		client.println(nPessoas);
		client.stop();
	}

	delay(10);

}
