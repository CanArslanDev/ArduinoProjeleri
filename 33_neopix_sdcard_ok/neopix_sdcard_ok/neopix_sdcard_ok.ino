//--------------------------------------------------------------------------------------------------
#include <Adafruit_NeoPixel.h>

// constants won't change. They're used here to 
// set pin numbers:
const int ledPin = 4;     // the number of the neopixel strip
const int numLeds = 13;
#define PIN        4 // On Trinket or Gemma, suggest changing this to 1
#define NUMPIXELS 13 // Popular NeoPixel ring size
//Adafruit_NeoPixel pixels = Adafruit_NeoPixel(8, ledPin);
Adafruit_NeoPixel strip = Adafruit_NeoPixel(numLeds, ledPin, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
#define DELAYVAL 50 // Time (in milliseconds) to pause between pixels
#include <SoftwareSerial.h>
#include "SD.h"       // SD Kart kütüphanesi
#include "TMRpcm.h"   // SD Karttan .Wav dosyalarını oynatmak için gerekli kütüphane
#include "SPI.h"      // SPI fonksiyonlarını kullanabilmek için gerekli kütüphane
#define SD_ChipSelectPin 2
TMRpcm tmrpcm;
int SensorPin;
int x=0;
int butonPin=7;
int butonDurum=0;
int butonPin2=5;
int butonDurum2=0;
int f=0;
int h=0;
//----------------------------------------------
void setup () {
  pinMode(SensorPin,INPUT);
     strip.begin();
  strip.setBrightness(100); // 1/3 brightness
tmrpcm.speakerPin = 9; // Uno ve Nano için 9, Mega için 5,6,11
Serial.begin(9600);
if (!SD.begin(SD_ChipSelectPin)) {
Serial.println("SD BASARISIZ");
return;
   pinMode(butonPin,INPUT);  
 pinMode(butonPin2,INPUT); 
   // These lines are specifically to support the Adafruit Trinket 5V 16 MHz.
  // Any other board, you can remove this part (but no harm leaving it):
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  // END of Trinket-specific code.

  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
}
  tmrpcm.play("0001.wav"); // Ses Dosyasını Oynat
  delay(1000);
}
void rainbow(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i*1+j) & 255));
    }
    strip.show();
    delay(wait);
  }
}
// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  if(WheelPos < 85) {
    return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  } 
  else if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } 
  else {
    WheelPos -= 170;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}
// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}



// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(uint8_t wait) {
  uint16_t i, j;
tmrpcm.play("0003.wav"); // Ses Dosyasını Oynat

}
//Theatre-style crawling lights.
void theaterChase(uint32_t c, uint8_t wait) {
  for (int j=0; j<10; j++) {  //do 10 cycles of chasing
    for (int q=0; q < 3; q++) {
      for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, c);    //turn every third pixel on
      }
      strip.show();

      delay(wait);

      for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}

//Theatre-style crawling lights with rainbow effect
void theaterChaseRainbow(uint8_t wait) {
  for (int j=0; j < 256; j++) {     // cycle all 256 colors in the wheel
    for (int q=0; q < 3; q++) {
      for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
     
      }

      for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}
//
void loop () {  
  SensorPin=analogRead(A2);
  Serial.println(SensorPin);
    pixels.clear(); // Set all pixel colors to 'off'
 if(digitalRead(butonPin)==HIGH){
  if(x<1){
    x++;
tmrpcm.play("0003.wav"); // Ses Dosyasını Oynat
    delay(500);
//-----------------------------------------------

    }
      tmrpcm.play("0005.wav"); // Ses Dosyasını Oynat
          rainbow(30);
  delay(10);
  }
 else{x=0;
   strip.clear();
 } 
 //-----------------------------------------------  
  if(digitalRead(butonPin2)==HIGH){
    //-----------------------------------------------
     if(h<1){
      h++;
          tmrpcm.play("0004.wav"); // Ses Dosyasını Oynat
     }
    if(SensorPin > 200){
  for(int i=0; i<6; i++) { // For each pixel...
    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a moderately bright green color:
    pixels.setPixelColor(i+1, pixels.Color(0, 150, 150));
    pixels.setPixelColor(i, pixels.Color(0, 150, 0));
    pixels.show();   // Send the updated pixel colors to the hardware.
    f++;
    delay(20); // Pause before next pass through loop
  }
    for(int i=6; i>=0; i--) { // For each pixel...

    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a moderately bright green color:
    pixels.setPixelColor(f, pixels.Color(0, 150, 150));
     pixels.setPixelColor(f, pixels.Color(0, 150, 0));
    pixels.setPixelColor(f-1, pixels.Color(0, 150, 0));
    pixels.setPixelColor(f-2, pixels.Color(0, 150, 0));
    pixels.setPixelColor(f-3, pixels.Color(0, 150, 0));
    pixels.setPixelColor(f-4, pixels.Color(0, 150, 0));
    pixels.setPixelColor(f-5, pixels.Color(0, 150, 0));
    pixels.setPixelColor(f-6, pixels.Color(0, 150, 0));
    pixels.show();   // Send the updated pixel colors to the hardware.
   f--;
    delay(20); // Pause before next pass through loop
    pixels.clear();
  }
    }
        if(SensorPin > 100){
  for(int i=0; i<4; i++) { // For each pixel...
    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a moderately bright green color:
    pixels.setPixelColor(i+1, pixels.Color(0, 150, 150));
    pixels.setPixelColor(i, pixels.Color(0, 150, 0));
    pixels.show();   // Send the updated pixel colors to the hardware.
    f++;
    delay(20); // Pause before next pass through loop
  }
    for(int i=4; i>0; i--) { // For each pixel...

    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a moderately bright green color:
    pixels.setPixelColor(f, pixels.Color(0, 150, 150));
     pixels.setPixelColor(f, pixels.Color(0, 150, 0));
    pixels.setPixelColor(f-1, pixels.Color(0, 150, 0));
    pixels.setPixelColor(f-2, pixels.Color(0, 150, 0));
    pixels.setPixelColor(f-3, pixels.Color(0, 150, 0));
    pixels.setPixelColor(f-4, pixels.Color(0, 150, 0));
    pixels.show();   // Send the updated pixel colors to the hardware.
   f--;
    delay(20); // Pause before next pass through loop
    pixels.clear();
  }
    }
            if(SensorPin > 30){
  for(int i=0; i<2; i++) { // For each pixel...
    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a moderately bright green color:
    pixels.setPixelColor(i+1, pixels.Color(0, 150, 150));
    pixels.setPixelColor(i, pixels.Color(0, 150, 0));
    pixels.show();   // Send the updated pixel colors to the hardware.
    f++;
    delay(20); // Pause before next pass through loop
  }
    for(int i=2; i>0; i--) { // For each pixel...

    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a moderately bright green color:
    pixels.setPixelColor(f, pixels.Color(0, 150, 150));
     pixels.setPixelColor(f, pixels.Color(0, 150, 0));
    pixels.setPixelColor(f-1, pixels.Color(0, 150, 0));
    pixels.setPixelColor(f-2, pixels.Color(0, 150, 0));
    pixels.setPixelColor(f-3, pixels.Color(0, 150, 0));
    pixels.setPixelColor(f-4, pixels.Color(0, 150, 0));
    pixels.show();   // Send the updated pixel colors to the hardware.
   f--;
    delay(20); // Pause before next pass through loop
    pixels.clear();
  } }
   }else{
    h=0;
   }
  }
