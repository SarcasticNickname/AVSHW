//
// Created by User on 15.10.2021.
//

#ifndef __square__
#define __square__

#include <cstdio>
#include "rnd.h"
#include "matrix.h"

class Square : public Matrix {
private:
    float** elements{};
public:
    explicit Square(int size);
    ~Square() override;
    void In(FILE* file, bool& success) override;
    void InRnd() override;
    void Out(FILE* file) override;
    void Print() override;
    void Delete() override;
    double Average() override;
};

#endif //__square__
