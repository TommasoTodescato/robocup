#define MOTOR_PIN 3
#define BOTTON_PIN 4

int UltimoValore= 0; 
void setup() {
  pinMode(MOTOR_PIN, OUTPUT); 
  pinMode(BOTTON_PIN, INPUT);



}

void loop() {
  if(digitalRead(BOTTON_PIN) == HIGH){
    digitalWrite(MOTOR_PIN, HIGH); 
  }
  else{
    digitalWrite(MOTOR_PIN, LOW); 
  }
}