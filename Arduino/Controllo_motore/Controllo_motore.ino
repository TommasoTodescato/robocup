 
#define M2INA 13    //definisco i vari pin necessari per il funzionamento dei motori, ingresso A, B e PWM//              
#define M2INB 12
#define M2PWM 11
#define M1INA 8  
#define M1INB 7 
#define M1PWM 6

 

void setup() {
  pinMode(13, INPUT);     //imposto i vari pin di INPUT e OUTPUT
  pinMode(12, INPUT); 
  pinMode(11, OUTPUT);
  pinMode(7, INPUT); 
  pinMode(8, INPUT); 
  pinMode(6, OUTPUT);
}

void loop() {
  digitalWrite (13, HIGH);
  digitalWrite (12, LOW);
  analogWrite (11, 100);     //imposto la velocità, indicando prima il pin PWM e successivamente il valore della velocità (da 0 a 255)
  digitalWrite (7, HIGH);
  digitalWrite (8, LOW);
  analogWrite (6, 100);

  
}
