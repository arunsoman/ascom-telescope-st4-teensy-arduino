#include <Arduino.h>
#include <Axis.h>
#include <St4.h>

#define DEBUGGER Serial2
#define RA_PLUS 2
#define RA_MINUS 5
#define DEC_PLUS 3
#define DEC_MINUS 4

void printRA_DEC(){
  DEBUGGER.print("RA: plusPin=");
  DEBUGGER.print(RA_PLUS);
  DEBUGGER.print(" minusPin=");
  DEBUGGER.println(RA_MINUS);

  DEBUGGER.print("DEC: plusPin=");
  DEBUGGER.print(DEC_PLUS);
  DEBUGGER.print(" minusPin=");
  DEBUGGER.println(DEC_MINUS);

}
class Axis ra(RA_PLUS, RA_MINUS);
class Axis dec(DEC_PLUS, DEC_MINUS);

class St4 st4(ra, dec);

void setup() {
  Serial.begin(57600);
  DEBUGGER.begin(500000);
  //Wait for serial port to connect. Needed for Leonardo only
  while (!Serial);
  while (!DEBUGGER);
  st4.setup();
  printRA_DEC();
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