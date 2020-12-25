//Kod Yapımcısı: Can Arslan
//Yürüyen Robot Projesi

#include <Servo.h>
Servo sg92; //servo pinlerini tanıtıyoruz
Servo sg91; //servo pinlerini tanıtıyoruz
Servo sg90;  //servo pinlerini tanıtıyoruz
Servo sg89;  //servo pinlerini tanıtıyoruz

void setup() {
  sg90.attach(8);  // pinlerini ayarlıyoruz
  sg89.attach(10);   // pinlerini ayarlıyoruz
  sg91.attach(9);  // pinlerini ayarlıyoruz
  sg92.attach(11);  // pinlerini ayarlıyoruz

}
void loop() {
sg90.write(30);  // pinlerin yönünü ayarlıyoruz
sg89.write(30);  // pinlerin yönünü ayarlıyoruz
sg91.write(0);  // pinlerin yönünü ayarlıyoruz
sg92.write(0);  // pinlerin yönünü ayarlıyoruz
delay(700); // 700ms (0.7sn) beklemesini istiyoruz
sg90.write(0);  // pinlerin yönünü ayarlıyoruz
sg89.write(0);  // pinlerin yönünü ayarlıyoruz
sg91.write(30);  // pinlerin yönünü ayarlıyoruz
sg92.write(30);  // pinlerin yönünü ayarlıyoruz
delay(700); // 1000ms (0.7sn) beklemesini istiyoruz

}

