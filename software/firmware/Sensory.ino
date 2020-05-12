/*
 * @brief Fungsi untuk setup sensor
 * @parameter None
 * @return Void
 */
void sensory_setup(){
    analogReadResolution(12);
    SENSOR_SCT013.current(PIN_SENSOR_SCT013, 30.0);
}

/*
 * @brief Fungsi abstraksi untuk mendapatkan data sensor
 * SCT-013
 * @parameter None
 * @return Struct DATA
 */
void sensory_get_sensor(SCT013 &sct013){
  float tegangan = TEGANGAN_PLN;
  float arus = SENSOR_SCT013.calcIrms(1480);
  float watt = arus * tegangan;

  sct013.tegangan = tegangan;
  sct013.arus = arus;
  sct013.watt = watt;
}
