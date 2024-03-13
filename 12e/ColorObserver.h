//
// Created by Aleksi Merilainen on 11.3.2024.
//

#ifndef LAB12_COLOROBSERVER_H
#define LAB12_COLOROBSERVER_H

#include "Observer.h"
#include <iostream>
#include <string>

class ColorObserver : public Observer {
public:
    ColorObserver(const std::string& colorName) : colorName(colorName) {}

    void update(int newValue) override {
        std::cout << colorName << " color changed to: " << newValue << std::endl;
    }

private:
    std::string colorName;
};

#endif //LAB12_COLOROBSERVER_H

