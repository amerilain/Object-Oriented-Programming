#include <iostream>
#include <vector>
#include <limits>

int getValidInt() {
    int num;
    while(!(std::cin >> num)){
        std::cout << "Invalid input. Please enter a number: ";
        std::cin.clear(); // Clear the error state
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear the input buffer
    }
    return num;
}

void getNumbersFromUser(std::vector<int>& num, int numCount) {
    for (int i = 0; i < numCount; i++) {
        std::cout << "Enter number[" << i + 1 << "]: ";
        int x = getValidInt();
        num.push_back(x);
    }
}

void printNumbers(const std::vector<int>& num) {
    std::cout << "You entered: ";
    for (int i = 0; i < num.size(); i++) {
        std::cout << num[i];
        if (i != num.size() - 1) {
            std::cout << ", ";
        }
    }
}

int main() {
    std::vector<int> num;

    std::cout << "How many numbers do you want to enter? ";
    int numCount = getValidInt();

    getNumbersFromUser(num, numCount);
    printNumbers(num);

    return 0;
}