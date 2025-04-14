#ifndef FILEUTILS_H
#define FILEUTILS_H

#include <unordered_map>
#include <string>
#include "Token.h"

// Функция для загрузки токенов из файла с присвоением порядковых номеров
std::unordered_map<std::string, std::string> loadTokensFromFile(const std::string& filename, char prefix);

// Функция для загрузки литералов из файла
std::unordered_map<std::string, std::string> loadLiteralsFromFile(const std::string& filename);

// Функция для записи токена в файл
void writeTokenToFile(const std::string& filename, const Token& token);

#endif // FILEUTILS_H
