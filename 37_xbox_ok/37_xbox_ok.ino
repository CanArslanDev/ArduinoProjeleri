#include <SoftwareSerial.h>
#include <DFPlayer_Mini_Mp3.h>
#include <Adafruit_NeoPixel.h>
#include "FastLED.h"
#include <EEPROM.h>
#define N_PIXELS  8  // Number of pixels in strand
#define MIC_PIN   A5  // Microphone is attached to this analog pin
#define LED_PIN    8  // NeoPixel LED strand is connected to this pin
#define DC_OFFSET  0  // DC offset in mic signal - if unusure, leave 0
#define NOISE     70  // Noise/hum/interference in mic signal
#define SAMPLES   40  // Length of buffer for dynamic level adjustment
#define TOP       (N_PIXELS + 2) // Allow dot to go slightly off scale
#define PEAK_FALL 20  // Rate of peak falling dot

byte
  peak      = 0,      // Used for falling dot
  dotCount  = 0,      // Frame counter for delaying dot-falling speed
  volCount  = 0;      // Frame counter for storing past volume data
int
  vol[SAMPLES],       // Collection of prior volume samples
  lvl       = 20,      // Current "dampened" audio level
  minLvlAvg = 0,      // For dynamic adjustment of graph low & high
  maxLvlAvg = 512;
#define NUM_LEDS 8 
CRGB leds[NUM_LEDS];
#define PIN 5 
int qa = 0;
int sound = 0;
int sound1 = 0;
int neopixel = 0;
int soundv = 0;
const int ledPin = 5;     // the number of the neopixel strip
const int numLeds = 8;
Adafruit_NeoPixel strip = Adafruit_NeoPixel(numLeds, ledPin, NEO_GRB + NEO_KHZ800);
SoftwareSerial secondarySerial(7, 8); // RX, TX
 SoftwareSerial bt_iletisim(2,3);
void setup() {
    Serial.begin(9600);
    bt_iletisim.begin(9600);
secondarySerial.begin (9600);
mp3_set_serial (secondarySerial); //set Serial for DFPlayer-mini mp3 module
mp3_set_volume (20);
analogReference(EXTERNAL);
  memset(vol, 0, sizeof(vol));
   strip.begin();
  strip.setBrightness(80); // 1/3 brightness
  delay(1000);
mp3_play (1);
//delay(3000);
 FastLED.addLeds<WS2811, PIN, GRB>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
 for(int i=0; i<2; i++){
//   rainbow(30);
 rainbowCycle(20);
 }
}

