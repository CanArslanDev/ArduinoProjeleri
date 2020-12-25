#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F, 20, 4);
#include "Wire.h"
#include "Adafruit_BMP085.h" //Basınç Sensörü Kütüphanesi
Adafruit_BMP085 mySensor; 
byte ozelChar[8] = { //yatay
        B00000,
        B00000,
        B00000,
        B11111,
        B00000,
        B00000,
        B00000,
        B00000
};
byte ozelChar1[8] = { //dikey
        B00100,
        B00100,
        B00100,
        B00100,
        B00100,
        B00100,
        B00100,
        B00100
};
byte ozelChar2[8] = { // yataya tam dikey yarım (dik)
        B00100,
        B00100,
        B00100,
        B11111,
        B00000,
        B00000,
        B00000,
        B00000
};
byte ozelChar3[8] = { //yatay tam dikey tam
        B00100,
        B00100,
        B00100,
        B11111,
        B00100,
        B00100,
        B00100,
        B00100
};
byte ozelChar4[8] = {
        B00000,
        B00000,
        B00000,
        B11111,
        B00100,
        B00100,
        B00100,
        B00100
};


int high;
float zaman=60;
int saat=0;
int dakika=0;
int saniye=0;
int buzzerPin = 7;
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
int butonPin=6;
int butonsayac = 0; //butona kaç kere basıldığını yazıcağımız değişkenimiz
int sonbutondurum = 0; //butonun en son basılıp basılmadığını atadığımız değişkenimiz
int butondurum = 0; //butonun basılıp basılmadığını atadığımız değişkenimiz
int butondurum1 = 0; //butonun basılıp basılmadığını atadığımız değişkenimiz
int butondurum2 = 0; //butonun basılıp basılmadığını atadığımız değişkenimiz
void setup() {
pinMode(buzzerPin, OUTPUT); //ledpinini çıkış olarak atadık
    lcd.init();
    lcd.backlight();
  mySensor.begin();
  lcd.print("Yukleniyor...");
    lcd.setCursor(0,1);
lcd.print("Lutfen Bekleyiniz");
 lcd.createChar(1,ozelChar);
  lcd.createChar(2,ozelChar1);
   lcd.createChar(3,ozelChar2);
  lcd.createChar(4,ozelChar3);
    lcd.createChar(5,ozelChar4);
  delay(2000);
  lcd.clear();
   
}
void loop() {
rakim3=mySensor.readAltitude(); //Rakım Okunuyor
rakim4 = rakim3 + 36;
rakim = rakim3 + 36;
      basinc=mySensor.readPressure(); //Rakım Okunuyor
  Celsius = mySensor.readTemperature(); // Sıcaklık Okuyor
Fahrenheit = Celsius*1.8 + 32.; // Fahrenheit ile Celsius Dönüşümü Yapılıyor
//-----------------------------------------------------------------------
  butondurum = digitalRead(butonPin);
if (butondurum != sonbutondurum) { //eğer şuanki buton durumu son buton durumundan 
if (butondurum == HIGH) {     //ve eğer buton durumu aktifse
butonsayac++;                 //butonsayacını 1 arttır
}
delay(50);                    // çift basım hatasını gidermek için 50ms bekle
}
sonbutondurum = butondurum; //butondurumunu son buton durumuna kaydet
if (butonsayac % 2 == 0) {  //eğer butona 2 kes basılmışsa, aktif et 0 a eşitle ve 
 yyrakim=mySensor.readAltitude(); //Rakım Okunuyor
              yerdenm=mySensor.readAltitude(); //Rakım Okunuyor
     rakim1=mySensor.readAltitude(); //Rakım Okunuyor
     delay(1000);
     saniye ++;
    lcd.clear();
  lcd.setCursor(0,3);
  lcd.print("R:");
  lcd.print(rakim);
  //--------------------------
  /*
        lcd.setCursor(7,2);
  lcd.print("B:");
  lcd.print(basinc); */
  //--------------------------
      lcd.setCursor(0,0);
    lcd.print(Celsius);
    lcd.print("C"); 
    
  //--------------------------
        lcd.setCursor(13,3);
       sonuc = yyrakim - rakim1;
    lcd.print(sonuc);
          lcd.print(" M");
    //--------------------------------------
        {
              yerdenm1=mySensor.readAltitude(); //Rakım Okunuyor
       sonuc1 = yerdenm1 - yerdenm;
            lcd.setCursor(14,1);
            lcd.print(sonuc1);
                        lcd.print("M/s");
                        //aşağı doğru 
                          if (sonuc1 < 0)
                    {
                   digitalWrite(buzzerPin, HIGH);
                      delay(500);
                      digitalWrite(buzzerPin, LOW); 
                   }
          //sağa doğru
          lcd.setCursor(0,2);
          lcd.write(byte(1));
          lcd.setCursor(1,2);
          lcd.write(byte(1));
          lcd.setCursor(2,2);
          lcd.write(byte(1));
          lcd.setCursor(3,2);
          lcd.write(byte(1));
           lcd.setCursor(4,2);
          lcd.write(byte(1));
          lcd.setCursor(5,2); 
          lcd.write(byte(1));
          lcd.setCursor(7,2);
          lcd.write(byte(1));
          lcd.setCursor(8,2);
          lcd.write(byte(1));
          lcd.setCursor(9,2);
          lcd.write(byte(5));
          lcd.setCursor(10,2);
          lcd.write(byte(1));
          lcd.setCursor(11,2);
          lcd.write(byte(1));
          lcd.setCursor(13,2);
          lcd.write(byte(1));
          lcd.setCursor(14,2);
          lcd.write(byte(1));
          lcd.setCursor(15,2);
          lcd.write(byte(1));
          lcd.setCursor(16,2);
          lcd.write(byte(1));
          lcd.setCursor(17,2);
          lcd.write(byte(1));
          lcd.setCursor(18,2);
          lcd.write(byte(1));
          lcd.setCursor(19,2);
          lcd.write(byte(1));
          //aşağı doğru
          lcd.setCursor(12,0);
          lcd.write(byte(2));
          lcd.setCursor(12,1);
          lcd.write(byte(2));
          lcd.setCursor(12,2);
          lcd.write(byte(4));
          lcd.setCursor(12,3);
          lcd.write(byte(2));
          //aşağı doğru
          lcd.setCursor(6,0);
          lcd.write(byte(2));
          lcd.setCursor(6,1);
          lcd.write(byte(2));
          lcd.setCursor(6,2);
          lcd.write(byte(3));
          //aşağı doğru
          lcd.setCursor(9,3);
          lcd.write(byte(2));
            //------------------------
  if(saniye == zaman)
  {
saniye = 0;
  dakika ++;
  }
              //------------------------
  if(dakika == zaman)
  {
   saniye = 0;
   dakika = 0;
   saat ++;
  }
    //-------------------------------
      lcd.setCursor(10,1);
  lcd.print(saniye);
    lcd.setCursor(7,1);
  lcd.print(dakika);
  lcd.setCursor(9,1);
  lcd.print(":");
    lcd.setCursor(8,0);
    lcd.print("S:");
  lcd.print(saat);
  //-----------------------------
  if(sonuc1 > high){
    high = sonuc1;
  }
  //---------------------------
  lcd.setCursor(10,3);
  lcd.print(high);
    }
}
else
{
 yyrakim=mySensor.readAltitude(); //Rakım Okunuyor
              yerdenm=mySensor.readAltitude(); //Rakım Okunuyor
              dakika = 0;
              saniye = 0;
       delay(1000);
   lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("YerdenY:");
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
                           if (sonuc1 < 0)
                    {
                   digitalWrite(buzzerPin, HIGH);
                      delay(500);
                      digitalWrite(buzzerPin, LOW); 
                   }
}
//---------------------------------------------------------------------------
}
