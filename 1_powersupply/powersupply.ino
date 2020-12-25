#include <SimpleSDAudio.h>

volatile int mode = 0;
volatile int one = 0;
volatile int led = 0;
volatile long stime = 0;
volatile long ftime = 0;
//-Inıt Chip
void setup()
{
  pinMode(2, INPUT); //LED line input
  SdPlay.setSDCSPin(10);
  SdPlay.init(SSDA_MODE_FULLRATE | SSDA_MODE_MONO | SSDA_MODE_AUTOWORKER);
  attachInterrupt(digitalPinToInterrupt(2), kontrol, FALLING);
}

//-ISR
void kontrol() {

  ftime = millis() - stime;
  stime = millis();
  if (ftime > 300) {
    mode = 3;//yedek güç tükeniyor
  }
  if (ftime > 1000) {
    mode = 2;//yedek güç devrede
  }
  if (ftime > 3000) {//default 3000
    mode = 0;
  }
}


//-Main
void loop(void) {
  delay(3000);//interrupt tetiklenmesi için bekle
  if (mode >= 0) {
    //interrupt geçici devre dışı seslerin çalması bitene kadar bekletilecek
    detachInterrupt(digitalPinToInterrupt(2));
    led = pulseIn(2, LOW, 3000000);//3sn zaman dilimi içinde ölçme yap
    if (led == 0) {
      if (digitalRead(2)) {//2 pinin true false kontrolü değeri TRUE ise
        mode = 1;
      }
      if (!digitalRead(2)) {//2 pinin true false kontrolü değeri FALSE ise (ElkKesik-edek güç tükendi)
        mode = 4;
      }
    }

  }

  //-------------------------------------------
  
  if (mode == 1 && one == 1 ) {
    SdPlay.setFile("upsoff.wav");//Elektrik geldi-yedek güç devre dışı
    SdPlay.play();
    delay(8 * 1000);
    SdPlay.stop();
    one = 0;  //TODO:finalde kullanılacak sadece 1 kez mesaj verecek
  }

  if (mode == 2) {
    SdPlay.setFile("upson.wav");//Elektrik kesik-yedek güç devrede
    SdPlay.play();
    delay(8 * 1000);
    SdPlay.stop();
    one = 1;
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
  delay(1000*60);// mesajların çevrim süresi
  // interrupt tekrar aktifleştirildi
  attachInterrupt(digitalPinToInterrupt(2), kontrol, FALLING);
}
