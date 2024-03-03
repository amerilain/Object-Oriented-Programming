#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
class House {
private:
    string address;
    double area;
    int price;

public:
    House() : area(0.0), price(0) {}
    House(string addr, double ar, int pr) : address(std::move(addr)), area(ar), price(pr) {}

    void setAddress(const string& addr) { address = addr; }
    void setArea(double ar) { area = ar; }
    void setPrice(int pr) { price = pr; }

    [[nodiscard]] double getPricePerSquareMeter() const {
        return price / area;
    }

    friend ostream& operator<<(ostream& os, const House& house);
    friend istream& operator>>(istream& is, House& house);
    friend bool operator<(const House& lhs, const House& rhs);
};

ostream& operator<<(ostream& os, const House& house) {
    os << house.address << ", " << house.area << ", " << house.price ; return os;
}

istream& operator>>(istream& is, House& house) {
    getline(is, house.address, ','); // Using comma as delimiter
    is >> house.area;
    is.ignore();
    is >> house.price;
    return is;
}

bool operator<(const House& lhs, const House& rhs) {
    return lhs.getPricePerSquareMeter() < rhs.getPricePerSquareMeter();
}

int main() {
    vector<House> houses;
    string line;
    string address;
    double area;
    int price;

    cout << "Enter information for house 1 (address, area, price): ";
    getline(cin, address, ',');
    cin >> area;
    cin.ignore();
    cin >> price;
    houses.emplace_back(address, area, price);


    House house2;
    cout << "Enter information for house 2 (address, area, price): ";
    getline(cin, address, ',');
    cin >> area;
    cin.ignore();
    cin >> price;
    house2.setAddress(address);
    house2.setArea(area);
    house2.setPrice(price);
    houses.push_back(house2);

    // Houses 3 to 5
    for (int i = 3; i <= 5; ++i) {
        House house;
        cout << "Enter information for house " << i << " (address, area, price): ";
        cin >> house;
        houses.push_back(house);
    }

    // Sorting and outputting the houses
    sort(houses.begin(), houses.end());
    for (const auto& house : houses) {
        cout << house << endl;
    }

    return 0;
}