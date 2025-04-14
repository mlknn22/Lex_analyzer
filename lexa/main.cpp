#include <iostream>
#include "Lexer.h"

int main() {
    setlocale(LC_CTYPE, "ru");

    Lexer lexer;
    std::string code = R"(
        #include <iostream>
        #include <string>

        int factorial(int n) {
            if (n <= 1)
                return 1;
            else
                return n * factorial(n - 1);
        }

        int main() {
            int number = 5;
            std::string message = "Factorial of " + std::to_string(number) + " is: ";
            
            if (number > 0 && number < 10) {
                std::cout << message << factorial(number) << std::endl;
            } else if (number == 10 || number == 15) {
                std::cout << "Special number!" << std::endl;
            } else {
                std::cout << "Number is too large or negative." << std::endl;
            }

            return 0;
        }
    )";

    lexer.tokenize(code);
    lexer.printIdentifiersInLine();

    return 0;
}
