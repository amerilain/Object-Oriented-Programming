#include <iostream>
#include <string>
#include <sstream>
using namespace std;


int main() {
    string str;
    bool stop = false;

    while (!stop) {
        int sum = 0;
        int count = 0;
        cout << "\nEnter a line with numbers or 'stop': ";
        getline (cin, str);
        if (str == "stop") {
            stop = true;
        } else {
            // create string stream from the user input and read integers from the stream.
            stringstream ss(str);
            int num;
            while (ss >> num) {
                sum += num;
                count++;
            }
            // print the sum and count of the integers (example: "Total of 6 numbers is 129")
            cout << "Total of " << count << " numbers is " << sum << endl;

        }
    }






    return 0;
}
