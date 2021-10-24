//
// Created by User on 15.10.2021.
//

#include "matrix.h"
#include "diagonal.h"
#include "triangular.h"
#include "square.h"

Random Matrix::rnd100(1,100);
Random Matrix::rnd30(2,30);
Random Matrix::rnd3(1,3);

Matrix* Matrix::StaticIn(FILE *file, bool& success) {
    Matrix* matrix = nullptr;
    double k_param, n_param;
    fscanf(file,"%lf%lf", &k_param, &n_param);
    int k, n;
    //Проверка того, что в файле k и n - целые числа.
    if ((k_param - (int)k_param == 0) && ((n_param - (int)n_param)) == 0 &&
        k_param >=1 && k_param <=3 && n_param > 0) {
        k = (int)k_param;
        n = (int)n_param;
    } else {
        printf("K or N is not integer number \n");
        success = false;
        return matrix;
    }
    switch(k) {
        case 1:
            matrix = new Diagonal(n);
            break;
        case 2:
            matrix = new Square(n);
            break;
        case 3:
            matrix = new Triangular(n);
            break;
    }
    matrix->In(file, success);
    return matrix;
}

Matrix* Matrix::StaticRnd() {
    auto k = Matrix::rnd3.Get();
    auto n = Matrix::rnd30.Get();
    Matrix* matrix = nullptr;
    switch(k) {
        case 1:
            matrix = new Diagonal(n);
            break;
        case 2:
            matrix = new Square(n);
            break;
        case 3:
            matrix = new Triangular(n);
            break;
    }
    matrix->InRnd();
    return matrix;
}
