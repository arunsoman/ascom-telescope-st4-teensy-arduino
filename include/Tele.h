#ifndef TELE_H
#define TELE_H

#include <Arduino.h>

#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>

class Tele
{

  typedef String (*fptr[54])(String s);

private:
  /* data */
  static String Echo_f(String);
  static String AlignmentMode_f(String);
  static String Altitude_f(String);
  static String ApertureArea_f(String);
  static String ApertureDiameter_f(String);
  static String AtHome_f(String);
  static String AtPark_f(String);
  static String Azimuth_f(String);
  static String CanFindHome_f(String);
  static String CanPark_f(String);
  static String CanPulseGuide_f(String);
  static String CanSetDeclinationRate_f(String);
  static String CanSetGuideRates_f(String);
  static String CanSetPark_f(String);
  static String CanSetPierSide_f(String);
  static String CanSetRightAscensionRate_f(String);
  static String CanSetTracking_f(String);
  static String CanSlew_f(String);
  static String CanSlewAltAz_f(String);
  static String CanSlewAltAzAsync_f(String);
  static String CanSlewAsync_f(String);
  static String CanSync_f(String);
  static String CanSyncAltAz_f(String);
  static String CanUnpark_f(String);
  static String Connected_f(String);
  static String Declination_f(String);
  static String DeclinationRate_f(String);
  static String Description_f(String);
  static String DoesRefraction_f(String);
  static String DriverInfo_f(String);
  static String DriverVersion_f(String);
  static String EquatorialSystem_f(String);
  static String FocalLength_f(String);
  static String GuideRateDeclination_f(String);
  static String GuideRateRightAscension_f(String);
  static String InterfaceVersion_f(String);
  static String IsPulseGuiding_f(String);
  static String Name_f(String);
  static String RightAscension_f(String);
  static String RightAscensionRate_f(String);
  static String SideOfPier_f(String);
  static String SiderealTime_f(String);
  static String SiteElevation_f(String);
  static String SiteLatitude_f(String);
  static String SiteLongitude_f(String);
  static String Slewing_f(String);
  static String SlewSettleTime_f(String);
  static String SupportedActions_f(String);
  static String TargetDeclination_f(String);
  static String TargetRightAscension_f(String);
  static String Tracking_f(String);
  static String TrackingRate_f(String);
  static String TrackingRates_f(String);
  static String UTCDate_f(String);

  fptr cap = {
      Echo_f,
      AlignmentMode_f,
      Altitude_f,
      ApertureArea_f,
      ApertureDiameter_f,
      AtHome_f,
      AtPark_f,
      Azimuth_f,
      CanFindHome_f,
      CanPark_f,
      CanPulseGuide_f,
      CanSetDeclinationRate_f,
      CanSetGuideRates_f,
      CanSetPark_f,
      CanSetPierSide_f,
      CanSetRightAscensionRate_f,
      CanSetTracking_f,
      CanSlew_f,
      CanSlewAltAz_f,
      CanSlewAltAzAsync_f,
      CanSlewAsync_f,
      CanSync_f,
      CanSyncAltAz_f,
      CanUnpark_f,
      Connected_f,
      Declination_f,
      DeclinationRate_f,
      Description_f,
      DoesRefraction_f,
      DriverInfo_f,
      DriverVersion_f,
      EquatorialSystem_f,
      FocalLength_f,
      GuideRateDeclination_f,
      GuideRateRightAscension_f,
      InterfaceVersion_f,
      IsPulseGuiding_f,
      Name_f,
      RightAscension_f,
      RightAscensionRate_f,
      SideOfPier_f,
      SiderealTime_f,
      SiteElevation_f,
      SiteLatitude_f,
      SiteLongitude_f,
      Slewing_f,
      SlewSettleTime_f,
      SupportedActions_f,
      TargetDeclination_f,
      TargetRightAscension_f,
      Tracking_f,
      TrackingRate_f,
      TrackingRates_f,
      UTCDate_f,
  };

  static String roll;
  static String pitch;
  static String yaw;
  const String EOM = "#";
  static String alt;
  static String lat;
  static String lng;
  static Adafruit_BNO055 bno;

 

public:
  Tele(/* args */);
  ~Tele();
  static void init();
  static void readGpsData();
  static void readRollYawPitchData();
  String execute(String s)
  {
    int index = s.substring(0, 2).toInt();
    return cap[index](s) + EOM;
  }
  void updateGPS(long&, long&, long&);
};

#endif