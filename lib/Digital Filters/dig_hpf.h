#ifndef DIG_HPF
#define DIG_HPF

class highpass{
    private :
        float *y , *x ;
        int n;
        float beta ;
    public :
        highpass(float beta , int N);
        void Init_hpf(float beta , int N);
        void filter_hp(float *in);
};

#endif
