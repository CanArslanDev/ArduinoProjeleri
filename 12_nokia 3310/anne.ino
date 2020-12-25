#include <LCD5110_Graph.h>

LCD5110 myGLCD(8,9,10,11,12);

extern uint8_t anne[];
extern uint8_t baba[];
extern uint8_t SmallFont[];
extern uint8_t MediumNumbers[];


void setup() {
  // put your setup code here, to run once:
  myGLCD.InitLCD();



}

void loop()
{
 myGLCD.clrScr();
 myGLCD.drawBitmap(0, 0, anne, 48, 48);
 myGLCD.update();
 
 delay(2000);

 myGLCD.clrScr();
 myGLCD.drawBitmap(0, 0, baba, 48, 48);
 myGLCD.update();

 delay(2000);

 myGLCD.clrScr();
 myGLCD.invert(0);
 myGLCD.setFont(SmallFont);
 myGLCD.print("Sizi Seviyorum", 0,10);
 myGLCD.print("Anne Ve Baba", CENTER,20);
 myGLCD.update();

 delay(500);

 myGLCD.clrScr();
 myGLCD.invert(1);
 myGLCD.setFont(SmallFont);
 myGLCD.print("Sizi Seviyorum", 0,10);
 myGLCD.print("Anne Ve Baba", CENTER,20);
 myGLCD.update();

 delay(500);

 myGLCD.clrScr();
 myGLCD.invert(0);
 myGLCD.setFont(SmallFont);
 myGLCD.print("Sizi Seviyorum", 0,10);
 myGLCD.print("Anne Ve Baba", CENTER,20);
 myGLCD.update();

 delay(500);

 myGLCD.clrScr();
 myGLCD.invert(1);
 myGLCD.setFont(SmallFont);
 myGLCD.print("Sizi Seviyorum", 0,10);
 myGLCD.print("Anne Ve Baba", CENTER,20);
 myGLCD.update();

 delay(500);

 myGLCD.clrScr();
 myGLCD.invert(0);
 myGLCD.setFont(SmallFont);
 myGLCD.print("Sizi Seviyorum", 0,10);
 myGLCD.print("Anne Ve Baba", CENTER,20);
 myGLCD.update();

 delay(500);

 myGLCD.clrScr();
 myGLCD.setFont(SmallFont);
 myGLCD.invertText(1);
 myGLCD.print("Sizi Seviyorum", 0,10);
myGLCD.invertText(0);
 myGLCD.print("Anne Ve Baba", CENTER,20);
 myGLCD.update();


 delay(500);

 myGLCD.clrScr();
 myGLCD.setFont(SmallFont);
 myGLCD.invertText(0);
 myGLCD.print("Sizi Seviyorum", 0,10);
myGLCD.invertText(1);
 myGLCD.print("Anne Ve Baba", CENTER,20);
 myGLCD.update();


 delay(500);


myGLCD.clrScr();
 myGLCD.setFont(SmallFont);
 myGLCD.invertText(1);
 myGLCD.print("Sizi Seviyorum", 0,10);
myGLCD.invertText(0);
 myGLCD.print("Anne Ve Baba", CENTER,20);
 myGLCD.update();


 delay(500);

 myGLCD.clrScr();
 myGLCD.setFont(SmallFont);
 myGLCD.invertText(0);
 myGLCD.print("Sizi Seviyorum", 0,10);
myGLCD.invertText(1);
 myGLCD.print("Anne Ve Baba", CENTER,20);
 myGLCD.update();


 delay(500);


 
 

}
