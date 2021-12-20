//
// Created by Dereli Serkan
//

#ifndef AVSHW5_DECYPHERKIT_H
#define AVSHW5_DECYPHERKIT_H

#include <map>
#include <string>

/**
 * Класс для дешифровки строки.
 */
class DecypherKit {
private:
    // Таблица дешифровки.
    std::map<char, char> *decypher_table_;
    // Получение всех символов в зашифрованной строке, которых нет в таблице дешифровки.
    std::string getAllCharWhichAreNotPresentInMap(const std::string &cyphered_word);
    // Дешифровка части строки.
    static void decypherPartOfTheWord(const std::map<char, char> *decypher_table_,
                                      const std::string &word_part,
                                      std::string *decyphered_word_parts,
                                      const int &word_part_index);
    // Запись дешифрованной подстроки в массив дешифрованных подстрок.
    static void setDecypheredWordPart(const std::string &decyphered_word_part,
                                      std::string *decyphered_word_parts,
                                      const int &word_part_index);

public:
    explicit DecypherKit(std::map<char, char> *decypher_table);
    ~DecypherKit();
    // Метод расшифровки всей строки.
    std::string decypher(const std::string& cyphered_word, bool &success);
};

#endif //AVSHW5_DECYPHERKIT_H
