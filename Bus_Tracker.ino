#include<SoftwareSerial.h>
#include<ESP8266WiFi.h>
#include<BlynkSimpleEsp8266.h>
#include<TinyGPS++.h>
#define BLYNK_PRINT Serial

static const int TXPin=5,RXPin=4;//GPIO 4=D2(connect TX of GPS) and GPIO 5=D1(connect RX of GPS)
static const uint32_t GPSbaud=9600;//Baud rate should be 9600 else assign the value 4800

WidgetMap mymap(V0);//Virtual Pin of Map Widget
TinyGPSPlus gps;//TinyGPS++ object
SoftwareSerial ss(RXPin,TXPin);
BlynkTimer t;
float spd,sats;//Variable to store the speed and no.of stellites responses
String bearing;//Variable to store orientation of the GPS

char authen[]="29c22b2c027f44b5b68bcc463f90bff6";//Authentication key from Blynk
char SSid[]="Moto";//Name of the network
char Pass[]="steamcsgo";//Password of the network

unsigned int move_index=1;//Fixed location for now

void setup(){
 Serial.begin(115200);
 Serial.println();
 ss.begin(GPSbaud);
 Blynk.begin(authen,SSid,Pass);
 t.setInterval(500L,checkGPS);//Every 5s check if GPS is connected 
}

void checkGPS(){
  if(gps.charsProcessed()<10)
  {
    Serial.println(F("No GPS detected."));
    Blynk.virtualWrite(V4,"GPS Error");//IF GPS is not detected
  }
}

void loop(){
  while(ss.available()>0){
    if(gps.encode(ss.read()))
      displayInfo();
  }
  Blynk.run();
  t.run();
}

void displayInfo(){
  if(gps.location.isValid()){
    float lati=(gps.location.lat());
    float longi=(gps.location.lng());//Storing lat. and lon.
    Serial.print("LAT: ");
    Serial.println(lati,6);
    Serial.print("LONG: ");
    Serial.println(longi,6);
    Blynk.virtualWrite(V1,String(lati,6));
    Blynk.virtualWrite(V2,String(longi,6));
    mymap.location(move_index,lati,longi,"GPS_Location");
    spd=gps.speed.kmph();//Get Speed
    bearing=TinyGPSPlus::cardinal(gps.course.value());//Get the direction
    sats=gps.satellites.value();//Get number of satellites
    Blynk.virtualWrite(V3,spd);
    Blynk.virtualWrite(V4,sats);
    Blynk.virtualWrite(V5,bearing);
  }
  Serial.println();
}
