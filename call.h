//
// Created by houqinghua on 2017/12/28.
//

#ifndef CALL_H
#define CALL_H

#include "payoff.h"
#include "matrix.h"
class call : public payoff{
public:
    call(double, double, double, double, double);
    matrix option_Crank_Nicolson(int, int);
    matrix option_DFI(int, int);
};
#endif //C_PROJET_CALL_H
