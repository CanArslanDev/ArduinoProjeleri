//--------------------------------------------------------------------------------------------------
#include <SoftwareSerial.h>
#include <DFPlayer_Mini_Mp3.h>
SoftwareSerial secondarySerial(7, 8); // RX, TX
//
void setup () {
 pinMode(5,INPUT_PULLUP); 
 pinMode(6,INPUT_PULLUP); 

secondarySerial.begin (9600);
mp3_set_serial (secondarySerial); //set Serial for DFPlayer-mini mp3 module
mp3_set_volume (100);
}


//
void loop () {        
  if(digitalRead(5)==LOW){mp3_play (1);delay(1000);}
  if(digitalRead(6)==LOW){mp3_play (2);delay(1000);}
}
