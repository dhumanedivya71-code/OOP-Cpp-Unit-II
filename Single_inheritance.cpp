#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int age;

public:
    Person(string n, int a) {
        name = n;
        age = a;
    }

    void showPerson() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class Employee : public Person {
private:
    int employeeId;

public:
    Employee(string n, int a, int id) : Person(n, a) {
        employeeId = id;
    }

    void showEmployee() {
        showPerson();
        cout << "Employee ID: " << employeeId << endl;
    }
};

int main() {
    Employee e("Rahul", 21, 105);

    e.showEmployee();

    return 0;
}
