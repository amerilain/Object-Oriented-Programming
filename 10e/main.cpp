#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

class UniqueRng {
public:
    UniqueRng(int min, int max) : min(min), max(max) {}
    int operator()();

private:
    int min;
    int max;
    std::vector<int> numbers;
};

int UniqueRng::operator()() {
    if (numbers.size() == (max - min + 1)) {
        throw std::runtime_error("Unable to produce unique random number ");
    }
    int number;
    do {
        number = rand() % (max - min + 1) + min;
    } while(find(numbers.begin(), numbers.end(), number) != numbers.end());

    numbers.push_back(number);
    return number;
}

void test_generator(UniqueRng ur, int count) {
    std::cout << "Generating numbers:" << std::endl;
    std::vector<int> generatedNumbers;

    try {
        for(int i = 0; i < count; ++i) {
            generatedNumbers.push_back(ur());
        }

    } catch (std::runtime_error& e) {
        std::cout << "Exception: " << e.what() << " Tried to generate " << count << " random numbers. But got only " << generatedNumbers.size() << std::endl;
    }

    // Directly printing the number one-by-one
    for(auto num : generatedNumbers) {
        std::cout << num << std::endl;
    }

    std::cout << "End of generator" << std::endl;
}

int main(void) {
    srand(time(nullptr));
    UniqueRng randGen(5, 13);
    test_generator(randGen, 6);
    test_generator(randGen, 9);
    test_generator(randGen, 13); // this will cause exception
    UniqueRng randGen2(1, 35);
    test_generator(randGen2, 7);
    test_generator(randGen2, 7);
    test_generator(randGen2, 7);
    test_generator(randGen2, 70); // this will cause exception
}