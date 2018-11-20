#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>

Servo servo;

// Change this section based on your Blynk project
char auth[] = "dd3ff8e311424e0b8e3640c58b60187d";

// Change this section base on your hotspot device 
char ssid[] = "yourssid";
char pass[] = "yourpassword";

void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);

  // NodeMCU D8 pin
  servo.attach(15);
}

void loop()
{
  Blynk.run();
}

BLYNK_WRITE(V1)
{
  servo.write(param.asInt());
}

BLYNK_WRITE(V2)
{
  servo.write(0);
}

BLYNK_WRITE(V3)
{
  servo.write(90);
}
