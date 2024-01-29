#include <iostream>
#include <deque>

int runAvgSize = 5;

class RunningAverage {
    public:
        explicit RunningAverage(int size) : maxSize(size) {}
        void add_value(int value);
        double get_average();

    private:
        std::deque<int> values;
        int maxSize;
};

void RunningAverage::add_value(int value) {
    values.push_back(value);
    if (values.size() > maxSize) {
        values.pop_front();
    }
}

double RunningAverage::get_average() {
    if (values.empty()) return 0.0;
    double sum = 0.0;
    for (int value : values) {
        sum += value;
    }
    return sum / values.size();
}

int main() {
    RunningAverage avg(runAvgSize); // Instance for running average of the last 5 numbers
    int number;

    while (true) {
        std::cout << "Enter a number (0 to stop): ";
        std::cin >> number;

        if (number == 0) break;

        avg.add_value(number);
        std::cout << "Current Running Average: " << avg.get_average() << std::endl;
    }

    std::cout << "Final Running Average: " << avg.get_average() << std::endl;
    return 0;
}
