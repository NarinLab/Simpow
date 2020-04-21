/*
 * @brief Fungsi setup scheduler
 * @parameter None
 * @return Void
 */
void scheduler_setup(){}

/* @brief Fungsi untuk kirim data ke Cloud
 * @parameter None
 * @return Void
 */
void scheduler_send(){}

/* @brief Fungsi untuk kirim/cetak data ke serial
 * @parameter None
 * @return Void
 */
void scheduler_print(){
  SCT013 sct013;
  // Gunakan variable reference sebagai parameter
  sensory_get_sensor(sct013);

  Log.notice(F("Tegangan: %.2f VAC" CR), sct013.tegangan);
  Log.notice(F("Arus: %.2f Ampere" CR), sct013.arus);
  Log.notice(F("Watt: %.2f Watt" CR), sct013.watt);
}

/* @brief Fungsi loop untuk menjalankan setiap 
 * fungsi scheduler secara periodik
 * @parameter None
 * @return Void
 */
long SCHDULER_LAST_RUN_SHORT  = 0; // Counter jangka pendek (30 detik)
void scheduler_loop(){
  long NOW = millis();

  // RUN_SHORT (Setiap 30 Detik)
  if( (NOW - SCHDULER_LAST_RUN_SHORT) > 30000){
     // Eksekusi fungsi yg akan dijalankan setiap 30 detik
     scheduler_print();

     // Reset counter RUN_SHORT dari 0 lagi
     SCHDULER_LAST_RUN_SHORT = NOW;
  }
}
