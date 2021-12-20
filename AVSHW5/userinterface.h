//
// Created by Dereli Serkan
//

#include<map>
#include<iostream>
#include<string>

#ifndef AVSHW5_USERINTERFACE_H
#define AVSHW5_USERINTERFACE_H
/**
 * Класс для взаимодействия с пользователем.
 */
class UserInterface {
private:
    // Получает таблицы дешифровки.
    static std::map<char, char> *getNewDecypherMap();
    // Модифицирует таблицу дешифровки.
    static void modifyDecypherMap(std::map<char, char> *decypherMap);

public:
    UserInterface() = default;
    ~UserInterface() = default;
    // Основной метод работы программы.
    static void runProgram();
};
#endif //AVSHW5_USERINTERFACE_H