void loop() {
  sound=0;
  sound1=0;
  if(neopixel == 0){
   CylonBounce(0, 255, 0, 1, 10, 50);
  }
    if(neopixel == 1){
   rainbowCycle(20);
  }
     if(neopixel == 2){
    meteorRain(0,255,0,10, 64, true, 30);
  }
       if(neopixel == 3){
   RunningLights(0,255,0, 50);
  }
  if(neopixel == 4){
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
  if(soundv==1){
    mp3_set_volume(5);
  }
    if(soundv==2){
    mp3_set_volume(10);
  }
    if(soundv==3){
    mp3_set_volume(15);
  }
    if(soundv==4){
    mp3_set_volume(20);
  }
    if(soundv==5){
    mp3_set_volume(25);
  }
    if(soundv==6){
    mp3_set_volume(30);
  }
   bt_iletisim.listen();
  if(bt_iletisim.available())
   {
    char data=bt_iletisim.read();
     Serial.println(data);
     {
if(data=='1')
{
  if(sound<1){
    mp3_play(3);
//mp3_next ();
sound++;  
  }
  neopixel=4;
 }
if(data=='2')
{
  if(sound<1){
    mp3_play(4);
//mp3_next ();
sound++;  
  }
 neopixel=4;
 }
if(data=='3')
{
  if(sound<1){
    mp3_play(5);
//mp3_next ();
sound++;  
  }
   neopixel=4;
}
if(data=='4')
{
  if(sound<1){
    mp3_play(6);
//mp3_next ();
sound++;  
  }
  neopixel=4;
  }
  if(data=='5')
{
  if(sound<1){
    mp3_play(7);
//mp3_next ();
sound++;  
  }
  neopixel=4;
  }
if(data=='s')
{
if(soundv==7){
  soundv=0;
}
else{
  soundv++;
}
}
if(data=='d')
{
  //secondarySerial.listen();
   mp3_pause ();
//bt_iletisim.listen();
}
if(data=='v')
{
  //secondarySerial.listen();
   mp3_play ();
//bt_iletisim.listen();
}
if(data=='l')
{
  mp3_set_volume (20);
mp3_play (2);
}
if(data=='f')
{
  if(neopixel==4){
    neopixel=0;
  }
  else{
neopixel++;
}}
}
}
}
void RunningLights(byte red, byte green, byte blue, int WaveDelay) {
  int Position=0;
 
  for(int j=0; j<30*2; j++)
  {
      Position++; // = 0; //Position + Rate;
      for(int i=0; i<30; i++) {
        // sine wave, 3 offset waves make a rainbow!
        //float level = sin(i+Position) * 127 + 128;
        //setPixel(i,level,0,0);
        //float level = sin(i+Position) * 127 + 128;
        setPixel(i,((sin(i+Position) * 127 + 128)/255)*red,
                   ((sin(i+Position) * 127 + 128)/255)*green,
                   ((sin(i+Position) * 127 + 128)/255)*blue);
      }
     
      showStrip();
      delay(WaveDelay);
  }
}
void meteorRain(byte red, byte green, byte blue, byte meteorSize, byte meteorTrailDecay, boolean meteorRandomDecay, int SpeedDelay) {  
  setAll(0,0,0);
 
  for(int i = 0; i < 30+30; i++) {
   
   
    // fade brightness all LEDs one step
    for(int j=0; j<30; j++) {
      if( (!meteorRandomDecay) || (random(10)>5) ) {
        fadeToBlack(j, meteorTrailDecay );        
      }
    }
   
    // draw meteor
    for(int j = 0; j < meteorSize; j++) {
      if( ( i-j <30) && (i-j>=0) ) {
        setPixel(i-j, red, green, blue);
      }
    }
   
    showStrip();
    delay(SpeedDelay);
  }
}

void fadeToBlack(int ledNo, byte fadeValue) {
 #ifdef ADAFRUIT_NEOPIXEL_H
    // NeoPixel
    uint32_t oldColor;
    uint8_t r, g, b;
    int value;
   
    oldColor = strip.getPixelColor(ledNo);
    r = (oldColor & 0x00ff0000UL) >> 16;
    g = (oldColor & 0x0000ff00UL) >> 8;
    b = (oldColor & 0x000000ffUL);

    r=(r<=10)? 0 : (int) r-(r*fadeValue/256);
    g=(g<=10)? 0 : (int) g-(g*fadeValue/256);
    b=(b<=10)? 0 : (int) b-(b*fadeValue/256);
   
    strip.setPixelColor(ledNo, r,g,b);
 #endif
 #ifndef ADAFRUIT_NEOPIXEL_H
   // FastLED
   leds[ledNo].fadeToBlackBy( fadeValue );
 #endif  
}
void CylonBounce(byte red, byte green, byte blue, int EyeSize, int SpeedDelay, int ReturnDelay){

  for(int i = 0; i < NUM_LEDS-EyeSize-2; i++) {
    setAll(0,0,0);
    setPixel(i, red/10, green/10, blue/10);
    for(int j = 1; j <= EyeSize; j++) {
      setPixel(i+j, red, green, blue); 
    }
    setPixel(i+EyeSize+1, red/10, green/10, blue/10);
    setPixel(i+EyeSize+2, red/10, green/50, blue/10);
    setPixel(i+EyeSize+3, red/10, green/50, blue/10);
    setPixel(i+EyeSize+4, red/10, green/50, blue/10);
    setPixel(i+EyeSize+5, red/10, green/50, blue/10);
    setPixel(i+EyeSize+6, red/10, green/50, blue/10);
    setPixel(i+EyeSize+7, red/10, green/50, blue/10);
    setPixel(i+EyeSize+8, red/10, green/50, blue/10);
    setPixel(i+EyeSize-1, red/10, green/50, blue/10);
    setPixel(i+EyeSize-2, red/10, green/50, blue/10);
    setPixel(i+EyeSize-3, red/10, green/50, blue/10);
    setPixel(i+EyeSize-4, red/10, green/50, blue/10);
    setPixel(i+EyeSize-5, red/10, green/50, blue/10);
    setPixel(i+EyeSize-6, red/10, green/50, blue/10);
    setPixel(i+EyeSize-7, red/10, green/50, blue/10);
    setPixel(i+EyeSize-9, red/10, green/50, blue/10);
    showStrip();
    delay(100);
  }

  delay(ReturnDelay);

  for(int i = NUM_LEDS-EyeSize-2; i > 0; i--) {
    setAll(0,0,0);
    setPixel(i, red/10, green/10, blue/10);
    for(int j = 1; j <= EyeSize; j++) {
      setPixel(i+j, red, green, blue); 
    }
    setPixel(i+EyeSize+1, red/10, green/10, blue/10);
    setPixel(i+EyeSize+2, red/10, green/50, blue/10);
    setPixel(i+EyeSize+3, red/10, green/50, blue/10);
    setPixel(i+EyeSize+4, red/10, green/50, blue/10);
    setPixel(i+EyeSize+5, red/10, green/50, blue/10);
    setPixel(i+EyeSize+6, red/10, green/50, blue/10);
    setPixel(i+EyeSize+7, red/10, green/50, blue/10);
    setPixel(i+EyeSize+8, red/10, green/50, blue/10);
    setPixel(i+EyeSize-1, red/10, green/50, blue/10);
    setPixel(i+EyeSize-2, red/10, green/50, blue/10);
    setPixel(i+EyeSize-3, red/10, green/50, blue/10);
    setPixel(i+EyeSize-4, red/10, green/50, blue/10);
    setPixel(i+EyeSize-5, red/10, green/50, blue/10);
    setPixel(i+EyeSize-6, red/10, green/50, blue/10);
    setPixel(i+EyeSize-7, red/10, green/50, blue/10);
    setPixel(i+EyeSize-9, red/10, green/50, blue/10);
    showStrip();
    delay(100);
  }
  
  delay(ReturnDelay);
}
void rainbowCycle(int SpeedDelay) {
  byte *c;
  uint16_t i, j;

  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< 30; i++) {
      c=Wheel(((i * 256 / 30) + j) & 255);
      setPixel(i, *c, *(c+1), *(c+2));
    }
    showStrip();
    delay(3);
  }
}

