#include <iostream>
using namespace std;

class College {
public:
    void collegeInfo() {
        cout << "This is a college." << endl;
    }
};

class Student : public College {
};

class Teacher : private College {
public:
    void showInfo() {
        collegeInfo();
    }
};

int main() {
    Student s;
    s.collegeInfo();

    Teacher t;
    t.showInfo();

    return 0;
}
