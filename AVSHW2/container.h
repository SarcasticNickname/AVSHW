#ifndef __container__
#define __container__

//------------------------------------------------------------------------------
// container.h - содержит тип данных,
// представляющий простейший контейнер
//------------------------------------------------------------------------------

#include "matrix.h"
#include <cstdio>

//------------------------------------------------------------------------------
// Простейший контейнер на основе одномерного массива
class Container {
private:
    int len; // текущая длина
    Matrix* storage[10000];

public:
    Container();
    ~Container();
    void In(FILE* file, bool& success);
    void InRnd(int size);
    void Out(FILE* file);
    void Print();
    double Average();
    // Очистка контейнера от данных
    void Delete();
    void Rearrange();
};

#endif