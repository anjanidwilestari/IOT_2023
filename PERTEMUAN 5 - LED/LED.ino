#define LedMerah D1  //D0 pin led merah 
#define LedHijau D2 //D1 pin led hijau 
#define LedBiru D3 //D2 pin led biru

void setup() {
Serial.begin(1000); 
pinMode(LedMerah, OUTPUT);
pinMode(LedHijau, OUTPUT); 
pinMode(LedBiru, OUTPUT); // atur pin digital sebagai output.
}

void RunningLED() { 
 digitalWrite(LedMerah, HIGH); 
 digitalWrite(LedHijau, LOW); 
 digitalWrite(LedBiru, LOW); 
 Serial.println("LED Merah nyala"); 
 delay(1000); 
 
 digitalWrite(LedMerah, LOW); 
 digitalWrite(LedHijau, HIGH); 
 digitalWrite(LedBiru, LOW); 
 Serial.println("LED Hijau nyala"); 
 delay(1000); 
 
 digitalWrite(LedMerah, LOW); 
 digitalWrite(LedHijau, LOW); 
 digitalWrite(LedBiru, HIGH); 
 Serial.println("LED Biru nyala"); 
 delay(1000);

 Serial.println();
}

void loop() {
  RunningLED();
}