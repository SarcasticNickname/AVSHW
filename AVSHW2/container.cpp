//------------------------------------------------------------------------------
// container_Constr.cpp - содержит функции обработки контейнера
//------------------------------------------------------------------------------

#include "container.h"

//------------------------------------------------------------------------------
// Конструктор контейнера
Container::Container(): len{0} { }

//------------------------------------------------------------------------------
// Деструктор контейнера
Container::~Container() {
    Delete();
}

//------------------------------------------------------------------------------
// Очистка контейнера от элементов (освобождение памяти)
void Container::Delete() {
    for(int i = 0; i < len; i++) {
        delete storage[i];
    }
    len = 0;
}

//------------------------------------------------------------------------------
// Ввод содержимого контейнера из указанного потока
void Container::In(FILE* file, bool& success) {
    while(feof(file) == 0) {
        if (success) {
            storage[len] = Matrix::StaticIn(file, success);
            len++;
        } else {
            return;
        }
    }
}

//------------------------------------------------------------------------------
// Случайный ввод содержимого контейнера
void Container::InRnd(int size) {
    while(len < size) {
        storage[len] = Matrix::StaticRnd();
        len++;
    }
}

//------------------------------------------------------------------------------
// Вывод содержимого контейнера в файл.
void Container::Out(FILE* file) {
    fprintf(file, "Container contains %d elements \n", len);
    for(int i = 0; i < len; i++) {
        storage[i]->Out(file);
    }
    fprintf(file, "Overall average: %f\n", Average());
}

//------------------------------------------------------------------------------
// Вывод содержимого контейнера в консоль.
void Container::Print() {
    printf("Container contains %d elements \n", len);
    for (int i = 0; i < len; ++i) {
        storage[i]->Print();
    }
    printf("Overall average: %f\n", Average());
}

//------------------------------------------------------------------------------
// Перестановки элементов в контейнере. Для 2 задания.
void Container::Rearrange() {
    auto* cont2 = new Matrix* [len];
    int count = 0;
    double overall_average = Average();
    for (int i = 0; i < len; ++i) {
        if (storage[i]->Average() > overall_average) {
            cont2[count] = storage[i];
            ++count;
        }
    }
    for (int i = 0; i < len; ++i) {
        if (storage[i]->Average() <= overall_average) {
            cont2[count] = storage[i];
            ++count;
        }
    }
    for (int i = 0; i < len; ++i) {
        storage[i] = cont2[i];
    }
    delete[] cont2;
}

//------------------------------------------------------------------------------
// Рассчёт среднего арифметического элементов матриц контейнера. Для 2 задания.
double Container::Average() {
    double sum = 0.0;
    for(int i = 0; i < len; i++) {
        sum += storage[i]->Average();
    }
    return sum / len;
}

