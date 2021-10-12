//
// Created by User on 08.10.2021.
//

#ifndef __rnd__
#define __rnd__

#include <cstdlib>

inline auto RandomElement() {
    int min = -100, max = 100;
    return (float) rand() / RAND_MAX * (max - min) + min;
}

inline auto RandomLength() {
    return rand() % 20 + 2;
}
#endif
