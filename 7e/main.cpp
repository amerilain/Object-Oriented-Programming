#include <iostream>
#include <string>
#include <algorithm>

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


class Spy : public Person {
public:
    Spy(const char *name, const char *alias, int resistance);
    void set_identity(const char *newAlias);
    void identity() const override;
    void interrogate() override;

private:
    std::string alias;
    int resistance;

};

Spy::Spy(const char *name, const char *alias, int resistance)
        : Person(name), alias(alias), resistance(resistance) {}

void Spy::set_identity(const char *newAlias) {
    alias = std::string(newAlias);
}

void Spy::identity() const {
    if (resistance > 0) {
        std::cout << "My name is: " << alias << std::endl;
    } else {
        Person::identity();
        std::cout << "My alias is: " << alias << std::endl;
    }
}

void Spy::interrogate() {
    resistance = std::max(0, resistance - 1);
}

int main() {
    Person agent("James Bond");
    Spy spy("Emilio Largo", "William Johnson", 3);
    Spy spy2("Ernst Blofield", "John Keats", 5);

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
