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
MPU6050 mpu(wire);
float gyroBaseX = 0.0f, gyroX = 0.0f;
void setGyroZero()
{
  gyroBaseX = mpu.getAngleX();
}

void setup()
{
  Serial.begin(9600);
  Wire.begin();
  setGyroZero();
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
    direzione;
  }


  mpu.getGyroAngleX();
}