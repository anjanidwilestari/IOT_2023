#include <Arduino.h>
#include <SimpleDHT.h>
#include <LiquidCrystal_I2C.h>
// #include <RTClib.h>
// #include "RTClib.h"
#include <DS3231.h>

#define pinDHT 7  // SD3 pin signal sensor DHT
#define LedMerah D3
#define LedHijau D6
#define LedBiru D8

LiquidCrystal_I2C lcd(0x27, 16, 2);
// RTC_DS3231 rtc;
DS3231 rtc;

int nilaiSensor;
byte temperature = 0;
byte humidity = 0;
int led = 13;

SimpleDHT11 dht11(D7);  //instan sensor dht11

void CahayaSuhu() {
  int err = SimpleDHTErrSuccess;

  if ((err = dht11.read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
    Serial.print("Pembacaan DHT11 gagal, err=");
    Serial.println(err);
    delay(1000);
    return;
  }

  Serial.print("Keadaan Sekarang: ");
  Serial.print((int)temperature);
  Serial.print(" *C, ");

  lcd.print((int)temperature);
  lcd.print("*C  ");
  lcd.print(((int)temperature)*1.8+32);
  lcd.println("*F ");  


  lcd.setCursor(1, 9);
  lcd.print(rtc.getDate());
  lcd.print(rtc.getTime());

  delay(1500);

  //KONDISI 1 : DINGIN
  if (temperature < 28) {
    digitalWrite(LedBiru, LOW);
    digitalWrite(LedMerah, LOW);
    digitalWrite(LedHijau, HIGH);
    Serial.println("LED Hijau nyala");
  }
  //KONDISI 2 : NORMAL
  if (temperature = 28) {
    digitalWrite(LedHijau, LOW);
    digitalWrite(LedBiru, HIGH);
    digitalWrite(LedMerah, LOW);
    Serial.println("LED Biru nyala");
  }
  //KONDISI 3 : PANAS
  if (temperature > 28) {
    digitalWrite(LedHijau, LOW);
    digitalWrite(LedBiru, LOW);
    digitalWrite(LedMerah, HIGH);
    Serial.println("LED Merah nyala");
  }
}

void setup() {
  Serial.begin(115200);
  Serial.println("Simple DHT");
  pinMode(LedMerah, OUTPUT);
  pinMode(LedHijau, OUTPUT);
  pinMode(LedBiru, OUTPUT);
  delay(3000);

  //LCD
  lcd.init();  // initialize the lcd
  lcd.backlight();
  lcd.clear();
  lcd.home();
}


void loop() {
  //LCD
  lcd.home();
  CahayaSuhu();
  delay(1000); 
}
