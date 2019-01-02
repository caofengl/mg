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
    std::map<int, int> major;
    StudentBasicInfo() : password("1"), name(""), age(0) { }
};

class Student {
public:
    Student(const std::string& user, CourseManage* cm);
    ~Student();

    void setUser(const std::string& user) { user_ = user; }

    void changePassword();
    void showCourseInfo();
    void choiceCourse();
    void queryGrade();
    void showIndividualInfo();

private:
    std::string user_;
    std::map<std::string, StudentBasicInfo*> students_;
    CourseManage* course_manage_;
};


#endif  // STUDENT_H_
