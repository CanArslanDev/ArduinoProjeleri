int role=2;
int sensorPin=7;
boolean val =0;

void setup(){
 pinMode(role, OUTPUT);
  pinMode(sensorPin, INPUT);
  Serial.begin (9600);
}
  
void loop (){
  val =digitalRead(sensorPin);
  Serial.println (val);
  // when the sensor detects a signal above the threshold value, LED flashes
  if (val==HIGH) {
 digitalWrite(role, HIGH);
 delay(2000);
     digitalWrite(role, LOW);
     delay(3600000); //delay(3600000);
  }
  else {
     digitalWrite(role, LOW);
  }
}
