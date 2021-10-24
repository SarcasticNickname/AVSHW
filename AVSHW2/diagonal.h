//
// Created by User on 15.10.2021.
//

#ifndef __diagonal__
#define __diagonal__

#include <cstdio>
#include "rnd.h"
#include "matrix.h"

class Diagonal : public Matrix {
private:
    float* elements{};
public:
    explicit Diagonal(int size);
    ~Diagonal() override;
    void In(FILE* file, bool& success) override;
    void InRnd() override;
    void Out(FILE* file) override;
    void Print() override;
    void Delete() override;
    double Average() override;
};

#endif //__diagonal__
