//
// Created by User on 09.10.2021.
//

#include "diagonal.h"
#include "rnd.h"
#include <cstdio>

//---------------------------------------------------------------------------------
// Сообщение об ошибке. Не удалось прочитать элементы диагональной матрицы с файла.
void errMessageDg1() {
    printf("Couldn't read a diagonal matrix. Incorrect input data.\n");
}

//------------------------------------------------------------------------------
// Ввод содержимого диагональной матрицы из указанного потока
bool In(diagonal &d, FILE *f, int n) {
    d.elements = new float[n];
    d.n = n;
    float elem;
    for (int i = 0; i < n; ++i) {
        //Проверяем корректность входных данных.
        if (fscanf(f,"%f",&elem) != 1) {
            errMessageDg1();
            return false;
        };
        d.elements[i] = elem;
    }
    return true;
}

//------------------------------------------------------------------------------
// Случайная генерация элементов диагональной матрицы.
void InRnd(diagonal &d) {
    int n = RandomLength();
    d.n = n;
    d.elements = new float[n];
    for (int i = 0; i < n; ++i) {
        d.elements[i] = RandomElement();
    }
}

//------------------------------------------------------------------------------
// Вывод диагональной матрицы в выходной файл.
void Out(diagonal &d, FILE* f) {
    fprintf(f, "This is a diagonal matrix. Diagonal elements: \n");
    for (int i = 0; i < d.n; ++i) {
        fprintf(f, "%f ",d.elements[i]);
    }
    fprintf(f, "\nAverage: %f\n", Average(d));
}

//------------------------------------------------------------------------------
// Вывод диагональной матрицы в консоль.
void Print(diagonal &d) {
    printf("This is a diagonal matrix. Diagonal elements: \n");
    for (int i = 0; i < d.n; ++i) {
        printf("%f ",d.elements[i]);
    }
    printf("\nAverage: %f\n", Average(d));
}

//------------------------------------------------------------------------------
// Удаление диагональной матрицы(очистка памяти).
void Delete(diagonal &d) {
    delete[] d.elements;
}

//------------------------------------------------------------------------------
// Вычисление среднего арифметического элементов диагональной матрицы. Для задания 2.
double Average(diagonal &d) {
    double sum = 0;
    for (int i = 0; i < d.n; ++i) {
        sum += d.elements[i];
    }
    return sum/(d.n);
}
