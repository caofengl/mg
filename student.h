#ifndef STUDENT_H_
#define STUDENT_H_

#include <map>
#include <string>
#include "course.h"
#include "dbms.h"

class CourseManage;

struct StudentBasicInfo {
    std::string        id;
    std::string        password;
    std::string        name;
    std::string        age;
    std::string        class_num;
    std::map<int, int> major;
    std::map<std::string, StudentBasicInfo*> students;

    StudentBasicInfo() : password("1"), name(""), age("20"), class_num("1") { }
    StudentBasicInfo(std::string id,
                     std::string password,
                     std::string name,
                     std::string age,
                     std::string class_num)
        : id(id), password(password),
          name(name), age(age), class_num(class_num) { }
};

class Student {
public:
    Student(const std::string& user,
            StudentBasicInfo* sbi,
            CourseManage* cm,
            DBMS* dbms);
    ~Student();

    void setUser(const std::string& user) { user_ = user; }

    void changePassword();
    void showCourseInfo();
    void choiceCourse();
    void queryGrade();
    void showIndividualInfo();

    void AddStudentInfo();
    void DeleteStudentInfo();

private:
    std::string       user_;
    StudentBasicInfo* student_info_;
    CourseManage*     course_manage_;
    DBMS*             dbms_;
};


#endif  // STUDENT_H_
