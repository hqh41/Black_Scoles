//
// Created by houqinghua on 2017/12/30.
//

#ifndef PROJET_PUT_H
#define PROJET_PUT_H
#include "payoff.h"
#include "matrix.h"
class put : public payoff{
public:
    put(double, double, double, double, double);
    matrix option_Crank_Nicolson(int, int);
    matrix option_DFI(int, int);
};
#endif //PROJET_PUT_H
