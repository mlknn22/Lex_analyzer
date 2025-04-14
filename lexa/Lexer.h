#ifndef LEXER_H
#define LEXER_H

#include <unordered_map>
#include <vector>
#include <string>
#include "Token.h"
#include "FileUtils.h"

// Лексический анализатор
class Lexer {
private:
    std::unordered_map<std::string, std::string> keywords;
    std::unordered_map<std::string, std::string> singleDelimiters;
    std::unordered_map<std::string, std::string> doubleDelimiters;
    std::unordered_map<std::string, std::string> identifiersMap;
    std::unordered_map<std::string, std::string> unsignedIntsMap;
    std::unordered_map<std::string, std::string> literalsMap;
    std::vector<Token> tokens;

public:
    Lexer();
    void addToken(const std::string& value, const std::string& filename, std::unordered_map<std::string, std::string>& tokenMap, char prefix);
    void tokenize(const std::string& input);
    void printIdentifiersInLine();
};

#endif // LEXER_H
