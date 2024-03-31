int AIN1 = 2;
int AIN2 = 3;
int STBY = 4;
int BIN1 = 5;
int BIN2 = 6;
int PWMA = 10;  // enable pin 1
int PWMB = 11;  // enable pin 2
// D2 and D3 as a set, D5 and D6 as a set
// D10 and D11 as enable pins for DC motors
void setup()
{
  int i;
  for (i = 2; i <= 6; i++)  // Ardunio motor driver module
    pinMode(i, OUTPUT);     // set digital pins 2,3,4,5,6 as output

  pinMode(10, OUTPUT);      // set digital pins 10, 11 as output
  pinMode(11, OUTPUT);
}
void loop()
{
  // 2 DC motor rotate CW for 1S, and rotate CCW for 1S
  // rotate CW
  digitalWrite(STBY, HIGH);

  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  analogWrite(PWMA, 200);

  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, LOW);
  analogWrite(PWMB, 200);
  delay(1000);

  digitalWrite(STBY, LOW);
  delay(1000);
  // rotate CCW
  digitalWrite(STBY, HIGH);
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, HIGH);
  analogWrite(PWMA, 100);

  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, HIGH);
  analogWrite(PWMB, 100);
  delay(1000);
  
  digitalWrite(STBY, LOW);
  delay(1000);
}