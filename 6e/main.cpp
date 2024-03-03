#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>

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

    [[nodiscard]] string getAddress() const { return address; } // Getter for address

    friend ostream& operator<<(ostream& os, const House& house);
    friend istream& operator>>(istream& is, House& house);
    friend bool operator<(const House& lhs, const House& rhs);
};

class Apartment {
private:
    shared_ptr<House> house;
    string apt_number;
    double area;
    int rent;

public:
    Apartment() : area(0.0), rent(0) {}
    Apartment(std::shared_ptr<House> h, string apt_num, double ar, int r)
            : house(std::move(h)), apt_number(std::move(apt_num)), area(ar), rent(r) {}

    void setHouse(std::shared_ptr<House> h) { house = std::move(h); }
    void setApartmentNumber(const string& apt_num) { apt_number = apt_num; }
    void setArea(double ar) { area = ar; }
    void setRent(int r) { rent = r; }

    bool operator<(const Apartment& rhs) const {
        return rent < rhs.rent;
    }

    void printApartmentInfo() const {
        cout << "Address and apartment nr: " << house->getAddress() << ", " << apt_number << endl;
        cout << "Size of the apartment: " << area << endl;
        cout << "The monthly rent: " << rent << endl;
    }

    static Apartment createApartment(shared_ptr<House> house, const string& apt_number, double area, int rent) {
        Apartment apt;
        apt.setHouse(std::move(house));
        apt.setApartmentNumber(apt_number);
        apt.setArea(area);
        apt.setRent(rent);
        return apt;
    }

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
    // Create two houses
    shared_ptr<House> house1 = make_shared<House>("123 Street", 200.0, 500000);
    shared_ptr<House> house2 = make_shared<House>("456 Avenue", 300.0, 750000);

    // Set the values using setters
    house1->setAddress("123 Street");
    house1->setArea(200.0);
    house1->setPrice(500000);

    house2->setAddress("456 Avenue");
    house2->setArea(300.0);
    house2->setPrice(750000);

    // Define a vector of Apartments
    vector<Apartment> apartments;
    //USE MPLACE_BACK INSTEAD OF PUSH_BACK TYRY TO USE IT
    // Add three apartments of the first house using createApartment function
    apartments.push_back(Apartment::createApartment(house1, "Apt 1", 50.0, 1000));
    apartments.push_back(Apartment::createApartment(house1, "Apt 2", 60.0, 1200));
    apartments.push_back(Apartment::createApartment(house1, "Apt 3", 70.0, 1400));

    // Add four apartments of the second house
    apartments.push_back(Apartment::createApartment(house2, "Apt 1", 80.0, 1000));
    apartments.push_back(Apartment::createApartment(house2, "Apt 2", 90.0, 1200));
    apartments.push_back(Apartment::createApartment(house2, "Apt 3", 100.0, 1400));
    apartments.push_back(Apartment::createApartment(house2, "Apt 4", 110.0, 1500));

    // Sort the apartments
    sort(apartments.begin(), apartments.end());

    // Print the apartment information
    for (const auto& apartment : apartments) {
        apartment.printApartmentInfo();
        cout << endl;
    }

    return 0;
}