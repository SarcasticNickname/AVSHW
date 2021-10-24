//
// Created by User on 15.10.2021.
//

#include "triangular.h"

//------------------------------------------------------------------------------
// Сообщение об ошибке. Не удалось прочитать треугольную матрицу из файла.
void errMessageTr1() {
    printf("Couldn't read a triangular matrix. Incorrect input data.\n");
}

Triangular::Triangular(int size) {
    n = size * (size - 1) / 2;
    elements = nullptr;
}

Triangular::~Triangular() {
    Delete();
}

void Triangular::In(FILE* file, bool& success) {
    elements = new float[n];
    float elem;
    for (int i = 0; i < n; ++i) {
        //Проверяем на корректность ввода.
        if (fscanf(file,"%f",&elem) != 1) {
            errMessageTr1();
            success = false;
            return;
        }
        elements[i] = elem;
    }
}

void Triangular::InRnd() {
    elements = new float[n];
    for (int i = 0; i < n; ++i) {
        elements[i] = Triangular::rnd100.GetFloat();
    }
}

//------------------------------------------------------------------------------
// Вывод содержимого треугольной матрицы в указанный файл.
void Triangular::Out(FILE* file) {
    fprintf(file, "This is a triangular matrix. Matrix: \n");
    int j = 1;
    int i = 0;
    while(i < n){
        for (int k = 0; k < j; ++k) {
            if (k != j - 1){
                fprintf(file, "%f ", elements[i]);
                ++i;
            } else {
                fprintf(file, "%f", elements[i]);
                ++i;
            }
        }
        ++j;
        fprintf(file, "\n");
    }
    fprintf(file, "Average: %f\n", Average());
}

//------------------------------------------------------------------------------
// Вывод содержимого треугольной матрицы в консоль.
void Triangular::Print() {
    printf("This is a triangular matrix. Matrix: \n");
    int j = 1;
    int i = 0;
    while(i < n){
        for (int k = 0; k < j; ++k) {
            if (k != j - 1){
                printf("%f ", elements[i]);
                ++i;
            } else {
                printf("%f", elements[i]);
                ++i;
            }
        }
        ++j;
        printf("\n");
    }
    printf("Average: %f\n", Average());
}

//------------------------------------------------------------------------------
// Удаление элементов треугольной матрицы(очистка памяти)
void Triangular::Delete() {
    delete elements;
}

//------------------------------------------------------------------------------
// Вычисление среднего арифметического элементов треугольной матрицы. Для задания 2.
double Triangular::Average() {
    double sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += elements[i];
    }
    return sum/(n);
}

