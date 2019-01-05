#ifndef ADMIN_H_
#define ADMIN_H_

#include <string>
#include <map>
#include "student.h"
#include "course.h"

class Admin {
public:
    Admin(StudentBasicInfo* sbi, CourseManage* cm)
        : students_(sbi), cm_(cm) { }
    void ManageClass();
    void ManageCourseInfo();
    void ManageSubjectCourse();
    void ManageScore();
    void ManageStudent();

private:
    StudentBasicInfo* students_;
    CourseManage* cm_;
};


#endif  // ADMIN_H_
