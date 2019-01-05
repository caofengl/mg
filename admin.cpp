#include <iostream>
#include "admin.h"

using namespace std;

void Admin::ManageClass() {
    cout << "Plase input class num to show:";
    string num;
    cin >> num;

    for (auto& student : students_->students) {
        if (student.second->class_num == num) {
            cout << "Name: " << student.second->name << endl;
        }
    }
}

void Admin::ManageCourseInfo() {
    cm_->ShowCourseInfo();
    cout << "\t1: set hour\n";
    cout << "\t2: set capacity\n";
    cout << "choice func: ";
    int num;
    cin >> num;

    cout << "Plase class num:";
    int class_num = 0;
    cin >> class_num;
    switch (num) {
    case 1:
        cm_->SetCourseTime(class_num);
        break;
    case 2:
        cm_->SetCourseCapacity(class_num);
        break;
    default:
        break;
    }
}

void Admin::ManageSubjectCourse() {
    cout << "\t1 show subject of student\n";
    cout << "\t2 update subject\n";
    cout << "Plase input your choice: ";
    int num;
    cin >> num;

    switch (num) {
    case 1:
        for (auto& student : students_->students) {
            if (student.second->major.empty()) continue;
            cout << student.second->name << " :\n\t";
            for (auto& course : student.second->major) {
                cout << course.first << " ";
            }
            cout << "\n\n";
        }
        break;
    case 2:
        break;
    default:
        break;
    }
}
