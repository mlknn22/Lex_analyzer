#ifndef TOKEN_H
#define TOKEN_H

#include <string>

// Определение типов токенов
enum TokenType {
    UNSIGNED_INT,     // Целые числа без знака
    IDENTIFIER,       // Идентификаторы
    KEYWORD,          // Ключевые слова
    LITERAL,          // Литералы
    SINGLE_DELIMITER, // Однолитерные разделители
    DOUBLE_DELIMITER  // Двулитерные разделители
};

// Структура токена
struct Token {
    std::string value;
    std::string id;
};

#endif // TOKEN_H
