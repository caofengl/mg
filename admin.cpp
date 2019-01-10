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
    cout << "请输入您的选择: (0 表示退出)";
    int num;
    cin >> num;
    if (num == 0) return;

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
    cout << "请输入您的选择: (0 表示退出)";
    int num;
    cin >> num;
    if (num == 0) return;

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
    cout << "请输入您的选择(0 表示退出):";
    cin >> num;
    if (num == 0) return;

    string id, grade, query;
    switch (num) {
    case 1:
        cm_->ShowStudentInfo(class_num);
        break;
    case 2:
        cout << "请输学生id和该课程的成绩: ";
        cin >> id >> grade;
        // cm_->courses_[class_num]->SetGrade(id, grade);
        cm_->SetGrade(class_num, id, grade);
        query = "UPDATE subject SET course_grade=" + grade + " WHERE student_id=" + id + " and course_num=" + to_string(class_num);
        dbms_->Execute(query);
        break;
    default:
        break;
    }
}


void Admin::ManageStudent() {
    cout << "1 添加学生信息\n";
    cout << "2 删除学生信息\n";
    cout << "请输入您的选择:(0 表示退出)";
    int num;
    cin >> num;
    if (num == 0) return;

    switch (num) {
    case 1:
        students_info_->AddStudentInfo();
        break;
    case 2:
        students_info_->DeleteStudentInfo();
        break;
    default:
        break;
    }
}
