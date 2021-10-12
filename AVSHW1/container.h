//
// Created by User on 09.10.2021.
//

#ifndef __container__
#define __container__

#include "matrix.h"

struct container {
    enum {max_len = 10000};
    int len;
    matrix cont[max_len];
};

void Init(container &c);

bool In(container &c, FILE *f);

void InRnd(container &c, int size);

void Out(container &c, FILE *f);

void Print(container &c);

void Delete(container &c);

double Average(container &c);

void Rearrange(container &c);

#endif //__container__
