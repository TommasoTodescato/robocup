#define M1INA 14
#define M1INB 15
#define M1PWM 2

void setup() {
pinMode(14, INPUT); 
pinMode(15, INPUT); 
pinMode(2, OUTPUT); 

}

void loop() {
 digitalWrite(14, HIGH);
 digitalWrite(15, LOW);  
 
 analogWrite(2, 0); 
}
