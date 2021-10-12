//------------------------------------------------------------------------------
// main.cpp - содержит главную функцию,
// обеспечивающую простое тестирование
//------------------------------------------------------------------------------


#include <cstdlib> // для функций rand() и srand()
#include <ctime>   // для функции time()
#include <cstring>
#include <cstdio>

#include "container.h"

//------------------------------------------------------------------------------
// Сообщение об ошибке. Введена некорректные команды в командной строке.
void errMessage1() {
    printf( "incorrect command line!\n"
            "  Waited:\n"
            "     command -f infile outfile\n"
            "  Or:\n"
            "     command -n number outfile\n");
}

//-------------------------------------------------------------------------------
// Сообщение об ошибке. Неверный размер контейнера, введённый из командной строки.
void errMessage2() {
    printf( "incorrect qualifier value!\n"
            "  Waited:\n"
            "     command -f infile outfile\n"
            "  Or:\n"
            "     command -n number outfile\n");
}

//------------------------------------------------------------------------------
// Сообщение об ошибке. Нет файла, с которого можно считать данные по указанному пути.
void errMessage3() {
    printf("Incorrect input file path!\n"
           "Please try again:\n"
           "    command -f infile outfile"
           "Or:\n"
           "    command -n number outfile");
}

//------------------------------------------------------------------------------
// Сообщение об ошибке. Не можем создать файл по указанному пути для выходных данных.
void errMessage4() {
    printf("Incorrect output file path!\n"
           "Please try again: \n"
           "    command -f infile outfile\n"
           "Or:\n"
           "    command -n number outfile\n");
}

//------------------------------------------------------------------------------
// Главная функциональность программы.
int main(int argc, char* argv[]) {
    //Если введено меньше команды через командную строку, то прекращаем работу.
    if(argc != 4) {
        errMessage1();
        return 1;
    }
    printf("Start\n");
    // Инициализируем контейнер.
    container c;
    Init(c);
    //Проверяем на корректность введённую команду, указывающую на тип входных данных.
    if (!strcmp(argv[1], "-f")) {
        FILE* f = fopen(argv[2], "r");
        // Проверяем, существует ли файл по указанному пути.
        if (f == NULL) {
            errMessage3();
            printf("Stop\n");
            return 3;
        }
        //Проверяем, пустой ли входной файл:
        //Перемещаем каретку на конец файла.
        fseek(f,0,SEEK_END);
        //Если позиция каретки в конце файла == 0 ->
        //Файл пустой. Сообщаем об этом. Выходим из программы.
        if (ftell(f) == 0) {
            printf("File is empty. \n" );
            printf("Stop\n");
            return 3;
        }
        fseek(f,0,SEEK_SET);
        // Если существует, то получаем из него данные.
        // false вернётся, если в файле некорректные данные.
        if (In(c, f)) {
            printf("Container is successfully filled. \n");
        // Если вернулось false, то возникла ошибка при заполнении контейнера.
        } else {
            //Выводим сообщение об ошибке, удаляем контейнер, закрывает входной файл.
            printf("Failed to fill the container. \n");
            Delete(c);
            fclose(f);
            printf("Stop\n");
            return 3;
        }
    }
    // Проверяем на корректность введённую команду, указывающую на тип входных данных.
    else if(!strcmp(argv[1], "-n")) {
        // Получаем размер контейнера.
        int size;
        sscanf(argv[2], "%d", &size);
        // Валидный размер - от 1 до 10000 элементов, как в условии задачи.
        if ((size < 1) || (size > 10000)) {
            printf("incorrect number of matrixes = %d"
                 ". Set 0 < number <= 1000\n", size);
            printf("Stop\n");
            return 3;
        }
        // системные часы в качестве инициализатора
        srand(static_cast<unsigned int>(time(0)));
        // Заполнение контейнера генератором случайных чисел
        InRnd(c, size);
    }
    // Если ввели некорректную команду в командной строке, то сообщаем об этом.
    else {
        errMessage2();
        return 2;
    }
    //Проверяем, можно ли создать файл по указанному пути.
    FILE* f = fopen(argv[3], "w");
    if (f == NULL) {
        errMessage4();
        return 3;
    }
    //Вывод содержимого исходного контейнера в консоль.
    printf("Filled Container: \n");
    Print(c);
    // Вывод содержимого исходного контейнера в файл
    fprintf(f, "Filled container: \n");
    Out(c, f);
    // 2 Задание.
    Rearrange(c);
    //Вывод изменённого контейнера(выполнено 2 задание) в файл.
    fprintf(f, "Rearranged container: \n");
    Out(c, f);
    //Вывод изменённого контейнера(выполнено 2 задание) в консоль.
    printf("Rearranged container: \n");
    Print(c);
    //Удаление контейнера.
    Delete(c);
    printf("Stop\n");
    fclose(f);
    return 0;
}
