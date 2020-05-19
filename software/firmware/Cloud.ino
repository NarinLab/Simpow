/*
 * @brief Fungsi untuk setup cloud integration
 * @param None
 * @return None
 */
void cloud_setup(){
  ThingSpeak.begin(client);
}

/* 
 * @brief Fungsi untuk post data ke cloud
 * @param None
 * @return None
 */
void cloud_publish(){
  SCT013 sct013;
  sensory_get_sensor(sct013);

  
  ThingSpeak.setField(1, sct013.tegangan);
  ThingSpeak.setField(2, sct013.arus);
  ThingSpeak.setField(3, sct013.watt);
  ThingSpeak.setField(4, WiFi.RSSI());

  int errorCode = ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
  if(errorCode == 200){
    Log.notice(F("Berhasil publish data ke cloud." CR));
  }
  else{
    Log.error(F("Gagal publish data ke cloud: %d" CR), errorCode);
  }
  
}
