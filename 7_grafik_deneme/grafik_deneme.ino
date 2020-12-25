#include <LCD5110_Graph.h>

LCD5110 myGLCD(8,9,10,11,12);

extern uint8_t photo[];


void setup() {
  // put your setup code here, to run once:
  myGLCD.InitLCD();


}

void loop()
{
 myGLCD.clrScr();
 myGLCD.drawBitmap(0, 0, photo, 48, 48);
 myGLCD.update();
 
 delay(2000);
 
 myGLCD.clrScr();
 myGLCD.print("Baba nasil", CENTER, 0);
 myGLCD.update();
}
