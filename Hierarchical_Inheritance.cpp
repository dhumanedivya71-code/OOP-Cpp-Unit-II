#include <iostream>
#include <string>
using namespace std;

class Animal {
protected:
    string name;

public:
    Animal(string n) {
        name = n;
    }

    void eat() {
        cout << name << " is eating." << endl;
    }
};

class Dog : public Animal {
public:
    Dog(string n) : Animal(n) {
    }

    void bark() {
        cout << name << " is barking." << endl;
    }
};

class Cat : public Animal {
public:
    Cat(string n) : Animal(n) {
    }

    void meow() {
        cout << name << " is meowing." << endl;
    }
};

int main() {
    Dog d("Bruno");
    Cat c("Mimi");

    d.eat();
    d.bark();

    c.eat();
    c.meow();

    return 0;
}
