/*
 * @brief Fungsi untuk setup sensor
 * @parameter None
 * @return Void
 */
void sensory_setup(){
    SENSOR_SCT013.current(PIN_SENSOR_SCT013, 111.1);
}

/*
 * @brief Fungsi abstraksi untuk mendapatkan data sensor
 * SCT-013
 * @parameter None
 * @return Struct DATA
 */
void sensory_get_sensor(SCT013 &sct013){
  float tegangan = 230.0;
  float arus = SENSOR_SCT013.calcIrms(1480);
  float watt = arus * tegangan;

  sct013.tegangan = tegangan;
  sct013.arus = arus;
  sct013.watt = watt;
}
