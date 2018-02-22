//
// Created by houqinghua on 2017/12/28.
//
#include "payoff.h"
#include <iostream>
using namespace std;
payoff::payoff(double T, double r, double sigma, double K, double L){
    L_ = L;
    T_ = T;
    r_ = r;
    sigma_ = sigma;
    K_ = K;
}

payoff::~payoff(){
    L_ = 0;
    T_ = 0;
    r_ = 0;
    sigma_ = 0;
    K_ = 0;
}

