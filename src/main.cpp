#include <Arduino.h>
#include <TinyGPS.h>

#include <Axis.h>
#include <St4.h>
#include <Tele.h>

#define _sl(x) Serial.print("$$");Serial.print(x);
#define _l(x) Serial.print(x);
#define _el(x) Serial.print(x);Serial.print("#");

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
  _sl("Lat/Long(10^-5 deg): "); _l(lat); _l(", "); _el(lon);

  gps.get_datetime(&date, &time, &age);
  _sl("Date(ddmmyy): "); _l(date); _l(" Time(hhmmsscc): ");
  _el(time);
  
  gps.stats(&chars, &sentences, &failed);
  _sl("Stats: characters: "); _l(chars); _l(" sentences: ");
  _sl(sentences); _l(" failed checksum: "); _el(failed);
  alt=gps.altitude();
  _sl("Alt(cm): "); _el(alt);
}

void printRA_DEC() {
  _sl("RA: plusPin="); _l(RA_PLUS); _l(" minusPin="); _el(RA_MINUS);

  _sl("DEC: plusPin="); _l(DEC_PLUS); _l(" minusPin="); _el(DEC_MINUS);
}
class Axis ra(RA_PLUS, RA_MINUS);
class Axis dec(DEC_PLUS, DEC_MINUS);

class St4 st4(ra, dec);

void setupGPS(){
  pinMode(GPS_POWER_PIN, OUTPUT);
  digitalWrite(GPS_POWER_PIN, HIGH);
  Uart.begin(4800);
  _sl("Testing TinyGPS library v. "); _el(TinyGPS::library_version());
}
void setup() {
  
  Serial.begin(57600);
  while (!Serial);

  setupGPS();
  st4.setup();
  printRA_DEC();
  tele.init();
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
    _sl("request: {"); _l(opCode); _l("}, response: { "); _l(response);  _el("}");
  }
}