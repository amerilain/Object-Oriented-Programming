#include <iostream>
#include <string>
#include <algorithm>

class Observer;
class Subject {
public:
    virtual void Attach(Observer *o) = 0; // Set
    virtual void Notify() = 0;
};

// Abstract interface of observer
class Observer {
public:
    virtual void Update() = 0;
};


class Person {
public:
    explicit Person(const char *name = "nobody");
    virtual ~Person();
    virtual void identity() const;
    virtual void interrogate();
    std::string getName() const;

private:
    std::string name;
};

Person::Person(const char *name) : name(name) {}

Person::~Person() = default;

void Person::identity() const {
    std::cout << "My name is: " << getName() << std::endl;
}

void Person::interrogate() {}

std::string Person::getName() const { return name; }

class Spy : public Person, public Subject {
public:
    Spy(const char *name, const char *alias, int resistance);
    void set_identity(const char *newAlias);
    void identity() const override;
    void interrogate() override;
    void Attach(Observer *o) override;
    void Notify() override;

private:
    std::string alias;
    int resistance;
    Observer *observer;
};

Spy::Spy(const char *name, const char *alias, int resistance)
        : Person(name), alias(alias), resistance(resistance), observer(nullptr) {}

void Spy::Attach(Observer *o) {
    observer = o;
}

void Spy::Notify() {
    if (observer) {
        observer->Update();
    }
}

void Spy::interrogate() {
    resistance = std::max(0, resistance - 1);
    if (resistance == 0) {
        Notify();
    }
}

void Spy::identity() const {
    if (resistance > 0) {
        std::cout << "My name is: " << alias << std::endl;
    } else {
        Person::identity();
        std::cout << "My alias is: " << alias << std::endl;
    }
}

void Spy::set_identity(const char *newAlias) {
    alias = std::string(newAlias);
}

class Judge : public Person, public Observer {
public:
    explicit Judge(const char *name);
    void Update() override;
};

Judge::Judge(const char *name) : Person(name) {}

void Judge::Update() {
    identity();
    std::cout << "I'm sending a spy to prison!" << std::endl;
}

int main() {
    Person agent("James Bond");
    Spy spy("Emilio Largo", "William Johnson", 3);
    Spy spy2("Ernst Blofield", "John Keats", 5);
    Judge judge("Judge Barnhill");
    spy.Attach(&judge);
    spy2.Attach(&judge);

    // 1st interaction with an agent.
    std::cout << std::endl << "Nice to meet you. ";
    agent.identity();

    // Interrogate first spy.
    for (int i = 0; i < 6; ++i) {
        std::cout << "Who are you?" << std::endl;
        spy.interrogate();
        spy.identity();
    }
    // Change first spy's alias
    spy.set_identity("Bill Munny");
    spy.identity();

    // 2nd Interaction with an agent
    std::cout << std::endl << "Nice to meet you. ";
    agent.identity();

    // Interrogate second spy.
    for (int i = 0; i < 6; ++i) {
        std::cout << "Who are you?" << std::endl;
        spy2.interrogate();
        spy2.identity();
    }

    return 0;
}