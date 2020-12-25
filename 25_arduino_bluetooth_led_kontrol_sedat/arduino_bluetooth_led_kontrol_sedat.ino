
#include <Servo.h>
#include <SoftwareSerial.h>
 SoftwareSerial bt_iletisim(7,6);
 Servo servo;

void setup(){
  servo.attach(5);
pinMode(1,OUTPUT);
pinMode(2,OUTPUT);
pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  Serial.begin(9600);
  bt_iletisim.begin(9600);
 
}

void loop() 
{
  if(bt_iletisim.available())
   {
    
    char data=bt_iletisim.read();
    //char data=Serial.read();
   
     Serial.println(data);
    
     {
if(data=='1o')
{
digitalWrite(1,HIGH);    
}
if(data=='1c')
{
digitalWrite(1,LOW);    
}
if(data=='2';'o')
{
digitalWrite(2,HIGH);    
}
if(data=='2c')
{
digitalWrite(2,LOW);    
}
if(data=='3o')
{
digitalWrite(3,HIGH);    
}
if(data=='3c')
{
digitalWrite(3,LOW);    
}
if(data=='4o')
{
digitalWrite(4,HIGH);    
}
if(data=='4c')
{
digitalWrite(4,LOW);    
}
if(data=='5o')
{
digitalWrite(5,HIGH);    
}
if(data=='5c')
{
digitalWrite(5,LOW);    
}
    //-----
if(data=='5l')
{
servo.write(50); 
}
if(data=='6m')
{
servo.write(90); 
}
if(data=='7h')
{
servo.write(170); 
}




}
}
}
