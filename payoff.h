//
// Created by houqinghua on 2017/12/28.
//

#ifndef PAYOFF_H
#define PAYOFF_H

#include "matrix.h"

class payoff{
protected:
    double L_;//diviser S_max à L partis
    double T_;//diviser temps à T partis
    double r_;//taut d'intérêt
    double sigma_;
    double K_;//strike

public:
    payoff(double, double, double, double, double);
    ~payoff();
    virtual matrix option_Crank_Nicolson(int, int) = 0;
    virtual matrix option_DFI(int, int) = 0;
};
#endif //C_PROJET_PAYOFF_H
