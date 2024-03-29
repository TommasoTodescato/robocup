void setup() {
  Serial.begin(1200); 
#define s0 A0
#define s1 A1
#define s2 A2
#define s3 A3
#define s4 A4
#define s5 A5
#define s6 A6
#define s7 A7
#define s8 A8
#define s9 A9
#define s10 A10
#define s11 A11
#define s12 A12
#define s13 A13
#define s14 A14
#define s15 A15

}

void loop() {


int v1 = analogRead(s1); 
Serial.print(v1);
Serial.print(" ");


int v2 = analogRead(s2); 
Serial.print(v2 ); 
Serial.print(" ");

int v3 = analogRead(s3); 
Serial.print(v3 ); 
Serial.print(" ");

int v4 = analogRead(s4); 
Serial.print(v4 );
Serial.print(" "); 

int v5 = analogRead(s5); 
Serial.print(v5 ); 
Serial.print(" ");

int v6 = analogRead(s6); 
Serial.print(v6 );
Serial.print(" ");
 
int v7 = analogRead(s7); 
Serial.print(v7 );
Serial.print(" ");


int v8 = analogRead(s8); 
Serial.print(v8 ); 
Serial.print(" ");

int v9 = analogRead(s9); 
Serial.print(v9  ); 
Serial.print(" ");

int v10 = analogRead(s10); 
Serial.print(v10 ); 
Serial.print(" ");

int v11 = analogRead(s11); 
Serial.print(v11 ); 
Serial.print(" ");

int v12 = analogRead(s12); 
Serial.print(v12 ); 
Serial.print(" ");

int v13 = analogRead(s13); 
Serial.print(v13 );
Serial.print(" ");
 
int v14 = analogRead(s14); 
Serial.print(v14 ); 
Serial.print(" ");

int v15 = analogRead(s15); 

Serial.println(v15 ); 


  
}
