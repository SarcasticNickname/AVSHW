//
// Created by User on 08.10.2021.
//

#ifndef __matrix__
#define __matrix__

#include "cstdio"
#include "diagonal.h"
#include "square.h"
#include "triangular.h"

struct matrix {
    enum key {DIAGONAL, SQUARE, TRIANGULAR};
    key k;
    union {
        square s;
        triangular t;
        diagonal d;
    };
};

bool In(matrix &m, FILE *f);

bool InRnd(matrix &m);

void Out(matrix &m, FILE *f);

void Print(matrix &m);

void Delete(matrix &m);

double Average(matrix &m);

#endif //__matrix__
