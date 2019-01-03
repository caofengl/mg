#include <iostream>
#include "student.h"
#include "course.h"

using namespace std;

Student::Student(const std::string& user, CourseManage* cm)
    : user_(user),
      course_manage_(cm) {
    for (int i = 100; i < 151; ++i) {
        students_[std::to_string(i)] = new StudentBasicInfo();
    }
}

Student::~Student() {
    for (auto& student : students_) {
        delete student.second;
        student.second = NULL;
    }
    students_.clear();
}

void Student::changePassword() {
    cout << "请输入您的新密码: ";
    cin >> students_[user_]->password;
}

void Student::showCourseInfo() {
    course_manage_->ShowCourseInfo();
}

void Student::choiceCourse() {
    showCourseInfo();
    cout << "请输入您要选择的课程编号: ";
    int num;
    cin >> num;
    course_manage_->AddStudent(num, user_, students_[user_]);
    students_[user_]->major[num] = 0;
}

void Student::queryGrade() {
    cout << user_ << " grade:" << endl;
    for (const auto& subject : students_[user_]->major) {
        cout << "num: " << subject.first
             << " grade: " << subject.second << endl;
    }
}

void Student::showIndividualInfo() {
    cout << "info\n";
    cout << "\t id:  " << user_ << endl;
    cout << "\t name:" << students_[user_]->name << endl;
    cout << "\t age: " << students_[user_]->age<< endl;
}
