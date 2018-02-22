//
// Created by houqinghua on 2017/12/30.
//

#include "put.h"
#include "matrix.h"
#include <math.h>
#include <algorithm>
#include <iostream>
using namespace std;

put::put(double T, double r, double sigma, double K, double L):payoff(T, r, sigma, K, L){}
matrix put::option_Crank_Nicolson(int m, int n){
    double s;
    double h  = L_/m;
    double dt = T_/n;
    double lambda, nu;
    int i, k;
    lambda = dt/h;
    nu = dt/(h*h);

    matrix A(m + 1, m + 1);
    matrix B(m + 1, m + 1);
    matrix C(m + 1, m + 1);
    matrix P(m + 1, 1);

    P(0, 0) = K_;//price
    A(0, 0) = 1 + r_*dt/2;
    B(0, 0) = 1 - r_*dt/2;
    for(i = 1; i < m; i++){
        s = i * h;
        A(i, i-1) = 0.25*r_*s*lambda - 0.25*pow(sigma_*s, 2)*nu;
        A(i, i) = 1+pow(sigma_*s, 2)*nu*0.5 + r_*dt*05;
        A(i, i+1) = 0.25*-r_*s*lambda - 0.25*pow(sigma_*s, 2)*nu;
        B(i, i-1) = 0.25*-r_*s*lambda + 0.25*pow(sigma_*s, 2)*nu;
        B(i, i) = 1-pow(sigma_*s, 2)*nu*0.5 - r_*dt*05;
        B(i, i+1) = r_*s*lambda/4 + 0.25*pow(sigma_*s, 2)*nu;
        P(i, 0) = ((K_-s > 0) ? (K_-s) : 0);
    }


    s = m*h;
    A(m, m-1) = 0.25*r_*s*lambda-0.25*pow(sigma_*s, 2)*nu;
    A(m, m) = 1+pow(sigma_*s, 2)*nu*0.5+r_*dt*0.5;
    B(m, m-1) = 0.25*-r_*s*lambda+0.25*pow(sigma_*s, 2)*nu;
    B(m, m) = 1-pow(sigma_*s, 2)*nu*0.5-r_*dt*0.5;
    P(m, 0) = ((K_-s > 0) ? (K_-s) : 0);

    C = inverse(A);//operator=
    C = mul(C, B);

    for(k = 1; k <= n; k++){
        P = mul(C, P);
        P(m, 0) = 0;
        P(0, 0) = ((K_*exp(-r_*(T_-k*dt))-s > 0) ? (K_*exp(-r_*(T_-k*dt))-s) : 0);
    }
    return P;
}

matrix put::option_DFI(int m, int n){
    matrix A(m + 1, m + 1);
    matrix B(m + 1, m + 1);
    matrix C(m + 1, m + 1);
    matrix P(m + 1, 1);

    double s;
    double h = L_/m;
    double dt = T_/n;
    int i, k;

    P(0, 0) = K_;
    A(0, 0) = 1 + (2*dt)/pow(h, 2);
    for(i = 1; i < m; i++){
        s = i*h;
        A(i, i-1) = -dt/pow(h, 2);
        A(i, i) = 1 + (2*dt)/pow(h, 2);
        A(i, i+1) = -dt/pow(h, 2);
        P(i, 0) = ((K_-s > 0) ? (K_-s) : 0);
    }

    s = m*h;
    A(m, m-1) = -dt/pow(h, 2);
    A(m, m) = 1 + (2*dt)/pow(h, 2);
    P(m, 0) = ((K_-s > 0) ? (K_-s) : 0);

    C = inverse(A);
    for(k = 1; k < n; k++){
        P = mul(C, P);
        P(m, 0) = 0;
        P(0, 0) = ((K_*exp(-r_*k*dt))-s > 0) ? (K_*exp(-r_*k*dt))-s : 0;
    }
    return P;
}
