//------------------------------------------------------------------------------
// container.cpp - содержит функции обработки контейнера
//------------------------------------------------------------------------------

#include <cstdio>
#include "container.h"

//------------------------------------------------------------------------------
// Инициализация контейнера
void Init(container &c) {
    c.len = 0;
}

//------------------------------------------------------------------------------
// Ввод содержимого контейнера из указанного потока
bool In(container &c, FILE* f) {
    while(feof(f) == 0) {
        if (In(c.cont[c.len], f)) {
            c.len++;
        } else {
            return false;
        }
    }
    return true;
}

//------------------------------------------------------------------------------
// Случайный ввод контейнера с данным размером.
void InRnd(container &c, int size) {
    while(c.len < size) {
        if(InRnd(c.cont[c.len])) {
            ++c.len;
        }
    }
}

//------------------------------------------------------------------------------
// Вывод содержимого контейнера в файл.
void Out(container &c, FILE* f) {
    fprintf(f, "Container contains %d elements \n", c.len);
    for(int i = 0; i < c.len; i++) {
        Out(c.cont[i], f);
    }
    fprintf(f, "Overall average: %f\n", Average(c));
}

//------------------------------------------------------------------------------
// Вывод содержимого контейнера в консоль.
void Print(container& c) {
    printf("Container contains %d elements \n", c.len);
    for (int i = 0; i < c.len; ++i) {
        Print(c.cont[i]);
    }
    printf("Overall average: %f\n", Average(c));
}

//------------------------------------------------------------------------------
// Удаление всех элементов контейнера(очистка памяти).
void Delete(container &c) {
    for (int i = 0; i < c.len; ++i) {
        Delete(c.cont[i]);
    }
}

//------------------------------------------------------------------------------
// Перестановки элементов в контейнере. Для 2 задания.
void Rearrange(container &c) {
    auto* cont2 = new matrix[c.len];
    int count = 0;
    double overall_average = Average(c);
    for (int i = 0; i < c.len; ++i) {
        if (Average(c.cont[i]) > overall_average) {
            cont2[count] = c.cont[i];
            ++count;
        }
    }
    for (int i = 0; i < c.len; ++i) {
        if (Average(c.cont[i]) <= overall_average) {
            cont2[count] = c.cont[i];
            ++count;
        }
    }
    for (int i = 0; i < c.len; ++i) {
        c.cont[i] = cont2[i];
    }
    delete[] cont2;
}

//------------------------------------------------------------------------------
// Рассчёт среднего арифметического элементов матриц контейнера. Для 2 задания.
double Average(container &c) {
    double sum = 0.0;
    for(int i = 0; i < c.len; i++) {
        sum += Average(c.cont[i]);
    }
    return sum / c.len;
}
