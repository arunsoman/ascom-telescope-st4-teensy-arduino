#include "Tele.h"

#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>

Tele::Tele(/* args */)
{
}

Tele::~Tele()
{
}

String Tele::alt = "t";
String Tele::lat = "t";
String Tele::lng = "t";

String Tele::roll = "0";
String Tele::pitch = "0";
String Tele::yaw = "0";

Adafruit_BNO055 Tele::bno = Adafruit_BNO055(55);

void Tele::init(){
Tele::bno.begin();
}


void Tele::readGpsData()
{
    alt = "10";
    lat = "9.6836";
    lng = "76.3365";
}

void Tele::readRollYawPitchData()
{
    sensors_event_t event;
    bno.getEvent(&event);
    pitch = String(event.orientation.y);
    yaw = String(event.orientation.z);
}
String Tele::Echo_f(String cmd) { return cmd; }
String Tele::AlignmentMode_f(String cmd) { return "2"; }
String Tele::Altitude_f(String cmd)
{
    readRollYawPitchData();
    return pitch;
}
String Tele::ApertureArea_f(String cmd) { return cmd; }
String Tele::ApertureDiameter_f(String cmd) { return cmd; }
String Tele::AtHome_f(String cmd) { return cmd; }
String Tele::AtPark_f(String cmd) { return cmd; }
String Tele::Azimuth_f(String cmd)
{
    readRollYawPitchData();
    return yaw;
}
String Tele::CanFindHome_f(String cmd) { return cmd; }
String Tele::CanPark_f(String cmd) { return cmd; }
String Tele::CanPulseGuide_f(String cmd) { return cmd; }
String Tele::CanSetDeclinationRate_f(String cmd) { return cmd; }
String Tele::CanSetGuideRates_f(String cmd) { return cmd; }
String Tele::CanSetPark_f(String cmd) { return cmd; }
String Tele::CanSetPierSide_f(String cmd) { return cmd; }
String Tele::CanSetRightAscensionRate_f(String cmd) { return cmd; }
String Tele::CanSetTracking_f(String cmd) { return cmd; }
String Tele::CanSlew_f(String cmd) { return cmd; }
String Tele::CanSlewAltAz_f(String cmd) { return cmd; }
String Tele::CanSlewAltAzAsync_f(String cmd) { return cmd; }
String Tele::CanSlewAsync_f(String cmd) { return cmd; }
String Tele::CanSync_f(String cmd) { return cmd; }
String Tele::CanSyncAltAz_f(String cmd) { return cmd; }
String Tele::CanUnpark_f(String cmd) { return cmd; }
String Tele::Connected_f(String cmd) { return cmd; }
String Tele::Declination_f(String cmd) { return cmd; }
String Tele::DeclinationRate_f(String cmd) { return cmd; }
String Tele::Description_f(String cmd) { return cmd; }
String Tele::DoesRefraction_f(String cmd) { return cmd; }
String Tele::DriverInfo_f(String cmd) { return cmd; }
String Tele::DriverVersion_f(String cmd) { return cmd; }
String Tele::EquatorialSystem_f(String cmd) { return cmd; }
String Tele::FocalLength_f(String cmd) { return cmd; }
String Tele::GuideRateDeclination_f(String cmd) { return cmd; }
String Tele::GuideRateRightAscension_f(String cmd) { return cmd; }
String Tele::InterfaceVersion_f(String cmd) { return cmd; }
String Tele::IsPulseGuiding_f(String cmd) { return cmd; }
String Tele::Name_f(String cmd) { return cmd; }
String Tele::RightAscension_f(String cmd) { return cmd; }
String Tele::RightAscensionRate_f(String cmd) { return cmd; }
String Tele::SideOfPier_f(String cmd) { return cmd; }
String Tele::SiderealTime_f(String cmd) { return cmd; }
String Tele::SiteElevation_f(String cmd)
{
    readGpsData();
    return alt;
}
String Tele::SiteLatitude_f(String cmd)
{
    readGpsData();
    return lat;
}
String Tele::SiteLongitude_f(String cmd)
{
    readGpsData();
    return lng;
}
String Tele::Slewing_f(String cmd) { return cmd; }
String Tele::SlewSettleTime_f(String cmd) { return cmd; }
String Tele::SupportedActions_f(String cmd) { return cmd; }
String Tele::TargetDeclination_f(String cmd) { return cmd; }
String Tele::TargetRightAscension_f(String cmd) { return cmd; }
String Tele::Tracking_f(String cmd) { return cmd; }
String Tele::TrackingRate_f(String cmd) { return cmd; }
String Tele::TrackingRates_f(String cmd) { return cmd; }
String Tele::UTCDate_f(String cmd) { return cmd; }
