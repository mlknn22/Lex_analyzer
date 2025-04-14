#include "Lexer.h"
#include <cctype>
#include <iostream>

Lexer::Lexer() {
    keywords = loadTokensFromFile("keywords.txt", 'k');
    singleDelimiters = loadTokensFromFile("single_delimiters.txt", 's');
    doubleDelimiters = loadTokensFromFile("double_delimiters.txt", 'd');
    identifiersMap = loadTokensFromFile("identifiers.txt", 'i');
    unsignedIntsMap = loadTokensFromFile("unsigned_integers.txt", 'u');
    literalsMap = loadLiteralsFromFile("literals.txt");
}

void Lexer::addToken(const std::string& value, const std::string& filename, std::unordered_map<std::string, std::string>& tokenMap, char prefix) {
    if (tokenMap.find(value) != tokenMap.end()) {
        tokens.push_back({ value, tokenMap[value] });
        return;
    }

    std::string newId = prefix + std::to_string(tokenMap.size() + 1);
    tokenMap[value] = newId;
    tokens.push_back({ value, newId });
    writeTokenToFile(filename, { value, newId });
}

void Lexer::tokenize(const std::string& input) {
    std::string current;

    for (size_t i = 0; i < input.length(); ++i) {
        char ch = input[i];

        if (i + 1 < input.length()) {
            std::string twoChars = input.substr(i, 2);
            if (doubleDelimiters.find(twoChars) != doubleDelimiters.end()) {
                tokens.push_back({ twoChars, doubleDelimiters[twoChars] });
                i++;
                continue;
            }
        }

        if (singleDelimiters.find(std::string(1, ch)) != singleDelimiters.end()) {
            tokens.push_back({ std::string(1, ch), singleDelimiters[std::string(1, ch)] });
            continue;
        }

        if (std::isalpha(ch)) {
            current += ch;
            while (i + 1 < input.length() && (std::isalnum(input[i + 1]) || input[i + 1] == '_')) {
                current += input[++i];
            }

            if (keywords.find(current) != keywords.end()) {
                tokens.push_back({ current, keywords[current] });
            }
            else {
                addToken(current, "identifiers.txt", identifiersMap, 'i');
            }
            current.clear();
            continue;
        }

        if (ch == '_') {
            current += ch;
            while (i + 1 < input.length() && (std::isalnum(input[i + 1]) || input[i + 1] == '_')) {
                current += input[++i];
            }

            addToken(current, "identifiers.txt", identifiersMap, 'i');
            current.clear();
            continue;
        }

        if (std::isdigit(ch)) {
            current += ch;
            while (i + 1 < input.length() && std::isdigit(input[i + 1])) {
                current += input[++i];
            }

            addToken(current, "unsigned_integers.txt", unsignedIntsMap, 'u');
            current.clear();
            continue;
        }

        if (ch == '"' || ch == '\'') {
            char quote = ch;
            current += ch;
            while (i + 1 < input.length() && input[++i] != quote) {
                current += input[i];
            }
            current += quote;

            if (literalsMap.find(current) == literalsMap.end()) {
                addToken(current, "literals.txt", literalsMap, 'l');
            }
            else {
                tokens.push_back({ current, literalsMap[current] });
            }
            current.clear();
            continue;
        }

        if (!current.empty()) {
            current.clear();
        }
    }
}

void Lexer::printIdentifiersInLine() {
    std::string result;
    int lineLength = 0;

    for (const auto& token : tokens) {
        result += token.id + " ";
        lineLength += token.id.length() + 1;

        if (lineLength > 80) {
            result += "\n";
            lineLength = 0;
        }
    }

    if (!result.empty() && result.back() == ' ') {
        result.pop_back();
    }

    std::cout << "Лексическая свертка: " << "\n" << result << std::endl;
}
