//
// Created by User on 15.10.2021.
//

#ifndef __rnd__
#define __rnd__

#include <cstdlib>

class Random {
private:
    int min;
    int max;
public:
    Random(int left, int right) {
        if (left <= right) {
            min = left;
            max = right;
        } else {
            min = right;
            max = left;
        }
    }
    //Генерация случайного числа в заданном диапазоне.
    int Get() {
        return rand() % (max - min + 1) + min;
    }
    float GetFloat() {
        return (float) rand() / RAND_MAX * (max - min) + min;
    }
};

#endif //__rnd__
