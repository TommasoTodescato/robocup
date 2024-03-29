
#include <MPU6050_tockn.h>
#include <Wire.h>

MPU6050 mpu6050(Wire); 

void setup() {
  Serial.begin(9600); 
  Wire.begin(); 
  mpu6050.begin(); 
  mpu6050.calcGyroOffsets(true); 

}

unsigned long t1, dt; 

float x,y; 

void loop() {
  mpu6050.update(); 
  dt = millis() - t1; 
 
    t1 = millis(); 
    Serial.println(mpu6050.getGyroAngleX()); 
    //Serial.println(mpu6050.getGyroAngleY()); 
   
  
  

}
