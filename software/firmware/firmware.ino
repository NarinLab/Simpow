/*
 * Nama:
 * NIM:
 */
#include "header.h"
#include "secret.h"
#include <WiFi.h>
#include <ArduinoLog.h>
#include "ThingSpeak.h"
#include "EmonLib.h"

/* START DEKLARASI VARIABLE GLOBAL */
#define ESP32 1
#define PIN_SENSOR_SCT013 36
#define TEGANGAN_PLN 225.0
byte SAMLPING_COUNT = 1;
float AREF = 3.290;
int CTTURN = 2000;
float MAX_PEAK_CURR = 100;
float ICAL = 0;
float BURDEN_RES = 0;
/* STOP DEKLARASI VARIABLE GLOBAL */

/* START INSTANSIASI OBJEK  */
EnergyMonitor SENSOR_SCT013;
WiFiClient  client;
/* STOP INSTANSIASI OBJEK  */

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Log.begin(LOG_LEVEL_VERBOSE, &Serial);

  networking_setup();
  sensory_setup();
  cloud_setup();
  scheduler_setup();
}

void loop() {
  // put your main code here, to run repeatedly:
  scheduler_loop();
}
