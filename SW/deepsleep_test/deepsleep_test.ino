// Must be disabled USB CDC On Boot

#define SLEEP_SEC 15         // Measurement interval (seconds)
#define POWER 47

void setup(void)
{
  Serial.begin(115200);
  pinMode(POWER, OUTPUT); 
  digitalWrite(POWER, HIGH); // enable power supply for ePaper and uSup
  delay(500);

  goToSleep();
}

void loop(void) 
{

}

void goToSleep(){

  Serial.println("I'm mot sleeping");
  delay(3000);
  Serial.println("going to sleep 15 sek");
  digitalWrite(POWER, LOW); // disable power supply for ePaper
  // ESP Deep Sleep 
  Serial.println("ESP in sleep mode");
  Serial.flush(); 
  esp_sleep_enable_timer_wakeup(SLEEP_SEC * 1000000);
  delay(200);
  esp_deep_sleep_start();
}
