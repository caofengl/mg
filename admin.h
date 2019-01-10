#ifndef ADMIN_H_
#define ADMIN_H_

#include <string>
#include <map>
#include "student.h"
#include "course.h"
#include "dbms.h"

class Admin {
public:
    Admin(StudentBasicInfo* sbi, Student* s, CourseManage* cm, DBMS* dbms)
        : students_(sbi), students_info_(s), cm_(cm), dbms_(dbms) { }
    void ManageClass();
    void ManageCourseInfo();
    void ManageSubjectCourse();
    void ManageScore();
    void ManageStudent();

private:
    StudentBasicInfo* students_;
    Student*          students_info_;
    CourseManage*     cm_;
    DBMS*             dbms_;
};


#endif  // ADMIN_H_

