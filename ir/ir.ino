void setup()
{
  Serial.begin(750);
}

void loop()
{
  delay(500);

  int m = 1024;
  for (int i = 0; i < 16; i++)
  {
    int tmp = analogRead(i);
    m = min(m, tmp);
  }
  Serial.println(m);
}
