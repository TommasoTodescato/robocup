#include <MPU6050_tockn.h>
#include <Wire.h>

MPU6050 mpu(Wire);

void setup()
{
  Serial.begin(9600);
  Wire.begin();
  mpu.begin();
  mpu.calcGyroOffsets(true);
}

void loop()
{
  mpu.update();
  Serial.println(mpu.getGyroAngleX());
}
