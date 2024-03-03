#include <iostream>
#include <string>
#include <map>

//define a map<string, int> to store names and numbers
std::map<std::string, int> myMap;

int main() {
    bool stop = false;
    while (!stop) {
        std::string name;
        std::cout << "Enter a name or 'stop' or 'print': ";
        std::cin >> name;
        if (name == "stop") {
            std::cout << "Program stopped." << std::endl;
            stop = true;
        } else if (name == "print") {
            // print the content of the map in alphabetical order
            for (auto & it : myMap) {
                std::cout << it.first << " " << it.second << std::endl;
            /*
            // initialize an iterator to the beginning of the map
            std::map<std::string, int> :: iterator iter;
            for (iter = myMap.begin(); iter != myMap.end(); ++iter) {
                std::cout << iter->first << " : " << iter->second << std::endl;
            */
            }

        } else {
            int number;
            std::cout << "Enter a number: ";
            std::cin >> number;
            myMap[name] = number;
        }
    }
    return 0;
}
