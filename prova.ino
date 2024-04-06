int cont = 0, sum = 0, start_value = 0;

void setup() {
  Serial.begin(9600); 
  for (int i = 0; i < 10; i++)
  {
    start_value += analogRead(0);
  }
  start_value = start_value / 10;
  Serial.println(start_value);
}

void loop() {
  delay(5); 
  int v0 = analogRead(s0);
  sum += v0;
  cont++; 
  if (cont >= 10)
  {
    Serial.println((start_value) - (sum / 10));
    cont = sum = 0;
  }
}
