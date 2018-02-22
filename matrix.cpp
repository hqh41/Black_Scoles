//
// Created by houqinghua on 2017/12/28.
//
#include "matrix.h"
#include <iostream>
using namespace std;

matrix::matrix(int nl, int nc){
    nl_ = nl;
    nc_ = nc;
    data_ = new double[nl * nc];
    for(int i = 0; i < nl_ * nc_; i++){
        data_[i] = 0.0;
    }
}

matrix::~matrix(){
    nl_ = 0;
    nc_ = 0;
    delete data_;
}

matrix::matrix(matrix& A){
    nl_ = A.get_nl();
    nc_ = A.get_nl();
    data_ = new double[A.get_nl()*A.get_nl()];
    for(int i = 0; i < A.get_nl(); i++){
        for(int j = 0; j < A.get_nl(); j++){
            data_[i*A.get_nl()+j] = A(i, j);
        }
    }
    //cout << "copie de constructeur" << endl;
}

int matrix::get_nl() const{
    return nl_;
}

int matrix::get_nc() const{
    return nc_;
}

double* matrix::get_data() const{
    return data_;
}

matrix& matrix::operator= (const matrix& v){
    nl_ = v.get_nl();
    nc_ = v.get_nc();
    for(int i = 0; i < v.get_nl(); i++){
        for(int j = 0; j < v.get_nl(); j++){
            data_[i*get_nl()+j] = v(i, j);
        }
    }
    return *this;
}


double& matrix::operator() (int l, int c){
    return data_[l * get_nc() + c];
}

double matrix::operator() (int l, int c) const{
    return data_[l * get_nc() + c];
}

void affichage(matrix& A){
    for(int i = 0; i < A.get_nl(); i++){
        for(int j = 0; j < A.get_nc(); j++){
            cout << "->" << A(i, j) << endl;
        }
    }
}

matrix mul(matrix& A, matrix& B){
    matrix res(A.get_nc(), A.get_nc());
    for (int i = 0; i < A.get_nl(); ++i)
    {
        for (int j = 0; j < B.get_nc(); ++j)
        {
            for (int k = 0; k < A.get_nc(); ++k)
            {
                res(i, j) += A(i, k) * B(k, j);
            }
        }
    }
    return res;
}
matrix inverse(matrix& m)
{
    int n=m.get_nc();
    matrix res(n,n);
    double *p=new double[n];
    double *q=new double[n];
    double *A=new double[n];
    double *B=new double[n];
    p[0]=m(0,0);   //p1=b1
    A[0]=m(0,1)/p[0];  //A1=c1/p1
    q[n-1]=0;//qn=0
    B[n-1]=m(n-1,n-2)/m(n-1,n-1);//Bn=an/bn
    int i;
    for(i=1;i<n;i++){
        p[i]=m(i,i)-A[i-1]*m(i,i-1);//pi=bi-Ai-1*ai
        A[i]=m(i,i+1)/p[i];//Ai=ci/pi
    }
    for(i=n-2;i>=0;i--)
    {
        q[i]=B[i+1]*m(i,i+1);//qi=Bi+1*ci
        B[i]=m(i,i-1)/(m(i,i)-q[i]);//Bi=ai/bi-qi
    }


    res(0,0)=1/(m(0,0)-q[0]);//
    res(n-1,n-1)=1/p[n-1];//
    for(i=1;i<n;i++)
    {
        res(i,0)=-B[i]*res(i-1,0);//
    }
    for(i=n-2;i>=0;i--)
    {
        res(i,n-1)=-A[i]*res(i+1,n-1);//
    }


    int j;
    for(j=1;j<n-1;j++)
    {
        res(j,j)=1/(p[j]-q[j]);
        for(i=j+1;i<n;i++)
        {
            res(i,j)=-B[i]*res(i-1,j);
        }
        for(i=j-1;i>=0;i--)
        {
            res(i,j)=-A[i]*res(i+1,j);
        }
    }
    /*p = NULL;
    q = NULL;
    A = NULL;
    B = NULL;*/
    return res;
}




