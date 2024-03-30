int stato= LOW; 
int led = 13; 
int bottone=8; 
void setup() {
  pinMode(led, OUTPUT); 
  pinMode(bottone, INPUT);
}

void loop() {
  if(digitalRead(7)== HIGH){
    stato= !stato;
    delay(500); 
    digitalWrite(led, HIGH);  
  }
  if(stato== HIGH){
    digitalWrite(led, HIGH); 
  }
  else{
    digitalWrite(led, LOW); 
  }

  }

