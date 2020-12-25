#include "FastLED.h"
#define NUM_LEDS 5 
CRGB leds[NUM_LEDS];
#define PIN 5 
int butonPin=10;
int butonPin2=11;
int butonPin3=12;
int butonDurum=0;
int butonDurum2=0;
int butonDurum3=0;
int role=4;
void setup()
{
  pinMode(role, OUTPUT);
  pinMode(butonPin3, INPUT); //buton pinini giriş olarak atadık
  pinMode(butonPin2, INPUT); //buton pinini giriş olarak atadık
  pinMode(butonPin, INPUT); //buton pinini giriş olarak atadık
  FastLED.addLeds<WS2811, PIN, GRB>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
}

// *** REPLACE FROM HERE ***
void loop() {
    butonDurum=digitalRead(butonPin); // dijital olarak okuduk 
        if(butonDurum==LOW){
           digitalWrite(role, HIGH);
  FadeInOut(0xff, 0xff, 0xff);
      butonDurum=digitalRead(butonPin); // dijital olarak okuduk 
  if(butonDurum==HIGH){
      digitalWrite(role, LOW);
   CylonBounce(0xff, 0, 0, 1, 100, 10);
   CylonBounce(0xff, 0, 0, 1, 100, 10);
  }
    butonDurum2=digitalRead(butonPin2); // dijital olarak okuduk 
  if(butonDurum2==LOW){
    butonDurum2=digitalRead(butonPin2); // dijital olarak okuduk 
  if(butonDurum2==LOW){
      digitalWrite(role, LOW);
   CylonBounce(0xff, 0, 0, 1, 100, 10);
   CylonBounce(0xff, 0, 0, 1, 100, 10);
  }
  }
  } 
      butonDurum2=digitalRead(butonPin2); // dijital olarak okuduk 
          if(butonDurum2==LOW){
            delay(10);
                butonDurum2=digitalRead(butonPin2); // dijital olarak okuduk 
                if(butonDurum2==HIGH){
                   digitalWrite(role, HIGH);
    CylonBounce(0xff, 0, 0, 1, 100, 10);
  } 
      butonDurum2=digitalRead(butonPin2); // dijital olarak okuduk 
    if(butonDurum2==LOW){
       digitalWrite(role, HIGH);
   Strobe(0, 0xff, 0, 3, 50, 1000);
  }
  }
  butonDurum3=digitalRead(butonPin3); // dijital olarak okuduk 
  if(butonDurum3==LOW){
    digitalWrite(role, LOW);
  CylonBounce(0xff, 0, 0, 1, 100, 10);
  CylonBounce(0xff, 0, 0, 1, 100, 10);
  CylonBounce(0xff, 0, 0, 1, 100, 10);
  CylonBounce(0xff, 0, 0, 1, 100, 10);
  CylonBounce(0xff, 0, 0, 1, 100, 10);
  CylonBounce(0xff, 0, 0, 1, 100, 10);
  CylonBounce(0xff, 0, 0, 1, 100, 10);
  }

}
void Strobe(byte red, byte green, byte blue, int StrobeCount, int FlashDelay, int EndPause){
  for(int j = 0; j < StrobeCount; j++) {
    setAll(red,green,blue);
    showStrip();
    delay(FlashDelay);
    setAll(0,0,0);
    showStrip();
    delay(FlashDelay);
  }
 
 delay(EndPause);
}
void FadeInOut(byte red, byte green, byte blue){
  float r, g, b;
     
  for(int k = 0; k < 256; k=k+1) {
    r = (k/256.0)*red;
    g = (k/256.0)*green;
    b = (k/256.0)*blue;
    setAll(r,g,b);
    showStrip();
  }
     
  for(int k = 255; k >= 0; k=k-2) {
    r = (k/256.0)*red;
    g = (k/256.0)*green;
    b = (k/256.0)*blue;
    setAll(r,g,b);
    showStrip();
  }
}
void CylonBounce(byte red, byte green, byte blue, int EyeSize, int SpeedDelay, int ReturnDelay){

  for(int i = -1; i < NUM_LEDS-EyeSize; i++) {
    setAll(0,0,0);
         setPixel(i, red, green, blue);
    for(int j = 1; j <= EyeSize; j++) {
      setPixel(i+j, red, green, blue); 
    }
    setPixel(i+EyeSize+1, red/10, green/10, blue/10);
    setPixel(i+EyeSize+2, red/50, green/50, blue/50);
  /*  setPixel(i+EyeSize+3, red/50, green/50, blue/50);
    setPixel(i+EyeSize+4, red/50, green/50, blue/50);
    setPixel(i+EyeSize+5, red/50, green/50, blue/50);
    setPixel(i+EyeSize+6, red/50, green/50, blue/50);
    setPixel(i+EyeSize+7, red/50, green/50, blue/50);
    setPixel(i+EyeSize+8, red/50, green/50, blue/50);*/
    setPixel(i+EyeSize-1, red/10, green/10, blue/10);
   //         setPixel(i+EyeSize-2, red/50, green/50, blue/50);
 /*   setPixel(i+EyeSize-2, red/50, green/50, blue/50);
    setPixel(i+EyeSize-3, red/50, green/50, blue/50);
    setPixel(i+EyeSize-4, red/50, green/50, blue/50);*/
    showStrip();
    delay(SpeedDelay);
  }

  delay(ReturnDelay);

  for(int i = NUM_LEDS-EyeSize-2; i > -1; i--) {
    setAll(0,0,0);
         setPixel(i, red, green, blue);
    for(int j = 1; j <= EyeSize; j++) {
      setPixel(i+j, red, green, blue); 
    }
    setPixel(i+EyeSize+1, red/10, green/10, blue/10);
    setPixel(i+EyeSize+2, red/50, green/50, blue/50);
  /*  setPixel(i+EyeSize+3, red/50, green/50, blue/50);
    setPixel(i+EyeSize+4, red/50, green/50, blue/50);
    setPixel(i+EyeSize+5, red/50, green/50, blue/50);
    setPixel(i+EyeSize+6, red/50, green/50, blue/50);
    setPixel(i+EyeSize+7, red/50, green/50, blue/50);
    setPixel(i+EyeSize+8, red/50, green/50, blue/50);*/
    setPixel(i+EyeSize-1, red/10, green/10, blue/10);
   //     setPixel(i+EyeSize-2, red/50, green/50, blue/50);
 /*   setPixel(i+EyeSize-2, red/50, green/50, blue/50);
    setPixel(i+EyeSize-3, red/50, green/50, blue/50);
    setPixel(i+EyeSize-4, red/50, green/50, blue/50);*/
    showStrip();
    delay(SpeedDelay);
  }
  
  delay(ReturnDelay);
}
// *** REPLACE TO HERE ***

void showStrip() {
 #ifdef ADAFRUIT_NEOPIXEL_H 
   // NeoPixel
   strip.show();
 #endif
 #ifndef ADAFRUIT_NEOPIXEL_H
   // FastLED
   FastLED.show();
 #endif
}

void setPixel(int Pixel, byte red, byte green, byte blue) {
 #ifdef ADAFRUIT_NEOPIXEL_H 
   // NeoPixel
   strip.setPixelColor(Pixel, strip.Color(red, green, blue));
 #endif
 #ifndef ADAFRUIT_NEOPIXEL_H 
   // FastLED
   leds[Pixel].r = red;
   leds[Pixel].g = green;
   leds[Pixel].b = blue;
 #endif
}

void setAll(byte red, byte green, byte blue) {
  for(int i = 0; i < NUM_LEDS; i++ ) {
    setPixel(i, red, green, blue); 
  }
  showStrip();
}
