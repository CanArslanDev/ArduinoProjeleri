#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
#include "Wire.h"
#include "Adafruit_BMP085.h" //Basınç Sensörü Kütüphanesi
Adafruit_BMP085 mySensor; 
int buzzerPin = 6;
int notaSayisi = 8;
int C = 262; //do
int D = 294; //re
int E = 330; //mi
int F = 349; //fa
int G = 392; //sol
int A = 440; //la
int B = 494; //si
int C_ = 523;
int notalar[] = {C, D, E, F, G, A, B, C_};
float Celsius; // Değişkenler Tanımlanıyor
float Fahrenheit;
float yerdenm1;
float yerdenm;
float yyrakim;
float rakim4;
float rakim3;
float rakim2;
float rakim1;
float rakim;
float basinc; 
int sonuc;
int sonuc1;
int sonuc2;
int sonuc3;
int butonPin3=3;
int butonPin2=4;
int butonPin=5;
int butonsayac = 0; //butona kaç kere basıldığını yazıcağımız değişkenimiz
int sonbutondurum = 0; //butonun en son basılıp basılmadığını atadığımız değişkenimiz
int butondurum = 0; //butonun basılıp basılmadığını atadığımız değişkenimiz
int butondurum1 = 0; //butonun basılıp basılmadığını atadığımız değişkenimiz
int butondurum2 = 0; //butonun basılıp basılmadığını atadığımız değişkenimiz
void setup() {
    lcd.begin();
  mySensor.begin();
  lcd.print("Yukleniyor...");
  delay(500);
    lcd.setCursor(0,1);
lcd.print("Lutfen Bekleyin");
  delay(2000);
  lcd.clear();
   
}
void loop() {
rakim4=mySensor.readAltitude(); //Rakım Okunuyor
      basinc=mySensor.readPressure(); //Rakım Okunuyor
  rakim=mySensor.readAltitude(); //Rakım Okunuyor
  Celsius = mySensor.readTemperature(); // Sıcaklık Okuyor
Fahrenheit = Celsius*1.8 + 32.; // Fahrenheit ile Celsius Dönüşümü Yapılıyor
//-----------------------------------------------------------------------
  butondurum = digitalRead(butonPin);
if (butondurum != sonbutondurum) { //eğer şuanki buton durumu son buton durumundan 
if (butondurum == HIGH) {     //ve eğer buton durumu aktifse
butonsayac++;                 //butonsayacını 1 arttır
}
delay(100);                    // çift basım hatasını gidermek için 50ms bekle
}
sonbutondurum = butondurum; //butondurumunu son buton durumuna kaydet
if (butonsayac % 2 == 0) {  //eğer butona 2 kes basılmışsa, aktif et 0 a eşitle ve 

     rakim1=mySensor.readAltitude(); //Rakım Okunuyor
    lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Rakim:");
  lcd.print(rakim);
        lcd.setCursor(0,1);
  lcd.print("B:");
  lcd.print(basinc);
      lcd.setCursor(10,1);
    lcd.print(Celsius);
    lcd.print("C"); 
  delay(1000);
} else {
 yyrakim=mySensor.readAltitude(); //Rakım Okunuyor
              yerdenm=mySensor.readAltitude(); //Rakım Okunuyor
       delay(1000);
   lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("YerdenY:");
       sonuc = yyrakim - rakim1;
    lcd.print(sonuc);
    {
              yerdenm1=mySensor.readAltitude(); //Rakım Okunuyor
       sonuc1 = yerdenm1 - yerdenm;
            lcd.setCursor(10,0);
            lcd.print("SN ");
            lcd.print(sonuc1);
                        lcd.print("M");
    }
      lcd.setCursor(0,1);
  lcd.print("R:");
  lcd.print(rakim);
  lcd.setCursor(10,1);
  lcd.print(Celsius);
  lcd.print("C");
}
//---------------------------------------------------------------------------
sonuc3 = rakim - rakim4;
  if (yerdenm1 >= yerdenm + 1)
  {
         tone(buzzerPin, C);
    delay(1000);
     noTone(buzzerPin);
     sonuc3 - 1;
  }
    if (sonuc < sonuc1)
  {
         tone(buzzerPin, A);
    delay(1000);
     noTone(buzzerPin);
     sonuc3 - 1;
  }
}
