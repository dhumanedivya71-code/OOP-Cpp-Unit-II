#include <iostream>
#include <string>
using namespace std;

class Department {
protected:
    string departmentName;

public:
    Department(string d) {
        departmentName = d;
    }
};

class Teacher : public Department {
private:
    string subject;

public:
    Teacher(string d, string s) : Department(d) {
        subject = s;
    }

    void display() {
        cout << "Department: " << departmentName << endl;
        cout << "Subject: " << subject << endl;
    }
};

int main() {
    Teacher t("Computer Engineering", "C++");

    t.display();

    return 0;
}
