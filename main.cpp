#include <iostream>
#include "student.h"
#include "course.h"

using namespace std;

void StudentCase(Student* s) {
    cout << "Plase input id password:(default password is empty)\n";
    string id, password;
    cin >> id >> password;

    cout << "1 changePassword\n";
    cout << "2 showCourseInfo\n";
    cout << "Plase input your choice:\n";
    int num;
    cin >> num;

    switch (num) {
    case 1:
        s->changePassword("1");
        break;
    case 2:
        s->showCourseInfo();
    default:
        break;
    }
}

void AdminCase() {

}

int main() {

    CourseManage* cm = new CourseManage();
    string stu_name = "cf";
    Student student(stu_name, cm);

    cout << "log in" << endl;
    cout << "\t1: student" << endl;
    cout << "\t2: admin" << endl;

    int num;
    cin >> num;
    switch (num) {
    case 1:
        StudentCase(&student);
        break;
    case 2:
        AdminCase();
        break;
    default:
        break;
    }

    return 0;
}
