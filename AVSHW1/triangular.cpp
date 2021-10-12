//
// Created by User on 10.10.2021.
//

#include "triangular.h"
#include "rnd.h"
#include <cstdio>

//------------------------------------------------------------------------------
// Сообщение об ошибке. Не удалось прочитать треугольную матрицу из файла.
void errMessageTr1() {
    printf("Couldn't read a triangular matrix. Incorrect input data.\n");
}

//------------------------------------------------------------------------------
// Ввод содержимого треугольной матрицы из указанного файла.
bool In(triangular &t, FILE *f, int n) {
    t.n = n * (n - 1) / 2;
    t.elements = new float[t.n];
    float elem;
    for (int i = 0; i < t.n; ++i) {
        //Проверяем на корректность ввода.
        if (fscanf(f,"%f",&elem) != 1) {
            errMessageTr1();
            return false;
        };
        t.elements[i] = elem;
    }
    return true;
}

//------------------------------------------------------------------------------
// Случайная генерация треугольной матрицы.
void InRnd(triangular &t) {
    int n = RandomLength();
    t.n = n * (n - 1) / 2;
    t.elements = new float[t.n];
    for (int i = 0; i < t.n; ++i) {
        t.elements[i] = RandomElement();
    }
}

//------------------------------------------------------------------------------
// Вывод содержимого треугольной матрицы в указанный файл.
void Out(triangular &t, FILE* f) {
    fprintf(f, "This is a triangular matrix. Matrix: \n");
    int j = 1;
    int i = 0;
    while(i < t.n){
        for (int k = 0; k < j; ++k) {
            if (k != j - 1){
                fprintf(f, "%f ", t.elements[i]);
                ++i;
            } else {
                fprintf(f, "%f", t.elements[i]);
                ++i;
            }
        }
        ++j;
        fprintf(f, "\n");
    }
    fprintf(f, "Average: %f\n", Average(t));
}

//------------------------------------------------------------------------------
// Вывод содержимого треугольной матрицы в консоль.
void Print(triangular &t) {
    printf("This is a triangular matrix. Matrix: \n");
    int j = 1;
    int i = 0;
    while(i < t.n){
        for (int k = 0; k < j; ++k) {
            if (k != j - 1){
                printf("%f ", t.elements[i]);
                ++i;
            } else {
                printf("%f", t.elements[i]);
                ++i;
            }
        }
        ++j;
        printf("\n");
    }
    printf("Average: %f\n", Average(t));
}

//------------------------------------------------------------------------------
// Удаление элементов треугольной матрицы(очистка памяти)
void Delete(triangular &t) {
    delete t.elements;
}

//------------------------------------------------------------------------------
// Вычисление среднего арифметического элементов треугольной матрицы. Для задания 2.
double Average(triangular &t) {
    double sum = 0;
    for (int i = 0; i < t.n; ++i) {
        sum += t.elements[i];
    }
    return sum/(t.n);
}

