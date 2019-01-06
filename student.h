#ifndef STUDENT_H_
#define STUDENT_H_

#include <map>
#include <string>
#include "course.h"

class CourseManage;

struct StudentBasicInfo {
    std::string        password;
    std::string        name;
    unsigned int       age;
    std::string        class_num;
    std::map<int, int> major;
    std::map<std::string, StudentBasicInfo*> students;
    StudentBasicInfo() : password("1"), name(""), age(0), class_num("1") { }
};

class Student {
public:
    Student(const std::string& user, StudentBasicInfo* sbi, CourseManage* cm);
    ~Student();

    void setUser(const std::string& user) { user_ = user; }

    void changePassword();
    void showCourseInfo();
    void choiceCourse();
    void queryGrade();
    void showIndividualInfo();

private:
    std::string       user_;
    StudentBasicInfo* student_info_;
    CourseManage*     course_manage_;
};


#endif  // STUDENT_H_
