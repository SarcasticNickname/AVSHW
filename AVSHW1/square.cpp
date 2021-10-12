//
// Created by User on 10.10.2021.
//

#include "square.h"
#include "rnd.h"
#include <cstdio>

//------------------------------------------------------------------------------
// Сообщение об ошибке. Не удалось прочитать квадратную матрицу из файла.
void errMessageSq1() {
    printf("Couldn't read a square matrix. Incorrect input data.\n");
}

//------------------------------------------------------------------------------
// Ввод содержимого квадратной матрицы из указанного файла.
bool In(square &s, FILE *f, int n) {
    s.elements = new float* [n];
    for (int i = 0; i < n; ++i) {
        s.elements[i] = new float[n];
    }
    s.n = n;
    float elem;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            //Проверяем на корректность входных данных.
            if (fscanf(f,"%f",&elem) != 1) {
                errMessageSq1();
                return false;
            };
            s.elements[i][j] = elem;
        }
    }
    return true;
}

//------------------------------------------------------------------------------
// Случайная генерация квадратной матрицы.
void InRnd(square & s) {
    int n = RandomLength();
    s.n = n;
    s.elements = new float* [n];
    for (int i = 0; i < n; ++i) {
        s.elements[i] = new float[n];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            s.elements[i][j] = RandomElement();
        }
    }
}

//------------------------------------------------------------------------------
// Вывод квадратной матрицы в указанный файл.
void Out(square &s, FILE* f) {
    fprintf(f, "This is a square matrix. Matrix: \n");
    for (int i = 0; i < s.n; ++i) {
        for (int j = 0; j < s.n; ++j) {
            fprintf(f, "%f ", s.elements[i][j]);
        }
        fprintf(f, "\n");
    }
    fprintf(f, "Average: %f\n", Average(s));
}

//------------------------------------------------------------------------------
// Вывод элементов матрицы в консоль.
void Print(square &s) {
    printf("This is a square matrix. Matrix: \n");
    for (int i = 0; i < s.n; ++i) {
        for (int j = 0; j < s.n; ++j) {
            printf("%f ", s.elements[i][j]);
        }
        printf("\n");
    }
    printf("Average: %f\n", Average(s));
}

//------------------------------------------------------------------------------
// Удаление квадратной матрицы(очистка памяти).
void Delete(square &s) {
    for (int i = 0; i < s.n; ++i) {
        delete[] s.elements[i];
    }
    delete[] s.elements;
}

//------------------------------------------------------------------------------
// Вычисление среднего арифметического элеметнов квадратной матрицы. Для задания 2.
double Average(square &s) {
    double sum = 0;
    for (int i = 0; i < s.n; ++i) {
        for (int j = 0; j < s.n; ++j) {
            sum += s.elements[i][j];
        }
    }
    return sum/(s.n * s.n);
}

