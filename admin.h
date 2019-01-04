#ifndef ADMIN_H_
#define ADMIN_H_

#include <string>
#include <map>
#include "student.h"
#include "course.h"

class Admin {
public:
    Admin(CourseManage* cm) : cm_(cm) { }
    void ManageCourseInfo();

private:
    std::map<std::string, StudentBasicInfo*> students_;
    CourseManage* cm_;
};


#endif  // ADMIN_H_
