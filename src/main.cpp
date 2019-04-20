#include <Arduino.h>
#include <Axis.h>
#include <St4.h>

class Axis ra(
2,//RA+ pin
5);//RA- pin
class Axis dec(
3,//DEC+ pin
4);//DEC- pin

class St4 st4(ra, dec);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(57600);
  //Wait for serial port to connect. Needed for Leonardo only
  while (!Serial);
  st4.setup();
}

void loop() {
  if(Serial.available() > 0){
    String opCode = Serial.readStringUntil('#');
    String response = st4.process(opCode);
    if(response == st4.OK){
      Serial.print(response);
    }
  }
}