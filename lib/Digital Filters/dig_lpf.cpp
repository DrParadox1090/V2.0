#include "dig_lpf.h"

lowpass::lowpass(float alp){
    alpha = alp;
    y = 0 ;
    x = 0 ;
} 

float lowpass::filter_lp(float in){
    y = in*alpha + (1-alpha)*(y+x)  ;
    x = in;
    return y ;
}