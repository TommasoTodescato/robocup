#define AVERAGE 10
#define AVANTI_INIZIO 4
#define AVANTI_FINE 12
#define DIETRO_INIZIO 5
#define DIETRO_FINE 11

long media_avanti = 0, media_dietro = 0; 
long start_values[16];

void setup()
{
  Serial.begin(9600);
  for (int i = 0; i < 16; i++){
    start_values[i] = 0;
  }
    

  for (int h = 0; h < 16; h++)
  {
    for (int i = 0; i < AVERAGE; i++)
    {
      start_values[h] += analogRead(h);
      delay(5);
    }
  }

  for (int i = 0; i < 16; i++)
  {
    start_values[i] = start_values[i] / AVERAGE;
    //Serial.println(start_values[i]);
  }
  delay(1000);
}

void loop()
{
  delay(1000);
  for(int h = 0; h < 16; h++)
  {
    for(int i = 0; i < AVERAGE; i++)
    {
      int v = analogRead(h);
      delay(5);
      
      if (h >= AVANTI_INIZIO && h <= AVANTI_FINE)
        media_avanti += v;
      else{
        
        media_dietro += v;
      }
        
    }
  }
  if (media_avanti > media_dietro)
  {
    Serial.println("avanti");
    Serial.println(media_avanti);
    Serial.println(media_dietro);
  }

  else
    Serial.println("dietro");

  media_avanti = media_dietro = 0;
}
