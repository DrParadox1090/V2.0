#include "complementary_filter.h"

//Alpha -> close to zero (between 0.2 to 0.5)
CF::CF(float Alpha)  {
    roll = 0;
    pitch = 0 ;
    yaw = 0;
    alpha = Alpha;
}

void CF::update( float *tb ,float *acc , float *gyro , float t ){
    float dt = t;
    float tb_a[3] {0};
    float tb_g[3] {0};

    //roll and pitch estimates from filtered Gyroscope data
    for(int i = 0 ; i < 3 ; i++){
        tb_g[i] = gyro[i] * dt;
    }

    //filter_hp(&tb_g[0]);

    //roll and pitch estimates from filtered accelerometer data
    tb_a[0] = atan((acc[1])/sqrt(pow((acc[0]) , 2) + pow((acc[2]) , 2))) * (180.0/3.14);
    tb_a[1] = atan(-1*(acc[0])/sqrt(pow((acc[1]) , 2) + pow((acc[2]) , 2))) * (180.0/3.14);
    //tb_a[2] = atan((acc[2])/sqrt(pow((acc[0]) , 2) + pow((acc[1]) , 2))) * (180.0/3.14);

    roll = (1 - alpha)*(roll+tb_g[0]) + (alpha)*tb_a[0];
    pitch = (1 - alpha)*(pitch+tb_g[1]) + (alpha)*tb_a[1];
    //yaw = (1 - alpha)*(yaw+tb_g[2]) + (alpha)*tb_a[2];

    tb[0] = roll; tb[1] = pitch ; // tb[2] = yaw;
   
}

