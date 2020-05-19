/*
 * Nama:
 * NIM:
 */
#include <WiFi.h>
#include <ArduinoLog.h>
#include "header.h"
#include "EmonLib.h"
#include "ThingSpeak.h"
#include "secret.h"

/* START DEKLARASI VARIABLE GLOBAL */
#define PIN_SENSOR_SCT013 34
#define TEGANGAN_PLN 247.0
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
