#include <iostream>
#include <string>

void replaceChar(std::string& str, char ch) {
    for (char& c : str) {
        if (c == ch) {
            c = '_';
        }
    }
}

int main() {
    std::string inputString;
    std::string replaceStr;
    bool continueLoop = true;

    while (continueLoop) {
        std::cout << "Enter a string: ";
        std::getline(std::cin, inputString);

        // Check if valid string
        if (inputString.empty()) {
            std::cout << "Invalid input. Please enter a valid string.\n";
        } else {
            bool validChar = true;
            while (validChar) {
                std::cout << "Enter character to replace or \"stop\": ";
                std::getline(std::cin, replaceStr);

                // Check if valid character
                if (replaceStr.empty()) {
                    std::cout << "Invalid input. Please enter a valid character.\n";
                } else {
                    validChar = false; // Set flag to true and exit  loop
                }
            }

            if (replaceStr == "stop") {
                continueLoop = false; // Exit the program
            } else {
                // Replace the character in inputString
                replaceChar(inputString, replaceStr[0]);
                std::cout << "Result: " << inputString << std::endl;
            }
        }
    }

    return 0;
}