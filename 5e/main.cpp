#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iterator>

using namespace std;

class RandGen {
public:
    RandGen(int min, int max) : _min(min), _max(max) {
        srand(static_cast<unsigned int>(time(NULL)));
    }

    int operator()() {
        int number;
        do { number = rand() % (_max - _min + 1) + _min; }
        while (find(_numbers.begin(), _numbers.end(), number) != _numbers.end());
        _numbers.push_back(number);
        return number;
    }

private:
    int _min, _max;
    vector<int> _numbers;
};

// Function object to print numbers with an index
class PrintWithIndex {
public:
    PrintWithIndex() : index(0) {}

    void operator()(int number) {
        cout << "#" << ++index << ": " << number << endl;
    }

private:
    int index;
};

void generateAndPrintSets(vector<int> &set, RandGen &generator, const string &title) {
    generate_n(set.begin(), set.size(), generator);
    sort(set.begin(), set.end());
    cout << title << ": ";
    copy(set.begin(), set.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}

int main() {
    char userChoice;
    do {
        int lotto_size = 7;
        int viking_size = 6;
        int euro_size = 5;
        int min_num = 1;
        int lotto_max = 40;
        int viking_max = 48;
        int euro_max = 50;

        vector<int> lotto(lotto_size), vikingLotto(viking_size), eurojackpot(euro_size);
        RandGen genLotto(min_num, lotto_max), genViking(min_num, viking_max), genEurojackpot(min_num, euro_max);

        generateAndPrintSets(lotto, genLotto, "Lotto");
        generateAndPrintSets(vikingLotto, genViking, "Viking Lotto");

        // Find and print matching numbers between Lotto and Viking Lotto
        vector<int> common;
        set_intersection(lotto.begin(), lotto.end(), vikingLotto.begin(), vikingLotto.end(), back_inserter(common));

        cout << "Matching numbers:\n";
        if (!common.empty()) {
            for_each(common.begin(), common.end(), PrintWithIndex());
        } else {
            cout << "None\n";
        }

        generateAndPrintSets(eurojackpot, genEurojackpot, "Eurojackpot");

        // Find and print matching numbers across all three sets
        vector<int> commonFinal;
        set_intersection(common.begin(), common.end(), eurojackpot.begin(), eurojackpot.end(),
                         back_inserter(commonFinal));

        cout << "Matching numbers in three sets:\n";
        if (!commonFinal.empty()) {
            PrintWithIndex printWithIndex; // Define an instance of PrintWithIndex
            for_each(commonFinal.begin(), commonFinal.end(), printWithIndex);
        } else {
            cout << "None\n";
        }

        cout << "Generate another set? (Y/N): ";
        cin >> userChoice;
    } while (userChoice == 'Y' || userChoice == 'y');
    return 0;
}
