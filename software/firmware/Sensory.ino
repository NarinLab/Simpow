/*
 * @brief Fungsi untuk setup sensor
 * @parameter None
 * @return Void
 */
void sensory_setup(){
    analogSetPinAttenuation(PIN_SENSOR_SCT013, ADC_11db);
    analogReadResolution(12);
    pinMode(PIN_SENSOR_SCT013, INPUT);

    BURDEN_RES = (AREF * CTTURN) / ( 2.8284 * MAX_PEAK_CURR);
    ICAL = CTTURN / BURDEN_RES; 
    SENSOR_SCT013.current(PIN_SENSOR_SCT013, ICAL);
}

/*
 * @brief Fungsi abstraksi untuk mendapatkan data sensor
 * SCT-013
 * @parameter None
 * @return Struct DATA
 */
void sensory_get_sensor(SCT013 &sct013){
  float arus = 0.0;
  float watt = 0.0;
  for(byte i = 0; i < SAMLPING_COUNT; i++){
    arus += SENSOR_SCT013.calcIrms(1480);
  }
  
  sct013.tegangan = TEGANGAN_PLN;
  sct013.arus = arus / SAMLPING_COUNT;
  sct013.watt = TEGANGAN_PLN * (arus / SAMLPING_COUNT);
  sct013.ical = ICAL;
  sct013.burden_res = BURDEN_RES;
  sct013.rawSampleI = SENSOR_SCT013.getRawSampleI();
}
