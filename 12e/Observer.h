//
// Created by Aleksi Merilainen on 11.3.2024.
//

#ifndef LAB12_OBSERVER_H
#define LAB12_OBSERVER_H

class Observer {
public:
    virtual void update(int newValue) = 0;
    virtual ~Observer() = default;
};

#endif //LAB12_OBSERVER_H

