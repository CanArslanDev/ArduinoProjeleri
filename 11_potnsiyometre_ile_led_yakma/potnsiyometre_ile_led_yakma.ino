int led=10;
int pot=A0;
int x;
int y;
void setup(){

  pinMode(pot,INPUT);
  pinMode(led,OUTPUT);

  

}

void loop(){
  int x = analogRead(pot);
      y = map(x,0,1023,0,255);
analogWrite(led,y);
delay(1);
}
