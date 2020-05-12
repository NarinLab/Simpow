/*
 * Nama:
 * NIM:
 */
#include <WiFi.h>
#include <ArduinoLog.h>
#include "header.h"
#include "EmonLib.h"

/* START DEKLARASI VARIABLE GLOBAL */
const char* SSID = "NAMA WIFI";
const char* PWD = "PASS WIFI";
#define PIN_SENSOR_SCT013 34
/* STOP DEKLARASI VARIABLE GLOBAL */

/* START INSTANSIASI OBJEK  */
EnergyMonitor SENSOR_SCT013;
/* STOP INSTANSIASI OBJEK  */

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Log.begin(LOG_LEVEL_VERBOSE, &Serial);

  networking_setup();
  sensory_setup();
  scheduler_setup();
}

void loop() {
  // put your main code here, to run repeatedly:
  scheduler_loop();
}
