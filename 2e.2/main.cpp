#include <iostream>
#include <string>
#include <vector>
#include <filesystem>
#include <fstream>

int main() {
    std::vector<std::string> dirNames;
    std::string input;

    std::cout << "Enter directory names (blank line to stop): ";
    while (std::getline(std::cin, input) && !input.empty()) {
        dirNames.push_back(input);
        std::cout << "Enter another directory name (blank line to stop): ";
    }

    // iterate through the vector and append the names to the path
    std::filesystem::path dirPath;
    for (const auto& name : dirNames) {
        dirPath /= name;
    }

    std::filesystem::create_directories(dirPath);

    // Writing results to the file and screen
    std::filesystem::path resultFilePath = dirPath / "result.txt";
    std::ofstream resultFile(resultFilePath);

    std::cout << "Absolute Path: " << std::filesystem::absolute(resultFilePath) << std::endl;
    resultFile << "Absolute Path: " << std::filesystem::absolute(resultFilePath) << std::endl;
    
    for (const auto& name : dirNames) {
        std::cout << name << std::endl;
        resultFile << name << std::endl;
    }

    std::cout << "Relative Path: " << dirPath << std::endl;
    resultFile << "Relative Path: " << dirPath << std::endl;

    resultFile.close();
    return 0;
}
