 //--------------------------------------------------------------------------------------------------
#include <Adafruit_NeoPixel.h>
#include <EEPROM.h>
// constants won't change. They're used here to 
// set pin numbers:
const int ledPin = 4;     // the number of the neopixel strip
const int numLeds = 55;
#include <FastLED.h>
#define PIN 4 // On Trinket or Gemma, suggest changing this to 1
#define NUMPIXELS 55 // Popular NeoPixel ring size
#define DELAYVAL 20 // Time (in milliseconds) to pause between pixels
#define NUM_LEDS 55
Adafruit_NeoPixel strip = Adafruit_NeoPixel(numLeds, ledPin, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
#include <SoftwareSerial.h>
#include <DFPlayer_Mini_Mp3.h>
SoftwareSerial secondarySerial( 10, 11); // RX, TX
int x=0;
int y=1;
int z=0;
int f=0;
int l=0;
int j=0;
int butonPin=7;
int butondurum=0;
int butonPin1=6;
int butonDurum1=0;
int butonPin2=5;
int butonDurum2=0;
int butonsayac = 0;
int sonbutondurum = 0;

#define N_PIXELS  55  // Number of pixels in strand
#define MIC_PIN   A5  // Microphone is attached to this analog pin
#define LED_PIN    4  // NeoPixel LED strand is connected to this pin
#define DC_OFFSET  0  // DC offset in mic signal - if unusure, leave 0
#define NOISE     120  // Noise/hum/interference in mic signal
#define SAMPLES   40  // Length of buffer for dynamic level adjustment
#define TOP       (N_PIXELS + 2) // Allow dot to go slightly off scale
#define PEAK_FALL 60  // Rate of peak falling dot

byte
  peak      = 0,      // Used for falling dot
  dotCount  = 0,      // Frame counter for delaying dot-falling speed
  volCount  = 0;      // Frame counter for storing past volume data
int
  vol[SAMPLES],       // Collection of prior volume samples
  lvl       = 20,      // Current "dampened" audio level
  minLvlAvg = 0,      // For dynamic adjustment of graph low & high
  maxLvlAvg = 512;
//----------------------------------------------
void setup () {
  analogReference(EXTERNAL);

  memset(vol, 0, sizeof(vol));
     strip.begin();
  strip.setBrightness(100); //brightness
   pinMode(butonPin,INPUT); 
 pinMode(butonPin1,INPUT); 
 pinMode(butonPin2,INPUT); 
  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
secondarySerial.begin (9600);
mp3_set_serial (secondarySerial); //set Serial for DFPlayer-mini mp3 module
mp3_set_volume (100);
 delay(1000);
   mp3_play (1);
/*   colorWipe2(strip.Color(255, 0, 0), 50); // Red
  colorWipe2(strip.Color(0, 255, 0), 50); // Green
  colorWipe2(strip.Color(0, 0, 255), 50); // Blue */
}
 

void rainbow(uint8_t wait) {
  if(j<1){
  uint16_t i, j;
  for(j=0; j<256; j++) {
    for(i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i*1+j) & 255));
  if(digitalRead(butonPin)==HIGH){
j++;
}
    }
    strip.show();
    delay(5);
  }
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
    delay(30);
    f==c;
    f--;
    f--;
    f--;
    strip.setPixelColor(i, f);
  }
}
void colorWipe2(uint32_t c, uint8_t wait) {
  for(uint16_t i=44; i<strip.numPixels(); i--) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(30);
  }
}


// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(uint8_t wait) {
  uint16_t i, j;


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
void CylonBounce(byte red, byte green, byte blue, int EyeSize, int SpeedDelay, int ReturnDelay){

  for(int i = 0; i < NUM_LEDS-EyeSize-2; i++) {
    setAll(0,0,0);
    setPixel(i, red/10, green/10, blue/10);
    for(int j = 1; j <= EyeSize; j++) {
      setPixel(i+j, red, green, blue); 
    }
    setPixel(i+EyeSize+1, red/10, green/10, blue/10);
    showStrip();
    delay(25);
      if(digitalRead(butonPin)==HIGH){
x++;
}
  }

  delay(ReturnDelay);

  for(int i = NUM_LEDS-EyeSize-2; i > 0; i--) {
    setAll(0,0,0);
    setPixel(i, red/10, green/10, blue/10);
    for(int j = 1; j <= EyeSize; j++) {
      setPixel(i+j, red, green, blue); 
    }
    setPixel(i+EyeSize+1, red/10, green/10, blue/10);
    showStrip();
    delay(25);
      if(digitalRead(butonPin)==HIGH){
x++;
}
  }
  
  delay(ReturnDelay);
}
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

