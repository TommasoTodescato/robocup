int led = 13;  
void setup() {
  pinMode(8, INPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600); 
}

void loop() {
int luce= analogRead(A0); 
Serial.println(luce);
delay(100); 
if (luce <= 100){
  digitalWrite(led, HIGH); 
}
else{
  digitalWrite(led, LOW); 
}
}
