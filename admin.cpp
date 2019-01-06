#include <iostream>
#include "admin.h"

using namespace std;

void Admin::ManageClass() {
    cout << "请输入要查看的班级号";
    string num;
    cin >> num;

    for (auto& student : students_->students) {
        if (student.second->class_num == num) {
            cout << "姓名: " << student.second->name << endl;
        }
    }
}

void Admin::ManageCourseInfo() {
    cm_->ShowCourseInfo();
    cout << "\t1: 设置课时总数\n";
    cout << "\t2: 设置最大学生数\n";
    cout << "请输入您的选择: ";
    int num;
    cin >> num;

    cout << "请输入课程编号:";
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
    cout << "\t1 查看学生选课情况\n";
    cout << "\t2 调整课程\n";
    cout << "请输入您的选择: ";
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

void Admin::ManageScore() {
    cm_->ShowCourseInfo();
    cout << "请输入要操作的课程编号:";
    int class_num;
    cin >> class_num;

    int num;
    cout << "1 查看学生\n";
    cout << "2 设置课程分数\n";
    cout << "请输入您的选择:";
    cin >> num;

    switch (num) {
    case 1:
        cm_->courses_[class_num]->ShowStudentInfo();
        break;
    case 2:
        cm_->courses_[class_num]->SetGrade();
        break;
    default:
        break;
    }
}
