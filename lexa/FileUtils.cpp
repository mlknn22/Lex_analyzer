#include "FileUtils.h"
#include <fstream>
#include <iostream>

std::unordered_map<std::string, std::string> loadTokensFromFile(const std::string& filename, char prefix) {
    std::unordered_map<std::string, std::string> tokenMap;
    std::ifstream file(filename);
    std::string token;
    int counter = 1;

    if (file.is_open()) {
        while (file >> token) {
            tokenMap[token] = prefix + std::to_string(counter);
            counter++;
        }
        file.close();
    }
    else {
        std::cerr << "Ошибка при открытии файла: " << filename << std::endl;
    }

    return tokenMap;
}

std::unordered_map<std::string, std::string> loadLiteralsFromFile(const std::string& filename) {
    std::unordered_map<std::string, std::string> literalsMap;
    std::ifstream file(filename);
    std::string literal;
    int counter = 1;

    if (file.is_open()) {
        while (std::getline(file, literal)) {
            literalsMap[literal] = "l" + std::to_string(counter);
            counter++;
        }
        file.close();
    }
    else {
        std::cerr << "Ошибка при открытии файла с литералами: " << filename << std::endl;
    }

    return literalsMap;
}

void writeTokenToFile(const std::string& filename, const Token& token) {
    std::ofstream file(filename, std::ios::app);
    if (file.is_open()) {
        file << token.value << "\n";
        file.close();
    }
    else {
        std::cerr << "Ошибка при открытии файла для записи: " << filename << std::endl;
    }
}