// Set all LEDs to a given color and apply it (visible)
void setAll(byte red, byte green, byte blue) {
  for(int i = 0; i < NUM_LEDS; i++ ) {
    setPixel(i, red, green, blue); 
  }
  showStrip();
}
void FadeInOut(byte red, byte green, byte blue){
  float r, g, b;
      
  for(int k = 0; k < 256; k=k+1) { 
    r = (k/256.0)*red;
    g = (k/256.0)*green;
    b = (k/256.0)*blue;
    setAll(r,g,b);
    showStrip();
      if(digitalRead(butonPin)==HIGH){
x++;
}
  }
     
  for(int k = 255; k >= 0; k=k-2) {
    r = (k/256.0)*red;
    g = (k/256.0)*green;
    b = (k/256.0)*blue;
    setAll(r,g,b);
    showStrip();
     //delay(1000); //kayan ışık animasyon hız gecikme (yavaşlatma) parametresi
      if(digitalRead(butonPin)==HIGH){
x++;
}
  }
}
void loop () {  
  if(x<1){
 CylonBounce(0xff, 0x00, 0x00, 4, 10, 50);
  }
    if(x<1){
 FadeInOut(0xff, 0x00, 0x00); // red
  }
    if(x<1){
  CylonBounce(0, 0, 255, 4, 10, 50);
  }
    if(x<1){
 FadeInOut(0, 0, 255); // red
  }
    if(x<1){
   CylonBounce(0, 250, 0, 4, 10, 50);
  }
    if(x<1){
 FadeInOut(0, 255, 0); // red
  }
    if(x<1){
    CylonBounce(200, 50, 255, 4, 10, 50);
  }
    if(x<1){
 FadeInOut(200, 50, 255); // red
  }
    if(x<1){
     CylonBounce(255, 255, 255, 4, 10, 50);
  }
    if(x<1){
 FadeInOut(255, 255, 255); // red
  }
  
  butondurum = digitalRead(butonPin);
 
if (butondurum != sonbutondurum) { //eğer şuanki buton durumu son buton durumundan 
                                   //farklıysa yani pasiften aktif olmuşsa
                                   //veya aktiften basif olmuşsa
 
if (butondurum == HIGH) {     //ve eğer buton durumu aktifse
butonsayac++;                 //butonsayacını 1 arttır
}
delay(50);                    // çift basım hatasını gidermek için 50ms bekle
}
 
sonbutondurum = butondurum; //butondurumunu son buton durumuna kaydet
 
if (butonsayac % 2 == 0) {  //eğer butona 2 kes basılmışsa, aktif et 0 a eşitle ve 
      if(z<1){
    mp3_next ();
    z++;
    y--;
   }
  if(x>=1){
      uint8_t  i;
  uint16_t minLvl, maxLvl;
  int      n, height;



  n   = analogRead(MIC_PIN);                  // Raw reading from mic
  n   = abs(n - 512 - DC_OFFSET); // Center on zero
  n   = (n <= NOISE) ? 0 : (n - NOISE);             // Remove noise/hum
  lvl = ((lvl * 7) + n) >> 3;    // "Dampened" reading (else looks twitchy)

  // Calculate bar height based on dynamic min/max levels (fixed point):
  height = TOP * (lvl - minLvlAvg) / (long)(maxLvlAvg - minLvlAvg);

  if(height < 0L)       height = 0;      // Clip output
  else if(height > TOP) height = TOP;
  if(height > peak)     peak   = height; // Keep 'peak' dot at top


  // Color pixels based on rainbow gradient
  for(i=0; i<N_PIXELS; i++) {
    if(i >= height)               strip.setPixelColor(i,   0,   0, 0);
    else strip.setPixelColor(i,Wheel(map(i,0,strip.numPixels()-1,30,150)));

  }



  // Draw peak dot 
  if(peak > 0 && peak <= N_PIXELS-1) strip.setPixelColor(peak,Wheel(map(peak,0,strip.numPixels()-1,30,150)));

   strip.show(); // Update strip

// Every few frames, make the peak pixel drop by 1:

    if(++dotCount >= PEAK_FALL) { //fall rate

      if(peak > 0) peak--;
      dotCount = 0;
    }



  vol[volCount] = n;                      // Save sample for dynamic leveling
  if(++volCount >= SAMPLES) volCount = 0; // Advance/rollover sample counter

  // Get volume range of prior frames
  minLvl = maxLvl = vol[0];
  for(i=1; i<SAMPLES; i++) {
    if(vol[i] < minLvl)      minLvl = vol[i];
    else if(vol[i] > maxLvl) maxLvl = vol[i];
  }
  // minLvl and maxLvl indicate the volume range over prior frames, used
  // for vertically scaling the output graph (so it looks interesting
  // regardless of volume level).  If they're too close together though
  // (e.g. at very low volume levels) the graph becomes super coarse
  // and 'jumpy'...so keep some minimum distance between them (this
  // also lets the graph go to zero when no sound is playing):
  if((maxLvl - minLvl) < TOP) maxLvl = minLvl + TOP;
  minLvlAvg = (minLvlAvg * 63 + minLvl) >> 6; // Dampen min/max levels
  maxLvlAvg = (maxLvlAvg * 63 + maxLvl) >> 6; // (fake rolling average)

}
    }
 else {
  if(y<1){
  z--;
  y++;
  }
  mp3_stop ();


      for(int i=0; i<NUMPIXELS; i++) { // For each pixel...

    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a moderately bright green color:
    pixels.setPixelColor(i, pixels.Color(200, 200, 200));
   pixels.show();
    
  }
}
}
