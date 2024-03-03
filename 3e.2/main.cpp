#include <iostream>
#include <deque>

int runAvgSize = 5;

class RunningAverage {
    public:
        explicit RunningAverage(int size) : maxSize(size), sum(0) {}
        void add_value(double value);
        double get_average();

    private:
        std::deque<double> values;
        int maxSize;
        double sum;
};

void RunningAverage::add_value(double value) {
    values.push_back(value);
    sum += value;
    if (values.size() > maxSize) {
        sum -= values.front();
        values.pop_front();
    }
}

double RunningAverage::get_average() {
    if (values.empty()) return 0.0;
    return sum / values.size();
}

int main() {
    RunningAverage avg(runAvgSize);
    double number;
    bool stop = false;

    while (!stop) {
        std::cout << "Enter a number (0 to stop): ";
        std::cin >> number;

        if (number == 0) {
            stop = true;
        } else {
            avg.add_value(number);
            std::cout << "Current Running Average: " << avg.get_average() << std::endl;
        }
    }

    std::cout << "Final Running Average: " << avg.get_average() << std::endl;
    return 0;
}
