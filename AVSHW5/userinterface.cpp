//
// Created by Dereli Serkan on 19.12.2021.
//

#include <iostream>
#include "userinterface.h"
#include "decypherkit.h"

using namespace std;

/**
 * Метод получает таблицу дешифровки.
 * @return - мапу дешифровки.
 */
std::map<char, char> *UserInterface::getNewDecypherMap() {
    string message = "Enter a pair of characters : <char>-<char>, \n"
                     "where first character stands for a character in encrypted word,\n"
                     "the second character stands for a character in decrypted word.\n"
                     "This will set(or reset) char1 = char2 in the decryptition table.\n"
                     "Print stop, if you want to stop.\n";

    auto decypher_map = new map<char, char>;
    string character_pair;
    cout << message;
    while (character_pair != "stop") {
        getline(cin, character_pair);
        if (character_pair == "stop") {
            cout << "Stopped getting decrypt table.\n";
            break;
        }
        if (character_pair.size() != 3 || character_pair[1] != '-') {
            cout << "Wrong pair of characters, try again:\n";
            continue;
        }
        decypher_map->insert_or_assign(character_pair[0], character_pair[2]);
        cout << character_pair[0] << " = " << character_pair[2] << "\n";
    }
    return decypher_map;
}

/**
 * Метод модифицирует таблицу дешифровки.
 * @param decypher_map - ссылка на таблицу дешифровки.
 */
void UserInterface::modifyDecypherMap(std::map<char, char> *decypher_map) {
    string message = "Enter a pair of characters : <char>-<char>, \n"
                     "where first character stands for a character in encrypted word,\n"
                     "the second character stands for a character in decrypted word.\n"
                     "This will set(or reset) char1 = char2 in the decryption table.\n"
                     "Print stop, if you want to stop.\n";
    string character_pair;
    cout << message;
    while (character_pair != "stop") {
        getline(cin, character_pair);
        if (character_pair == "stop") {
            cout << "Stopped working with decryption table.\n";
            break;
        }
        if (character_pair.size() != 3 || character_pair[1] != '-') {
            cout << "Wrong pair of characters, try again:\n";
            continue;
        }
        decypher_map->insert_or_assign(character_pair[0], character_pair[2]);
        cout << character_pair[0] << " = " << character_pair[2] << "\n";
    }
}

/**
 * Основной метод программы. Взаимодействие с пользователем, обработка крайних случаев.
 */
void UserInterface::runProgram() {
    // Получаем таблицу.
    auto decryption_map = getNewDecypherMap();
    DecypherKit kit(decryption_map);
    string input;
    string decrypted_string;
    bool success = true;
    while (input != "exit") {
        cout << "Type an encrypted word (or exit to exit program): \n";
        // Получаем зашифрованное слово или сообщения для выхода.
        getline(cin, input);
        if (input == "exit") {
            continue;
        }
        decrypted_string = kit.decypher(input, success);
        // Если символов в таблице не хватает для дешифровки,
        // то обрабатываем соответствующим образом.
        while (!success) {
            cout << "Decryption table does not contain all needed symbols.\n";
            cout << "These characters are lacking: " + decrypted_string << "\n";
            cout << "Print modify to modify current decription table,\n";
            cout << "new table to get a new table.\n";
            cout << "new word to input a new word,\n";
            cout << "exit to exit the program.\n";
            getline(cin, input);
            if (input == "modify") {
                modifyDecypherMap(decryption_map);
            } else if (input == "new table") {
                decryption_map = getNewDecypherMap();
            } else if (input == "new word") {
                success = true;
            } else if (input == "exit") {
                cout << "Stopping the program...\n";
                delete decryption_map;
                exit(0);
            } else {
                cout << "Wrong decision input. Try again:\n";
                continue;
            }
            break;
        }
        if (success) {
            cout << decrypted_string << "\n";
        }
    }
}

