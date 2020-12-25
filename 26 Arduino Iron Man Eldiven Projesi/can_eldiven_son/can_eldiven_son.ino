#include <Servo.h>
Servo servo;
Servo servo1;
int butonPin=5;
int butondurum=0;
int butonsayac=0;
int sonbutondurum=0;
#include "SoftwareSerial.h"
//RX-TX PINLERI AYARLA
#include <SoftwareSerial.h>
#include <DFPlayer_Mini_Mp3.h>
SoftwareSerial secondarySerial(7, 8); // RX, TX
void setup() {
Serial.begin(9600);
servo.attach(3);
servo1.attach(4);
  pinMode(butonPin, INPUT_PULLUP);
    pinMode(10, INPUT_PULLUP);
servo.write(170);
servo1.write(0);
pinMode(6,OUTPUT);
secondarySerial.begin (9600);
mp3_set_serial (secondarySerial); //set Serial for DFPlayer-mini mp3 module
mp3_set_volume (100);
   mp3_play(5);
delay(2500);
}
void loop() {
butondurum = digitalRead(butonPin);
if (butondurum != sonbutondurum) { //eğer şuanki buton durumu son buton durumundan farklıysa yani pasiften aktif olmuşsa veya aktiften basif olmuşsa                         
if (butondurum == LOW) {     //ve eğer buton durumu aktifse
butonsayac++; }                //butonsayacını 1 arttır
delay(50); }                   // çift basım hatasını gidermek için 50ms bekle
sonbutondurum = butondurum; //butondurumunu son buton durumuna kaydet
 if (butonsayac % 2 == 0) {  //eğer butona 2 kes basılmışsa, aktif et 0 a eşitle ve 
   if(digitalRead(5)==LOW){mp3_play (3);delay(2000);}
   servo.write(170);
delay(20);
servo1.write(0);
}  
else{
 if(digitalRead(5)==LOW){mp3_play (1);delay(2000);}
   servo.write(110);
  delay(20);
servo1.write(40);
}  
if(digitalRead(10)==LOW){
  mp3_play (2);
digitalWrite(6, HIGH);
delay(5000);
  digitalWrite(6, LOW);
mp3_play (4);
delay(2700);}

else{
  digitalWrite(6, LOW);}
}


  
