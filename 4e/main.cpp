#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <limits>

class House {
private:
    std::string address;
    double area;
    int price;

public:
    explicit House(std::string addr = "", double ar = 0.0, int pr = 0) : address(addr), area(ar), price(pr) {}

    void setAddress(const std::string& addr) { address = addr; }
    void setArea(double ar) { area = ar; }
    void setPrice(int pr) { price = pr; }

    friend std::ostream& operator<<(std::ostream& os, const House& h);
    friend std::istream& operator>>(std::istream& is, House& h);
    bool operator<(const House& other) const;
};

std::ostream& operator<<(std::ostream& os, const House& h) {
    os << "Address: " << h.address << ", Area: " << h.area << " m², Price: " << h.price << " euros";
    return os;
}

std::istream& operator>>(std::istream& is, House& h) {
    std::cout << "Address: ";
    is.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear any leftover input
    std::getline(is, h.address);
    std::cout << "Area: ";
    is >> h.area;
    std::cout << "Price: ";
    is >> h.price;
    is.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the input buffer
    return is;
}

bool House::operator<(const House& other) const {
    return (price / area) < (other.price / other.area);
}

int main() {
    std::vector<House> houses;
    std::string addr;
    double area;
    int price;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    // Using parameterized constructor for house 1
    std::cout << "Enter details for house 1:\n";
    std::cout << "Address: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear buffer
    std::getline(std::cin, addr); // Read address with spaces
    std::cout << "Area: ";
    std::cin >> area;
    std::cout << "Price: ";
    std::cin >> price;
    houses.emplace_back(addr, area, price);

    // Repeat the same for other houses
    for (int i = 2; i <= 5; ++i) {
        std::cout << "Enter details for house " << i << ":\n";
        std::cout << "Address: ";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear buffer
        std::getline(std::cin, addr); // Read address with spaces
        std::cout << "Area: ";
        std::cin >> area;
        std::cout << "Price: ";
        std::cin >> price;
        houses.emplace_back(addr, area, price);
    }

    // Sort and display houses
    std::sort(houses.begin(), houses.end());
    std::cout << "\nSorted Houses:\n";
    for (const auto& h : houses) {
        std::cout << h << '\n';
    }

    return 0;
}
