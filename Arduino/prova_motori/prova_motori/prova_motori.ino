#define TrigPin = 2; 
#define EcoPin = 3; 
#define motore1 = 13; 
int durata; 
int cm; 
void setup() {
   Serial.begin(9600); 
  pinMode(13, OUTPUT);
  pinMode(3, INPUT); 
  pinMode(2, OUTPUT);  
}

void loop() {
   digitalWrite(2, LOW);
  delayMicroseconds(2);
  digitalWrite(2, HIGH);
  delay(100);
  digitalWrite(2, LOW);
  durata = pulseIn(3, HIGH);
  cm = durata / 58;
  Serial.print(cm); 
  if(cm<=12){
    digitalWrite(13, LOW);
  }
  else{
    digitalWrite(13, HIGH);
  }
    

}
