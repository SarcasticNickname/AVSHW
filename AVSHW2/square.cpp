//
// Created by User on 15.10.2021.
//

#include "square.h"

//------------------------------------------------------------------------------
// Сообщение об ошибке. Не удалось прочитать квадратную матрицу из файла.
void errMessageSq1() {
    printf("Couldn't read a square matrix. Incorrect input data.\n");
}


Square::Square(int size) {
    n = size;
    elements = nullptr;
}

Square::~Square() {
    Delete();
}

void Square::In(FILE* file, bool& success) {
    elements = new float* [n];
    for (int i = 0; i < n; ++i) {
        elements[i] = new float[n];
    }
    float elem;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            //Проверяем на корректность входных данных.
            if (fscanf(file,"%f",&elem) != 1) {
                errMessageSq1();
                success = false;
                return;
            };
            elements[i][j] = elem;
        }
    }
}

void Square::InRnd() {
    elements = new float* [n];
    for (int i = 0; i < n; ++i) {
        elements[i] = new float[n];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            elements[i][j] = Square::rnd100.GetFloat();
        }
    }
}

//------------------------------------------------------------------------------
// Вывод квадратной матрицы в указанный файл.
void Square::Out(FILE* f) {
    fprintf(f, "This is a square matrix. Matrix: \n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            fprintf(f, "%f ", elements[i][j]);
        }
        fprintf(f, "\n");
    }
    fprintf(f, "Average: %f\n", Average());
}

//------------------------------------------------------------------------------
// Вывод элементов матрицы в консоль.
void Square::Print() {
    printf("This is a square matrix. Matrix: \n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%f ", elements[i][j]);
        }
        printf("\n");
    }
    printf("Average: %f\n", Average());
}

//------------------------------------------------------------------------------
// Удаление квадратной матрицы(очистка памяти).
void Square::Delete() {
    for (int i = 0; i < n; ++i) {
        delete[] elements[i];
    }
    delete[] elements;
}

//------------------------------------------------------------------------------
// Вычисление среднего арифметического элеметнов квадратной матрицы. Для задания 2.
double Square::Average() {
    double sum = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            sum += elements[i][j];
        }
    }
    return sum/(n * n);
}

