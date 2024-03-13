//
// Created by Keijo Länsikunnas on 5.3.2024.
//

#include "IntEdit.h"
#include <iostream>

IntEdit::IntEdit(std::string menu_title) :
        MenuItem(menu_title), value(0), backup(0), changed(false) {
}

bool IntEdit::event(MenuItem::menuEvent e) {
    bool handled = true;
    switch (e) {
        case MenuItem::up:
            if (!changed) {
                changed = true;
                backup = value;
            }
            ++value;
            show();
            break;
        case MenuItem::down:
            if (!changed) {
                changed = true;
                backup = value;
            }
            --value;
            show();
            break;
        case MenuItem::ok:
            if (changed) {
                changed = false;
                notifyObservers(); // Notify observers of the change
            }
            break;
        case MenuItem::back:
            if (changed) {
                changed = false;
                value = backup;
                show();
            } else {
                handled = false;
            }
            break;
    }
    return handled;
}

void IntEdit::show() {
    std::cout << "[" << menu_title << "]" << std::endl;
    std::cout << "Value: " << value << std::endl;
}

void IntEdit::addObserver(Observer* observer) {
    observers.push_back(observer);
}

void IntEdit::removeObserver(Observer* observer) {
    observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}

void IntEdit::notifyObservers() {
    for (auto* observer : observers) {
        observer->update(value);
    }
}
