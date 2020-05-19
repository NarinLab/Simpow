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
  if(NOW - SCHDULER_PRINT_LAST_RUN > 5000){
    SCT013 sct013;
    // Gunakan variable reference sebagai parameter
    sensory_get_sensor(sct013);
  
    Log.notice(F("Tegangan: %F VAC" CR), sct013.tegangan);
    Log.notice(F("Arus: %F Ampere" CR), sct013.arus);
    Log.notice(F("Watt: %F Watt" CR), sct013.watt);  
    
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
