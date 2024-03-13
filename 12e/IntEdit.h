//
// Created by Keijo Länsikunnas on 5.3.2024.
//

#ifndef LAB12_INTEDIT_H
#define LAB12_INTEDIT_H

#include <string>
#include <vector>
#include "MenuItem.h"
#include "Observer.h" // Include the Observer interface

class IntEdit : public MenuItem {
public:
    explicit IntEdit(std::string menu_title);
    bool event(menuEvent e) override;
    void show() override;

    // Observer management
    void addObserver(Observer* observer);
    void removeObserver(Observer* observer);
    void notifyObservers();

protected:
    int value;
    int backup;
    bool changed;
    std::vector<Observer*> observers; // List of observers
};

#endif //LAB12_INTEDIT_H
