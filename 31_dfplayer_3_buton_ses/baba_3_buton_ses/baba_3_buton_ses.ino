//--------------------------------------------------------------------------------------------------
#include <SoftwareSerial.h>
#include <DFPlayer_Mini_Mp3.h>
SoftwareSerial secondarySerial( 10, 11); // RX, TX
int x=0;
int y=0;
//----------------------------------------------
void setup () {
   pinMode(7,INPUT); 
 pinMode(6,INPUT); 
 pinMode(5,INPUT); 

secondarySerial.begin (9600);
mp3_set_serial (secondarySerial); //set Serial for DFPlayer-mini mp3 module
mp3_set_volume (100);
}


//
void loop () {  
 if(digitalRead(7)==HIGH){if(x<1){x++;mp3_play (3);delay(1000);}}
 else{x=0;}   
  if(digitalRead(5)==HIGH){mp3_play (2);delay(1000);}
  if(digitalRead(6)==HIGH){if(y<1){y++;mp3_play (1);}}
 else{y=0;}   
}
