#include <iostream>

using namespace std;

class Counter {
public:
    virtual void inc() = 0;

    virtual void dec() = 0;

    virtual operator int() = 0;

    virtual ~Counter() {};
};


class LimitedCounter : public Counter {
private:
    int counter;
    int upperLimit;
public:
    LimitedCounter(int initialValue, int upperLimit) : counter(initialValue), upperLimit(upperLimit) {}

    void inc() override {
        if (counter < upperLimit) {
            counter++;
        }
    }

    void dec() override {
        if (counter > 0) {
            counter--;
        }
    }

    operator int() override {
        return counter;
    }
};

class OverflowCounter : public Counter {
private:
    int counter;
    int upperLimit;
public:
    OverflowCounter(int initialValue, int upperLimit) : counter(initialValue), upperLimit(upperLimit) {}

    void inc() override {
        counter++;
        if (counter > upperLimit) {
            counter = 0;
        }
    }

    void dec() override {
        if (counter == 0) {
            counter = upperLimit;
        } else {
            counter--;
        }
    }

    operator int() override {
        return counter;
    }
};

// you need to implement this function
void UseCounter(Counter &ctr, int num) {
    if (num > 0) {
        for (int i = 0; i < num; i++) {
            ctr.inc();
        }
    } else {
        for (int i = 0; i < -num; i++) {
            ctr.dec();
        }
    }
}


int main(int argc, char **argv) {
    LimitedCounter lc(0, 5);
    OverflowCounter oc(5, 9);

    cout << oc << endl;
    UseCounter(oc, 5);
    cout << oc << endl; // should display zero
    UseCounter(oc, -1);
    cout << oc << endl; // should display 9
    oc.dec();
    cout << oc << endl; // should display 8

    cout << lc << endl;
    lc.inc();
    cout << lc << endl;
    lc.dec();
    cout << lc << endl;
    for (int i = 0; i < 10; ++i) lc.inc();
    cout << lc << endl;
    UseCounter(lc, -9);
    cout << lc << endl;

    return 0;
}
