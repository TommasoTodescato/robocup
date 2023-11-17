void setup() {
  Serial.begin(9600); 
#define s1 A1
#define s2 A2
#define s3 A3
#define s4 A4
#define s5 A5
#define s6 A7
}

void loop() {

int v1 = analogRead(s1); 
Serial.println(v1);

int v2 = analogRead(s2); 
Serial.println(v2); 

int v3 = analogRead(s3); 
Serial.println(v3); 

int v4 = analogRead(s4); 
Serial.println(v4); 

int v5 = analogRead(s5); 
Serial.println(v5); 

int v6 = analogRead(s6); 
Serial.println(v6); 

  
}
