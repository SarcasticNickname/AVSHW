//
// Created by User on 08.10.2021.
//

#ifndef __square__
#define __square__

#include "cstdio"

struct square {
    int n;
    float ** elements;
};

bool In(square &s, FILE *f, int n);

void InRnd(square &s);

void Out(square &s, FILE *f);

void Print(square &s);

void Delete(square &s);

double Average(square &s);

#endif //__square__
