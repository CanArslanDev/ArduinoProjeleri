
#include <Servo.h>
#include <SoftwareSerial.h>
SoftwareSerial bt_iletisim(7, 6);
Servo servo;
  //String data;
  char data;
void setup() {
  servo.attach(8);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  Serial.begin(38400);
  bt_iletisim.begin(38400);

}

void loop()
{
  /*
    String data;
    if (Serial.available() > 0) { // Eğer seri porta veri geldiyse
    data = Serial.readString(); // gelen veriyi oku ve gelen değişkenine aktar
    }

  */
  if (bt_iletisim.available() > 0)
  {
    /*-CAN komutlar
      char data;
      data=bt_iletisim.read();
      Serial.println(data);
    */
    

    data = bt_iletisim.read();
    Serial.println(data);
    {
        
      if (data == '1')
      {
        data = bt_iletisim.read();
        if(data=='o'){digitalWrite(2, HIGH);}
        if(data=='c'){digitalWrite(2, LOW);}
      }
      if (data == '2')
      {
        data = bt_iletisim.read();
        if(data=='o'){digitalWrite(3, HIGH);}
        if(data=='c'){digitalWrite(3, LOW);}
      }
      if (data == '3')
      {
        data = bt_iletisim.read();
        if(data=='o'){digitalWrite(4, HIGH);}
        if(data=='c'){digitalWrite(4, LOW);}
      }
      if (data == '4')
      {
        data = bt_iletisim.read();
        if(data=='o'){digitalWrite(5, HIGH);}
        if(data=='c'){digitalWrite(5, LOW);}
      }
      if (data == '5')
      {
        data = bt_iletisim.read();
        if(data=='l'){servo.write(50);}
        if(data=='m'){servo.write(90);}
        if(data=='h'){servo.write(120);}
      }
    }
  }
}
