#include <MPU6050_tockn.h>
#include <Wire.h>

// GENERALI



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

int media_avanti = 0, media_dietro = 0; 
int start_values[16];


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
void setGyroZero()
{
  gyroBaseX = mpu.getAngleX();
}

//INFRA MEDIA
void Set_Infra(){
  
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
    Serial.println(start_values[i]);
  }
 

  
}

void Run_Infra(){
  
  for(int h = 0; h < 16; h++)
  {
    for(int i = 0; i < AVERAGE; i++)
    {
      int v = analogRead(h);
      delay(5);
      
      if (h >= AVANTI_INIZIO && h < AVANTI_FINE)
        media_avanti += v;
      else
        media_dietro += v;
    }
  }
  if (media_avanti > media_dietro)
  {
    gira(1, true, 200, 1000);
    gira(3, true, 200, 1000);
    Serial.println("avanti");
    //Serial.println(media_avanti);
    //Serial.println(media_dietro);
  }

  else
    Serial.println("dietro");
    gira(1, true, 200, 1000);
    gira(3, false, 200, 1000);
    gira(2, true, 200, 500);

    gira(1, true, 200, 1000);
    gira(3, true, 200, 1000);

  media_avanti = media_dietro = 0;

}

void setup()
{
  Serial.begin(1200); 
  Wire.begin();
  setGyroZero();
  Set_Infra(); 
  Serial.println("settato"); 
  Serial.println("run"); 
  
  
 
}

void loop()
{
  mpu.update();
  gyroX = mpu.getAngleX();

  // conviene fare tutti piccoli intervalli
  // se >= 0 (o viceversa) va avanti
  if (gyroX >= 0)
  {
    gira(1, true, 200, 1000);
  }
  else
  {
    //direzione;
  }


  mpu.getGyroAngleX();

  
  Run_Infra(); 

 
}
