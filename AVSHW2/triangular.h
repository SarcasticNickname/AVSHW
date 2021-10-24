//
// Created by User on 15.10.2021.
//

#ifndef __triangular__
#define __triangular__

#include <cstdio>
#include "rnd.h"
#include "matrix.h"

class Triangular : public Matrix {
private:
    float* elements;
public:
    explicit Triangular(int size);
    ~Triangular() override;
    void In(FILE* file, bool& success) override;
    void InRnd() override;
    void Out(FILE* file) override;
    void Print() override;
    void Delete() override;
    double Average() override;
};

#endif //__triangular__
