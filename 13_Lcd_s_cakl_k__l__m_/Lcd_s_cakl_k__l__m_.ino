

float sicaklik;
float olculendeger;
int sicaklikpin=0;
//#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2); // set the LCD address to 0x27 for a 16 chars and 2 line display

int oku = LOW;
void setup()
{
  Serial.begin(9600);
  lcd.init();                      // initialize the lcd

  // Print a message to the LCD.
  lcd.backlight();
  
analogReference(INTERNAL);//1.1v 
}


void loop()
{
  olculendeger = analogRead(sicaklikpin);
  olculendeger = (olculendeger/1023)*1100;
  sicaklik = olculendeger /10,0;
  
  lcd.print("Sicaklik : ");
  lcd.print(sicaklik);
  lcd.setCursor(0,1);
  lcd.print(" derece ");
  delay(1000);
  lcd.clear();
  
}
