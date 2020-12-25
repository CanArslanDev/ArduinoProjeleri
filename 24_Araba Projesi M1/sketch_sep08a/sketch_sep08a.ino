#include <Servo.h>
#include <SoftwareSerial.h>
Servo sg90;
SoftwareSerial bt_iletisim(7,6);
const int trigPin = 2;
const int echoPin = 3;
unsigned long sure = 0;
int mesafe = 0;
void setup() {
  pinMode(8, OUTPUT);
  pinMode(5, OUTPUT);
  sg90.attach(9);
Serial.begin(9600);
bt_iletisim.begin(9600);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
}

void loop() {
{
       digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    sure = pulseIn(echoPin, HIGH);
    mesafe = (sure/2) /29.1;

    if (mesafe <=21)

     {
          if (mesafe >=5)
          {
      sg90.write(90);
            delay(10);
      digitalWrite(8,HIGH);
      delay(1000);
      digitalWrite(8,LOW);
       delay(10);
      digitalWrite(5,LOW);
          }
     }
     



  if (bt_iletisim.available())
  {
    char data = bt_iletisim.read();
    Serial.println(data);

        if (data == 'a')
    {
    sg90.write(20);
    }

        if (data == 'b')
    {
    sg90.write(90);
    }

        if (data == 'c')
    {
    sg90.write(170);
    }

        if (data == 'd')
    {
    digitalWrite(5,HIGH);
    }

        if (data == 'e')
    {
    digitalWrite(5,LOW);
    }
      if (data == 'f')
    {
    digitalWrite(8,HIGH);
    }
        if (data == 'g')
    {
    digitalWrite(8,LOW);
    }
        if (data == 'i')
    {
pinMode(trigPin, OUTPUT);
pinMode(echoPin, OUTPUT);

    }
        if (data == 'j')
    {
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);


    }

    
        if (data == 'h')
    {
    digitalWrite(5,HIGH);
    delay(500);
    digitalWrite(5,LOW);
    delay(600);
    digitalWrite(5,HIGH);
    delay(300);
    digitalWrite(5,LOW);
    delay(200);
    digitalWrite(5,HIGH);
    delay(300);
    digitalWrite(5,LOW);
    }




  
  }}}
  
  
