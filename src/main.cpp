#include <Arduino.h>
#include <Wire.h>
#include "FXAS21002C_Basic.h"
#include "FXOS8700Q_Basic.h"
#include "MS5837.h"
#include "MadgwickAHRS.h"

TwoWire wire(PB7 , PB6);
Madgwick Filter;
float Acc[3]   , pitch , roll , yaw;
float Mag[3]  ;
float Gyr[3]  ;
int prevTime;

// MS5837 Bar ;

FXAS21002CBasic Gyro;      // Gyroscope sensor class declaration (0x21 , &Wire1)
FXOS8700QBasic AcMg;   // Magnetometer and Accelerometer sensors classes declarations (1 , 0x1F , &Wire1)
float present , gyro_sum[3] {0.0 , 0.0 , 0.0} ;
int it;
// float pres, prev;

void setup() {
  it = 0;
  // put your setup code here, to run once:
  wire.begin();
  Serial.begin(9600);
  AcMg = FXOS8700QBasic(1 , 0x1F , &wire);
  Gyro = FXAS21002CBasic(0x21 , &wire);
  // while(!Bar.begin(Wire1)){
  //   Serial.println("Bar02 - Init Failed!!\nTry Again");
  //   delay(1000);
  // };
  // Bar.setModel(MS5837::MS5837_02BA);
  // Bar.setFluidDensity(997);
  delay(100);
  prevTime = millis();
}

void loop() {
  prevTime = millis();
    // Bar.read();
    // Serial.print("Depth : ");
    // Serial.println(Bar.depth());
    // delay(1000);
    Gyro.updateGyroData(&Gyr[0]);
    AcMg.updateAccelMagData(&Acc[0] , &Mag[0]);
    Filter.update(Gyr[0] , Gyr[1] , Gyr[2] , Acc[0] , Acc[1] , Acc[2] , Mag[0] , Mag[1] , Mag[2]);
    pitch = Filter.getPitch(); roll = Filter.getRoll() ; yaw = Filter.getYaw();
    Serial.print(pitch); Serial.print("\t"); Serial.print(roll); Serial.print("\t"); Serial.println(yaw);
  delay(4 - (millis() - prevTime));
    /*
    Serial.print("Acc : ");
    Serial.print(Acc[0]);Serial.print("\t");  //Acc along X
    Serial.print(Acc[1]);Serial.print("\t");  //Acc along Y
    Serial.println(Acc[2]);                   //Acc along Z
    Serial.print("Gyro : ");
  
    Serial.print(Gyr[0]);Serial.print("\t");  //Gyro along X
    Serial.print(Gyr[1]);Serial.print("\t");  //Gyro along Y
    Serial.println(Gyr[2]);                   //Gyro along Z
    
    Serial.print("Mag : ");
    Serial.print(Mag[0]);Serial.print("\t");  //Mag along X
    Serial.print(Mag[1]);Serial.print("\t");  //Mag along Y
    Serial.println(Mag[2]);                   //Mag along Z
    */
 
  
 
}