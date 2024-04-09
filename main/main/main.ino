#include <MPU6050_tockn.h>
#include <Wire.h>

// GENERALI

// DRIVER
// driver A (destra)
// driver A (destra)
const int A_PWMA = 7;
const int A_AIN1 = 8;   // motore 1
const int A_AIN2 = 9;   // --------
const int A_STBY = 10;
const int A_BIN1 = 11;  // motore 2
const int A_BIN2 = 12;  // --------
const int A_PWMB = 13;

// driver B (sinistra)
const int B_PWMA = 2;
const int B_STBY = 3;
const int B_BIN1 = 4;   // motore 3
const int B_BIN2 = 5;   // --------
const int B_PWMB = 6;
// id motori:
//  driver A motore A -> 1
//  driver A motore B -> 2
//  driver B motore B -> 3

//INFRA
#define AVERAGE 20
#define AVANTI_INIZIO 4
#define AVANTI_FINE 12
#define DIETRO_INIZIO 5
#define DIETRO_FINE 11

long media_avanti = 0, media_dietro = 0;
long start_avanti = 0, start_dietro = 0;

bool gira(int id, bool senso, int potenza, int millis)
{
  switch(id)
  {
    case 1:
      digitalWrite(A_STBY, HIGH);
      digitalWrite(A_AIN1, senso);
      digitalWrite(A_AIN2, !senso);
      analogWrite(A_PWMA, potenza);
      delay(millis);
      digitalWrite(A_STBY, LOW);
      break;

    case 2:
      digitalWrite(A_STBY, HIGH);
      digitalWrite(A_BIN1, senso);
      digitalWrite(A_BIN2, !senso);
      analogWrite(A_PWMB, potenza);
      delay(millis);
      digitalWrite(A_STBY, LOW);
      break;

    case 3:
      digitalWrite(B_STBY, HIGH);
      digitalWrite(B_BIN1, senso);
      digitalWrite(B_BIN2, !senso);
      analogWrite(B_PWMB, potenza);
      delay(millis);
      digitalWrite(B_STBY, LOW);
      break;

    default:
      return false;
  }

  return true;
}

// GYRO
MPU6050 mpu(Wire);
float gyroBaseX = 0.0f, gyroX = 0.0f;
void SetGyroZero()
{
  gyroBaseX = mpu.getAngleX();
}

//INFRA MEDIA
void Set_Infra()
{
  
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

void Run_Infra()
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
    gira(1, true, 200, 1000);
    gira(3, true, 200, 1000);
  
  }
  else
  {
    Serial.println("dietro");
    gira(1, true, 200, 500);
    gira(3, false, 200, 500);
    gira(2, true, 200, 500);


    gira(1, true, 200, 1000);
    gira(3, true, 200, 1000);
}
 media_avanti = media_dietro = 0;
}

void setup()
{
  Serial.begin(9600); 
  Wire.begin();
    for (int i = 2; i < 14; i++){
    pinMode(i, OUTPUT);
}
  SetGyroZero();
  Set_Infra();
}

void loop()
{
  
 
  Run_Infra(); 
  
  }

 

