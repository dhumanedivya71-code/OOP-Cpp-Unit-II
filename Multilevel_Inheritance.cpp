#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;

public:
    Person(string n) {
        name = n;
    }

    void showName() {
        cout << "Name: " << name << endl;
    }
};

class Student : public Person {
protected:
    int rollNumber;

public:
    Student(string n, int r) : Person(n) {
        rollNumber = r;
    }

    void showStudent() {
        cout << "Roll Number: " << rollNumber << endl;
    }
};

class Result : public Student {
private:
    int marks;

public:
    Result(string n, int r, int m) : Student(n, r) {
        marks = m;
    }

    void showResult() {
        showName();
        showStudent();
        cout << "Marks: " << marks << endl;
    }
};

int main() {
    Result r("Sneha", 25, 88);

    r.showResult();

    return 0;
}
