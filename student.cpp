#include <iostream>
#include "student.h"
#include "course.h"

using namespace std;

Student::Student(const std::string& user,
                 StudentBasicInfo* sbi,
                 CourseManage* cm)
    : user_(user),
      student_info_(sbi),
      course_manage_(cm) {
    for (int i = 100; i < 151; ++i) {
        student_info_->students[std::to_string(i)] = new StudentBasicInfo();
    }
}

Student::~Student() {
    for (auto& student : student_info_->students) {
        delete student.second;
        student.second = NULL;
    }
    student_info_->students.clear();
}

void Student::changePassword() {
    cout << "请输入您的新密码: ";
    cin >> student_info_->students[user_]->password;
}

void Student::showCourseInfo() {
    course_manage_->ShowCourseInfo();
}

void Student::choiceCourse() {
    showCourseInfo();
    cout << "请输入您要选择的课程编号: ";
    int num;
    cin >> num;
    course_manage_->AddStudent(num, user_, student_info_->students[user_]);
    student_info_->students[user_]->major[num] = 0;
}

void Student::queryGrade() {
    cout << user_ << " grade:" << endl;
    for (const auto& subject : student_info_->students[user_]->major) {
        cout << "num: " << subject.first
             << " grade: " << subject.second << endl;
    }
}

void Student::showIndividualInfo() {
    cout << "info\n";
    cout << "\t id:  " << user_ << endl;
    cout << "\t name:" << student_info_->students[user_]->name << endl;
    cout << "\t age: " << student_info_->students[user_]->age<< endl;
}
