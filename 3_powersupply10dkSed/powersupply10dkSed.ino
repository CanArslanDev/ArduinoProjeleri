#include <SimpleSDAudio.h>

volatile int mode = 0;
volatile int emode = 0;
volatile int one = 0;
volatile int sayac = 0;
volatile int led = 0;
volatile unsigned long stime = 0;
volatile unsigned long ftime = 0;
volatile unsigned long dtime = 0;
volatile unsigned long xtime = 0;
volatile unsigned long bekle=1000L*60L*15L;//600000 = 15 dakika  (1sn=1000),(1dk=60000),(10dk=600000), (15dk=900000)
//-Inıt Chip
void setup()
{
  
  Serial.begin(9600);
  pinMode(2, INPUT); //LED line input
  //Serial.begin(9600);
  SdPlay.setSDCSPin(10);
  SdPlay.init(SSDA_MODE_FULLRATE | SSDA_MODE_MONO | SSDA_MODE_AUTOWORKER);
  attachInterrupt(digitalPinToInterrupt(2), kontrol, FALLING);
}
//-----------------------------------------------------------------------------------
//-ISR

void kontrol() {

  ftime = millis() - stime;
  stime = millis();
  if (ftime > 300) {
    mode = 3; //Elektrik kesik-yedek güç tükeniyor         
  }
  if (ftime > 1000) {
    mode = 2; //Elektrik kesik-yedek güç devrede
  }
  if (ftime > 3000) {//Elektrik geldi-yedek güç devre dışı
    mode = 0;
  }
}
//-----------------------------------------------------------------------------------
void playMode() {
  if (mode == 1 && one == 1) {
    SdPlay.setFile("upsoff.wav");//Elektrik geldi-yedek güç devre dışı
    SdPlay.play();
    delay(8 * 1000);
    SdPlay.stop();
    one = 0;  //TODO:finalde kullanılacak sadece 1 kez mesaj verecek
    sayac = 0;
  }
  if (mode == 2 && sayac == 1) {
    SdPlay.setFile("upsusing.wav");//Elektrik hala kesik-yedek güç kullanılıyor
    SdPlay.play();
    delay(8 * 1000);
    SdPlay.stop();
    one = 1;
  }
  
  if (mode == 2 && sayac == 0) {
    SdPlay.setFile("upson.wav");//Elektrik kesik-yedek güç devrede
    SdPlay.play();
    delay(8 * 1000);
    SdPlay.stop();
    one = 0;
    sayac = 1;
  }
  if (mode == 3) {
    SdPlay.setFile("upslow.wav");//Elektrik kesik-yedek güç tükeniyor
    SdPlay.play();
    delay(8 * 1000);
    SdPlay.stop();
    one = 1;
  }
  if (mode == 4 ) {
    SdPlay.setFile("upsend.wav");//Elektrik kesik-yedek güç tükendi
    SdPlay.play();
    delay(8 * 1000);
    SdPlay.stop();
    one = 1;
  }
  
  // interrupt tekrar aktifleştirildi
  attachInterrupt(digitalPinToInterrupt(2), kontrol, FALLING);

}
//-----------------------------------------------------------------------------------
//-Main
void loop(void) {
  delay(3000);//interrupt tetiklenmesi için bekle
  if (mode >= 0) {
    //interrupt geçici devre dışı seslerin çalması bitene kadar bekletilecek
    detachInterrupt(digitalPinToInterrupt(2));
    led = pulseIn(2, LOW, 3000000);
    if (led == 0) {
      if (digitalRead(2)) {//2 pinin true false kontrolü değeri TRUE ise(ElkGeldi-YedekGüçDevredışı)
        mode = 1;
      }
      if (!digitalRead(2)) {//2 pinin true false kontrolü değeri FALSE ise(ElkKesik-YedekGüçTükendi)
        mode = 4;
      }
    }

    xtime = millis() - dtime;
         Serial.print("xtime:");
    Serial.println(xtime);
       Serial.print("bekle:");
    Serial.println(bekle);

    
    if (emode != mode) {
      emode = mode;
      playMode();

      dtime = millis();
      Serial.println(xtime);
    } else if (xtime > bekle) {
  
    
      playMode();
      dtime = millis();
    }
 
  }
  attachInterrupt(digitalPinToInterrupt(2), kontrol, FALLING);
}
//-----------------------------------------------------------------------------------




