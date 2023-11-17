#define TrigPin = 5; 
#define EcoPin = 4; 
#define motore1 = 13; 
int durata; 
int cm; 
void setup() {
   Serial.begin(9600); 
  pinMode(13, OUTPUT);

  pinMode(4, INPUT); 
  pinMode(5, OUTPUT);  
}

void loop() {
   digitalWrite(5, LOW);
  delayMicroseconds(2);
  digitalWrite(5, HIGH);
  delay(100);
  digitalWrite(5, LOW);
  durata = pulseIn(4, HIGH);
  cm = durata / 58;
  Serial.print(cm); 
  if(cm<=12){
    digitalWrite(13, LOW);
  }
  else{
    digitalWrite(13, HIGH);
  }
    

}
