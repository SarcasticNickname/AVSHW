//
// Created by User on 15.10.2021.
//

#include "diagonal.h"

//---------------------------------------------------------------------------------
// Сообщение об ошибке. Не удалось прочитать элементы диагональной матрицы с файла.
void errMessageDg1() {
    printf("Couldn't read a diagonal matrix. Incorrect input data.\n");
}


Diagonal::Diagonal(int size) {
    n = size;
    elements = nullptr;
}

Diagonal::~Diagonal() {
    Delete();
}

void Diagonal::In(FILE* file, bool& success) {
    elements = new float[n];
    float elem;
    for (int i = 0; i < n; ++i) {
        //Проверяем корректность входных данных.
        if (fscanf(file,"%f",&elem) != 1) {
            errMessageDg1();
            success = false;
            return;
        }
        elements[i] = elem;
    }
}

void Diagonal::InRnd() {
    elements = new float[n];
    for (int i = 0; i < n; ++i) {
        elements[i] = Diagonal::rnd100.GetFloat();
    }
}

//------------------------------------------------------------------------------
// Вывод диагональной матрицы в выходной файл.
void Diagonal::Out(FILE* f) {
    fprintf(f, "This is a diagonal matrix. Diagonal elements: \n");
    for (int i = 0; i < n; ++i) {
        fprintf(f, "%f ", elements[i]);
    }
    fprintf(f, "\nAverage: %f\n", Average());
}

//------------------------------------------------------------------------------
// Вывод диагональной матрицы в консоль.
void Diagonal::Print() {
    printf("This is a diagonal matrix. Diagonal elements: \n");
    for (int i = 0; i < n; ++i) {
        printf("%f ",elements[i]);
    }
    printf("\nAverage: %f\n", Average());
}

//------------------------------------------------------------------------------
// Удаление диагональной матрицы(очистка памяти).
void Diagonal::Delete() {
    delete[] elements;
}

//------------------------------------------------------------------------------
// Вычисление среднего арифметического элементов диагональной матрицы. Для задания 2.
double Diagonal::Average() {
    double sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += elements[i];
    }
    return sum/(n);
}

