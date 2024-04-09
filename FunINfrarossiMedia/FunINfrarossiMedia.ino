#define AVERAGE 20
#define AVANTI_INIZIO 4
#define AVANTI_FINE 12
#define DIETRO_INIZIO 5
#define DIETRO_FINE 11

long media_avanti = 0, media_dietro = 0;
long start_avanti = 0, start_dietro = 0;

void setup()
{
  Serial.begin(9600);

  for (int i = 0; i < AVERAGE; i++)
  {
    for (int h = 0; h < 16; h++)
    {
      int v = analogRead(h);
      delay(5);

      if (h >= AVANTI_INIZIO && h <= AVANTI_FINE)
      {
        start_avanti += v;
      }
      else
      {
        start_dietro += v;
      }
    }
  }
  
  delay(1000);
}

void loop()
{
  delay(1000);
  for(int i = 0; i < AVERAGE; i++)
  {
    for(int h = 0; h < 16; h++)
    {
      int v = analogRead(h);
      delay(5);
      
      if (h >= AVANTI_INIZIO && h <= AVANTI_FINE)
      {
        media_avanti += v;
      }
      else
      {
        media_dietro += v;
      }
    }
  }
  
  media_avanti -= start_avanti;
  media_dietro -= start_dietro;
  media_dietro -= 270; 
  media_avanti = abs(media_avanti); 
  media_dietro = abs(media_dietro); 
  if (media_avanti > media_dietro)
  {
    Serial.println("avanti");
    Serial.println(media_avanti);
    Serial.println(media_dietro);
  }
  else
  {
    Serial.println("dietro");
    Serial.println(media_avanti);
    Serial.println(media_dietro);
  }

  media_avanti = media_dietro = 0;
}
