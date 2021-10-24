//
// Created by User on 15.10.2021.
//

#ifndef __matrix__
#define __matrix__

#include <cstdio>
#include "rnd.h"

class Matrix {
protected:
    static Random rnd100;
    static Random rnd30;
    static Random rnd3;
    int n;

public:
    Matrix() = default;
    virtual ~Matrix() = default;;
    static Matrix* StaticIn(FILE* file, bool& success);
    virtual void In(FILE* file, bool& success) = 0;
    static Matrix* StaticRnd();
    virtual void  InRnd() = 0;
    virtual void Out(FILE* file) = 0;
    virtual void Print() = 0;
    virtual double Average() = 0;
    virtual void Delete() = 0;
};

#endif //__matrix__
