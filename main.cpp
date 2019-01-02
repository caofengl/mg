#include <iostream>
#include "student.h"
#include "course.h"

using namespace std;

void StudentCase(Student* s) {
    cout << "Plase input id(110-150) password(default password is empty): ";
    string id, password;
    cin >> id >> password;
    s->setUser(id);

    cout << "\t1 changePassword\n";
    cout << "\t2 showCourseInfo\n";
    cout << "\t3 choiceCourse\n";
    cout << "\t4 queryGrade\n";
    cout << "\t5 showCourseInfo\n";

    int num;
    do {
        cout << "Plase input your choice(0 is quit): ";
        cin >> num;

        switch (num) {
        case 1:
            s->changePassword();
            break;
        case 2:
            s->showCourseInfo();
            break;
        case 3:
            s->choiceCourse();
            break;
        case 4:
            s->queryGrade();
            break;
        case 5:
            s->showIndividualInfo();
            break;
        default:
            break;
        }
    } while (num != 0);
}

void AdminCase() {

}

int main() {

    CourseManage* cm = new CourseManage();
    string stu_name = "101";
    Student student(stu_name, cm);

    int num;
    do {
        cout << "log in(0 is quit)" << endl;
        cout << "\t1: student" << endl;
        cout << "\t2: admin" << endl;
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
    } while (num != 0);

    delete cm;
    cm = NULL;

    return 0;
}
