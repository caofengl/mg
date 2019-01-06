#include "course.h"

using namespace std;

void Course::ShowStudentInfo() {
    cout << "姓名:\n";
    for (auto& student : students_) {
        if (student.second->major.find(num_) ==
                student.second->major.end()) {
            continue;
        }
        cout << "\t" << student.second->name << endl;
    }
}

void Course::SetGrade() {
    string name;
    int grade;
    cout << "请输学生姓名和该课程的成绩: ";
    cin >> name >> grade;
    students_[name]->major[num_] = grade;
}
