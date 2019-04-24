#include <Arduino.h>
#include <TinyGPS.h>

#include <Axis.h>
#include <St4.h>
#include <Tele.h>

#define _l Serial2

#define RA_PLUS 2
#define RA_MINUS 5
#define DEC_PLUS 3
#define DEC_MINUS 4

#define GPS_POWER_PIN 18

Tele tele;

TinyGPS gps;
HardwareSerial Uart = HardwareSerial();
bool gpsLocked = false;
long lat = 0, lon = 0, alt = 0;
unsigned long age, date, time, chars;
int year;
byte month, day, hour, minute, second, hundredths;
unsigned short sentences, failed;
void gpsdump(TinyGPS &gps)
{
  gps.get_position(&lat, &lon, &age);
  _l.print("Lat/Long(10^-5 deg): "); _l.print(lat); _l.print(", "); _l.println(lon);

  gps.get_datetime(&date, &time, &age);
  _l.print("Date(ddmmyy): "); _l.print(date); _l.print(" Time(hhmmsscc): ");
  _l.println(time);
  
  gps.stats(&chars, &sentences, &failed);
  _l.print("Stats: characters: "); _l.print(chars); _l.print(" sentences: ");
  _l.print(sentences); _l.print(" failed checksum: "); _l.println(failed);
  alt=gps.altitude();
  _l.print("Alt(cm): "); _l.print(alt);
}

void printRA_DEC() {
  _l.print("RA: plusPin="); _l.print(RA_PLUS); _l.print(" minusPin="); _l.println(RA_MINUS);

  _l.print("DEC: plusPin="); _l.print(DEC_PLUS); _l.print(" minusPin="); _l.println(DEC_MINUS);
}
class Axis ra(RA_PLUS, RA_MINUS);
class Axis dec(DEC_PLUS, DEC_MINUS);

class St4 st4(ra, dec);

void setup() {
  pinMode(GPS_POWER_PIN, OUTPUT);
  digitalWrite(GPS_POWER_PIN, HIGH);
  Serial.begin(57600);
  _l.begin(500000);
  while (!Serial)
    ;
  while (!_l)
    ;

  Uart.begin(4800);
  _l.print("Testing TinyGPS library v. ");
  _l.println(TinyGPS::library_version());

  st4.setup();
  printRA_DEC();
}

void loop() {
  if (gpsLocked == false) {
    bool newdata = false;
    unsigned long start = millis();

    // Every 5 seconds we print an update
    while (millis() - start < 5000) {
      if (Uart.available()) {
        char c = Uart.read();
        // Serial.print(c);  // uncomment to see raw GPS data
        if (gps.encode(c)) {
          newdata = true;
          // break;  // uncomment to print new data immediately!
        }
      }
    }
    if (newdata) {
      gpsdump(gps);
      if(lat != 0 && lon != 0){
        gpsLocked = true;
        digitalWrite(GPS_POWER_PIN, LOW);//Kill GPS module
      }
    }
  }

  if (Serial.available() > 0) {
    String opCode = Serial.readStringUntil('#');
    String response = st4.process(opCode);
    if (response != st4.OK) {
      response = tele.execute(opCode);
    }
    Serial.print(response);

  }
}