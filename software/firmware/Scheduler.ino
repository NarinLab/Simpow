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
long SCHDULER_SEND_LAST_RUN  = 0;
void scheduler_send(){
  long NOW = millis();
  if(NOW - SCHDULER_SEND_LAST_RUN > 30000){
    cloud_publish();
    
    SCHDULER_SEND_LAST_RUN = NOW;
  }  
}

/* @brief Fungsi untuk kirim/cetak data ke serial
 * @parameter None
 * @return Void
 */
long SCHDULER_PRINT_LAST_RUN  = 0;
void scheduler_print(){
  long NOW = millis();
  if(NOW - SCHDULER_PRINT_LAST_RUN > 1000){
    SCT013 sct013;
    // Gunakan variable reference sebagai parameter
    sensory_get_sensor(sct013);
  
    Log.notice(F("Tegangan: %F VAC - Arus: %F Ampere - Watt: %F Watt - ICAL: %F - BRES: %F" CR), sct013.tegangan, sct013.arus, sct013.watt, sct013.ical, sct013.burden_res);

    
    SCHDULER_PRINT_LAST_RUN = NOW;
  }
}

/* @brief Fungsi loop untuk menjalankan setiap 
 * fungsi scheduler secara periodik
 * @parameter None
 * @return Void
 */
void scheduler_loop(){
  scheduler_print(); 
  scheduler_send(); 
}
