//Kod Yapımcısı: Can Arslan
//Yürüyen Robot Projesi
#include <SoftwareSerial.h>
SoftwareSerial bt_iletisim(7,6);
#include <Servo.h>
Servo sg92; //servo pinlerini tanıtıyoruz
Servo sg91; //servo pinlerini tanıtıyoruz
Servo sg90;  //servo pinlerini tanıtıyoruz
Servo sg89;  //servo pinlerini tanıtıyoruz
const int trig = 2;
const int echo = 3;
int sure = 0;
int mesafe = 0;
void setup() {
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);  
    Serial.begin(9600);
    bt_iletisim.begin(9600);
  sg90.attach(8);  // pinlerini ayarlıyoruz
  sg89.attach(10);   // pinlerini ayarlıyoruz
  sg91.attach(9);  // pinlerini ayarlıyoruz
  sg92.attach(11);  // pinlerini ayarlıyoruz
sg90.write(30);  // pinlerin yönünü ayarlıyoruz
sg89.write(30);  // pinlerin yönünü ayarlıyoruz
sg91.write(30);  // pinlerin yönünü ayarlıyoruz
sg92.write(30);  // pinlerin yönünü ayarlıyoruz
delay(700); // 1000ms (1sn) beklemesini istiyoruz
Serial.println("Kod Çalışıyor");
}
void loop() {
  {
  digitalWrite(trig,HIGH);
  delayMicroseconds(1000);
  digitalWrite(trig,LOW);
  sure = pulseIn(echo,HIGH);
  mesafe = (sure/2) / 29.1;
  Serial.print("Mesafe:");
  Serial.print(mesafe);
  Serial.print("cm");
  delay(250);
  }
if (bt_iletisim.available())
{
  char data=bt_iletisim.read();
  Serial.println(data);
    if(data=='5'){
sg90.write(30);  // pinlerin yönünü ayarlıyoruz
sg89.write(30);  // pinlerin yönünü ayarlıyoruz
sg91.write(0);  // pinlerin yönünü ayarlıyoruz
sg92.write(0);  // pinlerin yönünü ayarlıyoruz
delay(700); // 1000ms (1sn) beklemesini istiyoruz
sg90.write(0);  // pinlerin yönünü ayarlıyoruz
sg89.write(0);  // pinlerin yönünü ayarlıyoruz
sg91.write(30);  // pinlerin yönünü ayarlıyoruz
sg92.write(30);  // pinlerin yönünü ayarlıyoruz
delay(700); // 1000ms (1sn) beklemesini istiyoruz
  }
   else if(data=='6'){
sg90.write(30);  // pinlerin yönünü ayarlıyoruz
sg89.write(30);  // pinlerin yönünü ayarlıyoruz
sg91.write(0);  // pinlerin yönünü ayarlıyoruz
sg92.write(0);  // pinlerin yönünü ayarlıyoruz
delay(700); // 1000ms (1sn) beklemesini istiyoruz
sg90.write(0);  // pinlerin yönünü ayarlıyoruz
sg89.write(0);  // pinlerin yönünü ayarlıyoruz
sg91.write(30);  // pinlerin yönünü ayarlıyoruz
sg92.write(30);  // pinlerin yönünü ayarlıyoruz
delay(700); // 1000ms (1sn) beklemesini istiyoruz
}
      if (mesafe <= 10 )
{
    sg90.write(30);  // pinlerin yönünü ayarlıyoruz
sg89.write(30);  // pinlerin yönünü ayarlıyoruz
sg91.write(30);  // pinlerin yönünü ayarlıyoruz
sg92.write(30);  // pinlerin yönünü ayarlıyoruz
 sg90.attach(0);  // pinlerini ayarlıyoruz
  sg89.attach(0);   // pinlerini ayarlıyoruz
  sg91.attach(0);  // pinlerini ayarlıyoruz
  sg92.attach(0);  // pinlerini ayarlıyoruz
    
  }
   
    else if (mesafe >= 11)
    {
       sg90.attach(8);  // pinlerini ayarlıyoruz
  sg89.attach(10);   // pinlerini ayarlıyoruz
  sg91.attach(9);  // pinlerini ayarlıyoruz
  sg92.attach(11);  // pinlerini ayarlıyoruz
  }
 if(data=='7'){
  sg90.write(30);  // pinlerin yönünü ayarlıyoruz
sg89.write(30);  // pinlerin yönünü ayarlıyoruz
sg91.write(30);  // pinlerin yönünü ayarlıyoruz
sg92.write(30);  // pinlerin yönünü ayarlıyoruz
delay(1000); // 1000ms (1sn) beklemesini istiyoruz
  sg90.write(0);  // pinlerin yönünü ayarlıyoruz
sg89.write(60);  // pinlerin yönünü ayarlıyoruz
sg91.write(30);  // pinlerin yönünü ayarlıyoruz
sg92.write(30);  // pinlerin yönünü ayarlıyoruz
delay(1000); // 1000ms (1sn) beklemesini istiyoruz
sg90.write(30);  // pinlerin yönünü ayarlıyoruz
sg89.write(30);  // pinlerin yönünü ayarlıyoruz
sg91.write(30);  // pinlerin yönünü ayarlıyoruz
sg92.write(30);  // pinlerin yönünü ayarlıyoruz
 }
  else if(data=='8'){
sg90.write(0);  // pinlerin yönünü ayarlıyoruz
sg89.write(0);  // pinlerin yönünü ayarlıyoruz
sg91.write(0);  // pinlerin yönünü ayarlıyoruz
sg92.write(0);  // pinlerin yönünü ayarlıyoruz
delay(100); // 1000ms (1sn) beklemesini istiyoruz
sg90.write(60);  // pinlerin yönünü ayarlıyoruz
sg89.write(60);  // pinlerin yönünü ayarlıyoruz
sg91.write(60);  // pinlerin yönünü ayarlıyoruz
sg92.write(60);  // pinlerin yönünü ayarlıyoruz
delay(100); // 1000ms (1sn) beklemesini istiyoruz
sg90.write(30);  // pinlerin yönünü ayarlıyoruz
sg89.write(30);  // pinlerin yönünü ayarlıyoruz
sg91.write(30);  // pinlerin yönünü ayarlıyoruz
sg92.write(30);  // pinlerin yönünü ayarlıyoruz
delay(100); // 1000ms (1sn) beklemesini istiyoruz
 }
}
}

