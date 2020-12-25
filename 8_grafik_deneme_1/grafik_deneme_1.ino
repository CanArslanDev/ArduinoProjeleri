#include <LCD5110_Graph.h>

LCD5110 myGLCD(8,9,10,11,12);

extern uint8_t d[];
extern uint8_t SmallFont[];
extern uint8_t MediumNumbers[];


void setup() {
  // put your setup code here, to run once:
  myGLCD.InitLCD();



}

void loop()
{
 myGLCD.clrScr();
 myGLCD.drawBitmap(0, 0, d, 48, 48);
 myGLCD.update();
 
 delay(2000);


 myGLCD.clrScr();
 myGLCD.setFont(SmallFont);
 myGLCD.print("Baba nasil", 10, 10);
 myGLCD.update();
 
 delay(2000);

 myGLCD.clrScr();
 myGLCD.setFont(MediumNumbers);
  myGLCD.print("1234567890",CENTER,0);
   myGLCD.update();

  delay(2000);
}
