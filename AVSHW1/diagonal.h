//
// Created by User on 08.10.2021.
//

#ifndef __diagonal__
#define __diagonal__

#include <cstdio>

struct diagonal {
    int n;
    float * elements;
};

bool In(diagonal &d, FILE *f, int n);

void InRnd(diagonal &d);

void Out(diagonal &d, FILE *f);

void Print(diagonal &d);

void Delete(diagonal &d);

double Average(diagonal &d);

#endif //__diagonal__
