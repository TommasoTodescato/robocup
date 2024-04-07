#define AVERAGE 20

long cont = 0, sum = 0, start_value = 0; 
int v = 0;

void setup() {
  Serial.begin(1200); 
  for (int i = 0; i < AVERAGE; i++)
  {
    start_value += analogRead(0);
  }
  start_value = start_value / AVERAGE;
  Serial.println(start_value);
}

void loop() {
  for(int h = 0; h < 16; h++){
    for(int i = 0; i < AVERAGE; i++){
      delay(5); 
      v = analogRead(h);
      sum += v;
      cont++;
    }
     
    if (cont >= AVERAGE)
    {
      long diff = start_value - (sum / AVERAGE);
      Serial.print(h);
      Serial.print(":");  
      Serial.println((start_value) - (sum / AVERAGE));
      cont = sum = 0;
      if (diff > 50)
        Serial.println("ok");
    }
  }
}
