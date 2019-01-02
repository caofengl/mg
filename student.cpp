#include <iostream>
#include "student.h"
#include "course.h"

using namespace std;

Student::Student(const std::string& user, CourseManage* cm)
    : user_(user),
      course_manage_(cm) {
    for (int i = 100; i < 149; ++i) {
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

void Student::changePassword(const string& new_password) {
    students_[user_]->password = new_password;
}

void Student::showCourseInfo() {
    course_manage_->ShowCourseInfo();
}

void Student::choiceCourse() {
    cout << "Plase course num:";
    int num;
    cin >> num;
    course_manage_->AddStudent(num);
    students_[user_]->major.insert({1, 0});
}

void Student::queryGrade() {
    std::cout << user_ << " grade:" << endl;
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
