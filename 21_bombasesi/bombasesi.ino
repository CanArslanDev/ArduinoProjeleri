int ledPin=8;
int butonPin=9;
int butonDurum=0;
void setup(){
  
  pinMode(ledPin,OUTPUT); //led pinimizi çıkıs ayarladık
  pinMode(butonPin,INPUT); // buton pinimizi giriş ayarladık
 
}
void loop(){
  
  butonDurum=digitalRead(butonPin); // dijital olarak okuduk 
  if(butonDurum==HIGH){
 
    digitalWrite(ledPin,HIGH);
    delay(3000);
    digitalWrite(ledPin,LOW);
    delay(2700);
    digitalWrite(ledPin,HIGH);
    delay(2500);
    digitalWrite(ledPin,LOW);
    delay(2300);
    digitalWrite(ledPin,HIGH);
    delay(2000);
    digitalWrite(ledPin,LOW);
    delay(1800);
    digitalWrite(ledPin,HIGH);
    delay(1600);
    digitalWrite(ledPin,LOW);
    delay(1400);
    digitalWrite(ledPin,HIGH);
    delay(1200);
    digitalWrite(ledPin,LOW);
    delay(1000);
    digitalWrite(ledPin,HIGH);
    delay(800);
    digitalWrite(ledPin,LOW);
    delay(600);
    digitalWrite(ledPin,HIGH);
    delay(800);
    digitalWrite(ledPin,LOW);
    delay(600);
    digitalWrite(ledPin,HIGH);
    delay(800);
    digitalWrite(ledPin,LOW);
    delay(600);
    digitalWrite(ledPin,HIGH);
    delay(800);
    digitalWrite(ledPin,LOW);
    delay(600);
    digitalWrite(ledPin,HIGH);
    delay(400);
    digitalWrite(ledPin,LOW);
    delay(200);
    digitalWrite(ledPin,HIGH);
    delay(100);
    digitalWrite(ledPin,LOW);
    delay(1000);
    
    
 
  }else
  digitalWrite(ledPin,LOW);
 
}
