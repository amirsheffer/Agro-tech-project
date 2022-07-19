// #include <ESP8266WiFi.h>
#include <WiFi.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <Adafruit_SHT31.h>
#include "ThingSpeak.h"
#include <Math.h>
unsigned long myChannelNumber = 1774830;

const char * myWriteAPIKey = "myWriteAPIKey"; //add your api write key

const char* ssid = "wifi"; // your wifi SSID name
const char* password = "password" ;// wifi pasword
 
const char* server = "api.thingspeak.com";

WiFiClient client;
#define ONE_WIRE_BUS 15
// Setup a oneWire instance to communicate with a OneWire device
OneWire oneWire(ONE_WIRE_BUS);
// Pass our oneWire reference to Dallas Temperature sensor 
DallasTemperature sensors(&oneWire);

DeviceAddress sensor1 = { 0x28, 0xB6, 0x21, 0x11, 0x0, 0x0, 0x0, 0x29 }; // adress for DS18B20 sensor

Adafruit_SHT31 sht31 = Adafruit_SHT31();
 
void setup() {
  Serial.begin(9600);
  WiFi.disconnect();
  delay(10);
  WiFi.begin(ssid, password);

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

    ThingSpeak.begin(client);
 
  WiFi.begin(ssid, password);
  
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("NodeMcu connected to wifi...");
  Serial.println(ssid);
  Serial.println();
  bool status;
  
if (! sht31.begin(0x44))
  {
    Serial.println("Couldn't find SHT31");
    while (1) delay(1);
  }
sensors.begin();
 
  Serial.println();
}


 
void loop() {
  printValues();
  float tmp = sensors.getTempC(sensor1);
  float tmp2 = sht31.readTemperature();
  float RH2 = sht31.readHumidity();
  float svp2 = 610.7 * (pow(10, (7.5*sht31.readTemperature()/(237.3+sht31.readTemperature()))));  
  float vpd2 = (((100 - sht31.readHumidity())/100)*svp2)/1000;
 // set fields for thingspeak data
  ThingSpeak.setField(1,tmp);
  ThingSpeak.setField(2,tmp2);
  ThingSpeak.setField(3,RH2);
  ThingSpeak.setField(4,vpd2);
  ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);

  Serial.println("uploaded to Thingspeak server....");

  client.stop();
 
  Serial.println("Waiting to upload next reading...");
  Serial.println();
  // thingspeak needs minimum 15 sec delay between updates

 
  
  delay(1000);
}
void printValues() {
  
  
  Serial.print("Temperature sht = ");
  Serial.print(sht31.readTemperature());
  Serial.println(" *C");
 

  Serial.print("Humidity sht = ");
  Serial.print(sht31.readHumidity());
  Serial.println(" %");
  Serial.print("Requesting temperatures...");
  sensors.requestTemperatures(); // Send the command to get temperatures
  Serial.println("DONE");
  
  Serial.print("Sensor 1(*C): ");
  Serial.print(sensors.getTempC(sensor1));
  Serial.println();
}
