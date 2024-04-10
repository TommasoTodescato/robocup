#include <MPU6050_tockn.h>
#include <Wire.h>

// DRIVER
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
#define AVERAGE 10
#define AVANTI_INIZIO 4
#define AVANTI_FINE 12
#define DIETRO_INIZIO 5
#define DIETRO_FINE 11

long media_avanti = 0, media_dietro = 0;
long start_avanti = 0, start_dietro = 0;
double start_rapporto = 0.0;

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
    
    case 4:
      digitalWrite(A_STBY, HIGH);
      delay(1); 
      digitalWrite(B_STBY, HIGH);

      digitalWrite(A_AIN1, senso);
      digitalWrite(A_AIN2, !senso);
      analogWrite(A_PWMA, potenza);
      digitalWrite(B_BIN1, senso);
      digitalWrite(B_BIN2, !senso);
      analogWrite(B_PWMB, potenza);

      delay(millis);      
      digitalWrite(A_STBY, LOW);
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
  delay(500);

  for (int i = 0; i < AVERAGE; i++)
  {
    for (int h = 0; h < 16; h++)
    {
      int v = analogRead(h);
      delay(2);

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

  start_rapporto = (double)start_avanti / (double)start_dietro;

  Serial.print("start_avanti: ");
  Serial.println(start_avanti);
  Serial.print("start_dietro: ");
  Serial.println(start_dietro);
  Serial.print("rapporto: ");
  Serial.println(start_rapporto);
  
  delay(500);
}

void Run_Infra()
{
  delay(500);
  for(int i = 0; i < AVERAGE; i++)
  {
    for(int h = 0; h < 16; h++)
    {
      int v = analogRead(h);
      delay(2);
      
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

  double rapp = (double)media_avanti / (double)media_dietro;
  if (rapp > start_rapporto)
  {
    Serial.print("avanti : ");
    Serial.print(rapp);
    Serial.print(" / ");
    Serial.println(media_avanti + media_dietro);
    Serial.println(media_avanti);
    Serial.println(media_dietro);
    
    gira(4, false, 200, 2000);
  }
  else
  {
    Serial.print("dietro : ");
    Serial.print(rapp);
    Serial.print(" / ");
    Serial.println(media_avanti + media_dietro);
    Serial.println(media_avanti);

    Serial.println(media_dietro);

  //   gira(1, true, 200, 1000);
  //   gira(3, false, 200, 1000);
  //   gira(2, true, 200, 1000);
  //   delay(500);
  //   gira(1, true, 200, 2000);
  //   gira(3, true, 200, 2000);
  }
  media_avanti = media_dietro = 0;
}

void setup()
{
  for (int i = 2; i < 14; i++)
    pinMode(i, OUTPUT);
  
  Serial.begin(9600); 
  Wire.begin();
  SetGyroZero();
  Set_Infra();
}

void loop()
{
  Run_Infra();
} 
