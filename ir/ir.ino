#include <limits.h>

#define SENSORS 16

int start_time;
int start[SENSORS], min[SENSORS];

int get_max(int arr[], int size)
{
  int index = 0, m = INT_MIN;
  for (int i = 0; i < size; i++)
  {
    if (arr[i] > m)
    {
      m = arr[i];
      index = i;
    }
  }
  return index;
}

void setup()
{
  Serial.begin(750);
  start_time = millis();

  for (int i = 0; i < SENSORS; i++)
    start[i] = min[i] = analogRead(i);
}

void loop()
{
  for (int i = 0; i < SENSORS; i++)
  {
    int tmp = analogRead(i);
    if (tmp < min[i])
      min[i] = tmp;
  }

  int t = millis();
  if (t - start_time >= 1000)
  {
    start_time = t;

    int diff[SENSORS];
    for (int i = 0; i < SENSORS; i++)
      diff[i] = start[i] - min[i];

    int max_index = get_max(diff, SENSORS);

    Serial.print(max_index);
    Serial.print(" / ");
    Serial.println(diff[max_index]);
    
    for (int i = 0; i < SENSORS; i++)
      start[i] = min[i] = analogRead(i);
  }
}
