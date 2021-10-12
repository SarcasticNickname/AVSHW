//
// Created by User on 09.10.2021.
//

#include "matrix.h"
#include "rnd.h"

//------------------------------------------------------------------------------
// Получение матрицы из файла.
bool In(matrix &m, FILE *f) {
    double k_param, n_param;
    fscanf(f,"%lf%lf", &k_param, &n_param);
    int k, n;
    //Проверка того, что в файле k и n - целые числа.
    if ((k_param - (int)k_param == 0) && ((n_param - (int)n_param)) == 0 &&
        k_param >=1 && k_param <=3 && n_param > 0) {
        k = (int)k_param;
        n = (int)n_param;
    } else {
        fprintf(f, "K or N is not integer number \n");
        return false;
    }
    //Вызываем нужную фунцию получения данных в зависимости от типа матрицы.
    switch(k) {
        case 1:
            m.k = matrix::DIAGONAL;
            if (!In(m.d, f, n)) {
               return false;
            }
            return true;
        case 2:
            m.k = matrix::SQUARE;
            if (!In(m.s, f, n)) {
                return false;
            }
            return true;
        case 3:
            m.k = matrix::TRIANGULAR;
            if (!In(m.t, f, n)) {
                return false;
            }
            return true;
        default:
            return false;
    }
}

//------------------------------------------------------------------------------
// Случайная генерация матрицы.
bool InRnd(matrix &m) {
    auto k = rand() % 3 + 1;
    //Вызываем нужную функцию случайной генерации в зависимости от случайного k.
    switch(k) {
        case 1:
            m.k = matrix::DIAGONAL;
            InRnd(m.d);
            return true;
        case 2:
            m.k = matrix::SQUARE;
            InRnd(m.s);
            return true;
        case 3:
            m.k = matrix::TRIANGULAR;
            InRnd(m.t);
            return true;
        default:
            return false;
    }
}

//------------------------------------------------------------------------------
// Вывод содержимого матрицы в файл.
void Out(matrix &m, FILE *f) {
    // Вызываем нужный метод вывода в файл в зависимости от типа матрицы.
    switch(m.k) {
        case matrix::DIAGONAL:
            Out(m.d, f);
            break;
        case matrix::SQUARE:
            Out(m.s, f);
            break;
        case matrix::TRIANGULAR:
            Out(m.t, f);
            break;
    }
}

//------------------------------------------------------------------------------
// Вывод матрицы в консоль.
void Print(matrix &m) {
    // Вызываем нужный метод в зависимости от типа матрицы.
    switch(m.k) {
        case matrix::DIAGONAL:
            Print(m.d);
            break;
        case matrix::SQUARE:
            Print(m.s);
            break;
        case matrix::TRIANGULAR:
            Print(m.t);
            break;
    }
}

//------------------------------------------------------------------------------
// Удаление содержимого матрицы(удаление памяти).
void Delete(matrix &m) {
    // Вызываем нужную функцию удаления в зависимости от типа матрицы.
    switch(m.k){
        case matrix::DIAGONAL:
            Delete(m.d);
            break;
        case matrix::SQUARE:
            Delete(m.s);
            break;
        case matrix::TRIANGULAR:
            Delete(m.t);
            break;
    }
}

//------------------------------------------------------------------------------
// Вычисление среднего значения элементов матрицы.
double Average(matrix &m) {
    // Вызываем нужную функцию в зависимости от типа матрицы.
    switch(m.k){
        case matrix::DIAGONAL:
            return Average(m.d);
        case matrix::SQUARE:
            return Average(m.s);
        case matrix::TRIANGULAR:
            return Average(m.t);
        default:
            return 0.0;
    }
}
