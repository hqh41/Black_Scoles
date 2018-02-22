//
// Created by houqinghua on 2017/12/28.
//

#ifndef MATRIX_H
#define MATRIX_H
class matrix{
private:
    int nl_;
    int nc_;
    double* data_;
public:
    matrix(int, int);
    virtual ~matrix();
    matrix(matrix&);
    int get_nl() const;
    int get_nc() const;
    double* get_data()const;
    matrix& operator= (const matrix& v);
    double& operator()(int, int);
    double operator()(int, int) const;
};
void affichage(matrix&);//si il n'y a &, il vont utiliser constructeur de copier
matrix mul(matrix&, matrix&);
matrix inverse(matrix&);


#endif //C_PROJET_MATRIX_H
