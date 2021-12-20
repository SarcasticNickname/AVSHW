//
// Created by Dereli Serkan
//

#include <cmath>
#include <iostream>
#include <thread>
#include <mutex>
#include "decypherkit.h"

using std::map;
using std::string;
using std::sqrt;
using std::ceil;
using std::cout;
using std::thread;
using std::mutex;

mutex mtx;

/**
 * Конструктор, принимающий дешифровачную таблицу.
 * @param decypher_table - дешифровочная таблица.
 */
DecypherKit::DecypherKit(map<char, char> *decypher_table) {
    decypher_table_ = decypher_table;
}

/**
 * Метод расшифровывает зашифрованное слово.
 * @param cyphered_word - зашифрованное слово.
 * @param success - флаг(удалось расшифровать или нет).
 * @return - расшифрованное слово.
 */
std::string DecypherKit::decypher(const string& cyphered_word, bool &success) {
    // Получаем все символы строки, которых нет в таблице дешифровки.
    // Если такая строка непустая, то надо поработать либо с таблицей,
    // либо с новым словом.
    string missed_chars = getAllCharWhichAreNotPresentInMap(cyphered_word);
    if (!missed_chars.empty()) {
        cout << "Decypher table does not contain all characters to decypher the word.";
        success = false;
        return missed_chars;
    }
    int decyphered_word_size = cyphered_word.size();
    int word_parts_number = (int)ceil(sqrt(decyphered_word_size));
    int word_parts_length = (int)ceil(static_cast<double>(decyphered_word_size) / word_parts_number);
    string cyphered_word_parts[word_parts_number];
    string decyphered_word_parts[word_parts_number];
    for (int i = 0; i < word_parts_number - 1; ++i) {
        cyphered_word_parts[i] = cyphered_word.substr(i * word_parts_length, word_parts_length);
    }
    cyphered_word_parts[word_parts_number - 1] = cyphered_word.substr((word_parts_number - 1) * word_parts_length);
    auto **threads = new thread *[word_parts_number];
    cout << "Starting to decrypt the given word.\n";
    // Создаём рабочих (потоки).
    for (int i = 0; i < word_parts_number; ++i) {
        threads[i] = new thread(decypherPartOfTheWord, decypher_table_, cyphered_word_parts[i], &decyphered_word_parts[0], i);
    }
    // Ждём, пока отработают все потоки.
    for (int i = 0; i < word_parts_number; ++i) {
        threads[i]->join();
    }
    string result;
    for (const string &part : decyphered_word_parts) {
        result += part;
    }
    cout << "Encrypted word was decrypted.\n";
    delete[] threads;
    success = true;
    return result;
}

/**
 * Проверяет, все ли символы в зашифрованной строке можно декодировать.
 * @param cyphered_word - зашифрованная строка.
 * @param decypher_table - таблица для дешифровки.
 * @return - true, если какого-то символа шифрованной строки
 * нет в таблице для дешифровки.
 */
string DecypherKit::getAllCharWhichAreNotPresentInMap(const string& cyphered_word) {
    auto end = decypher_table_->end();
    string all_missed_chars;
    for (char character : cyphered_word) {
        if (decypher_table_->find(character) == end) {
            all_missed_chars += character;
            all_missed_chars += " ";
        }
    }
    return all_missed_chars;
}

/**
 * Расшифровывает часть строки.
 * @param decypher_table_ - таблица расшифровки.
 * @param word_part - часть строки
 * @param decyphered_word_parts - массив расшифрованных подстрок
 * @param word_part_index - индекс подстроки среди расшифрованных.
 */
 void DecypherKit::decypherPartOfTheWord(const map<char, char> *decypher_table_,
                                        const string &word_part,
                                        string *decyphered_word_parts,
                                        const int &word_part_index) {
    string result;
    for (char character : word_part) {
        result += decypher_table_->at(character);
    }
    cout << "Part " << word_part << " has been decrypted by a thread.\n";
    setDecypheredWordPart(result, decyphered_word_parts, word_part_index);
}

/**
 * Деструктор
 */
DecypherKit::~DecypherKit() {
    delete decypher_table_;
}

/**
 * Метод записывает расшифрованную подстроку в массив расшифрованных подстрок.
 * @param decyphered_word_part  - расшифрованная подстрока.
 * @param decyphered_word_parts  - массив расшифрованных подстрок.
 * @param word_part_index - индекс расшифрованной подстроки.
 */
 void DecypherKit::setDecypheredWordPart(const string &decyphered_word_part,
                                         string *decyphered_word_parts,
                                        const int &word_part_index) {
     mtx.lock();
     decyphered_word_parts[word_part_index] = decyphered_word_part;
     mtx.unlock();
}
