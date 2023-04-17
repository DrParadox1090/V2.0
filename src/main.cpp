#include <FXAS21002C_Basic.h>
#include <FXOS8700Q_Basic.h>
#include <i2cdevice.h>
//#include <dig_hpf.h>
#include <MadgwickAHRS.h>
#include <Mahony\Mahony.h>

TwoWire Wire1(PB7 , PB6);
//Data Array Declarations
float Acc[3]  ;
float Mag[3]  ;
float Gyr[3]  ;
//float tb[3] {0};

//Class Declarations
FXAS21002CBasic Gyro(0x21 , &Wire1);      // Gyroscope sensor class declaration
FXOS8700QBasic AcMg(1 , 0x1F , &Wire1);   // Magnetometer and Accelerometer sensors classes declarations
Madgwick Filter;
// highpass R(0.98);
// highpass P(0.98);
// highpass Y(0.98);
float present ;
float tb[3];
/*
lowpass Gx , Gy , Gz ;    
lowpass Mx , My , Mz ;
*/
// float alpha = 0.9 ;
// float roll , pitch , yaw ;
// float tb_a[3] {0};
// float tb_g[3] {0};
// float g_min[3] {0};
// float g_max[3] {0};
// float sum[3] {0}; float n = 0;

// float pres, prev;

void setup() {
  // put your setup code here, to run once:
  Wire1.begin();
  Serial.begin(9600);
  delay(100);
  present = millis();
}

void loop() {
  // for(int i = 0 ; i < 128 ; i++){
  //   Wire1.beginTransmission(i);
  //   if(Wire1.endTransmission() == 0 ){
  //     Serial.print("I2C found at 0x");
  //     Serial.println(i , HEX);
  //   }
  // }
  Gyro.updateGyroData(&Gyr[0]);
  AcMg.updateAccelMagData(&Acc[0] , &Mag[0]);

  Filter.update(Gyr[0] , Gyr[1] , Gyr[2] , Acc[0] , Acc[1] , Acc[2] , Mag[0] , Mag[1] , Mag[2] );
    Serial.print("Orientation: ");
    Serial.print(Filter.getYaw());
    Serial.print(" ");
    Serial.print(Filter.getPitch());
    Serial.print(" ");
    Serial.println(Filter.getRoll());
  /*
  float dt = 0.01;
  
  sf.update(&tb[0] , &Acc[0] , &Gyr[0] , dt);
  // for(int i = 0 ; i < 3 ; i++){
  //   tb_g[i] = Gyr[i] * dt;
  // }
  // tb_a[0] = atan((Acc[1])/sqrt(pow((Acc[0]) , 2) + pow((Acc[2]) , 2))) * (180.0/3.14);
  // tb_a[1] = atan(-1*(Acc[0])/sqrt(pow((Acc[1]) , 2) + pow((Acc[2]) , 2))) * (180.0/3.14);
  // tb_a[2] = atan((Acc[2])/sqrt(pow((Acc[0]) , 2) + pow((Acc[1]) , 2))) * (180.0/3.14);

  // tb_g[0] = R.filter_hp(tb_g[0]);
  // tb_g[1] = P.filter_hp(tb_g[1]);
  // tb_g[2] = Y.filter_hp(tb_g[2]);

  // roll = (alpha)*(roll+tb_g[0]) + (1- alpha)*tb_a[0];
  // pitch = (alpha)*(pitch+tb_g[1]) + (1- alpha)*tb_a[1];
  // yaw = (alpha)*(yaw+tb_g[2]) + (1- alpha)*tb_a[2];
  // put your main code here, to run repeatedly:
  // Serial.print(tb[0]);
  // Serial.print(' ');
  // Serial.print(tb[1]);
  // Serial.print(' ');
  // Serial.print(tb[2]);
  // Serial.println();
  // delay(10);

  
    TYPICAL MAGNETIC FIELD COMPONENTS : @ CHENNAI in uT

    North/South (X) :   + 40.6619
    East/West   (Y) :   -  0.8715
    Vertical    (Z) :   + 10.8152 

    Total Field : 42.0847 uT
  
  
 
  Serial.print(Mag[0]);
  Serial.print(" ");
  Serial.println(Mag[1]);
  Serial.print(" ");
  Serial.println(Mag[2]);
  
  delay(2000);
  */
//  Serial.print("Raw:");
//  for(int i = 0 ; i < 3 ; i++){
//       Serial.print((Acc[i] ));
//       Serial.print(",");
//  }
//  for(int i = 0 ; i < 3 ; i++){
//       Serial.print((Gyr[i] ));
//       Serial.print(",");
//  }
//  for(int i = 0 ; i < 3 ; i++){
//       Serial.print(int(Mag[i] *10));
//       if(i != 2 ){
//         Serial.print(",");
//       }
//  }
//  Serial.println();
//  delay(100);

}