byte * Wheel(byte WheelPos) {
  static byte c[3];
 
  if(WheelPos < 85) {
   c[0]=WheelPos * 3;
   c[1]=255 - WheelPos * 3;
   c[2]=0;
  } else if(WheelPos < 170) {
   WheelPos -= 85;
   c[0]=255 - WheelPos * 3;
   c[1]=0;
   c[2]=WheelPos * 3;
  } else {
   WheelPos -= 170;
   c[0]=0;
   c[1]=WheelPos * 3;
   c[2]=255 - WheelPos * 3;
  }

  return c;
}
void rainbow(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel2((i*1+j) & 255));
    }
    strip.show();
    delay(10);
  }
}
uint32_t Wheel2(byte WheelPos2) {
  if(WheelPos2 < 85) {
    return strip.Color(WheelPos2 * 3, 255 - WheelPos2 * 3, 0);
  } 
  else if(WheelPos2 < 170) {
    WheelPos2 -= 85;
    return strip.Color(255 - WheelPos2 * 3, 0, WheelPos2 * 3);
  } 
  else {
    WheelPos2 -= 170;
    return strip.Color(0, WheelPos2 * 3, 255 - WheelPos2 * 3);
  }
}
//--------------------------------------------------------------------------------------------
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

// Set a LED color (not yet visible)
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
