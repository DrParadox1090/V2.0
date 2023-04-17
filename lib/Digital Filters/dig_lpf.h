#ifndef DIG_LPF
#define DIG_LPF

class lowpass{
    private :
        float y , x ;
        float alpha ;
    public :
        lowpass(float alpha = 0.98);
        float filter_lp(float in);
};
#endif
