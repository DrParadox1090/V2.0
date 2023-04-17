#include "dig_hpf.h"

highpass::highpass(float Beta , int N){
     Init_hpf(Beta , N);
}

void highpass::Init_hpf(float b , int N){
     beta = b;
     n = N;
     float a[n];
     float a1[n];

     x = &a[0];
     y = &a1[0];

}
// input - pointer to Array of indv inputs that needs to be filterd
//   y   - pointer of array of filtered outputs for the given inputs
void highpass::filter_hp(float *input){
    for(int i = 0 ; i < n ; i ++){
        y[i] = (0.5)*(2.0 - beta)*(input[i] - x[i] ) + (1.0 - beta)*y[i];
        x[i] = input[i];
        input[i] = y[i];
    }
    
}