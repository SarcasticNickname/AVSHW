//
// Created by User on 08.10.2021.
//

#ifndef __triangular__
#define __triangular__

#include "cstdio"

struct triangular {
    int n;
    float * elements;
};

bool In(triangular &t, FILE *f, int n);

void InRnd(triangular &t);

void Out(triangular &t, FILE *f);

void Print(triangular &t);

void Delete(triangular &t);

double Average(triangular &t);

#endif //__triangular__
