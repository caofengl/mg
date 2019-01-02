#ifndef COURSE_H_
#define COURSE_H_

#include <iostream>
#include <map>
#include <set>
#include "student.h"

struct StudentBasicInfo;

class Course {
public:
    Course(int num,
           const std::string& teacher,
           int hour,
           int capacity,
           const std::string& classroom)
        : num_(num),
          teacher_(teacher),
          hour_(hour),
          capacity_(capacity),
          classroom_(classroom) { }

    virtual void CourseInfo() = 0;

    int         num_;
    std::string teacher_;
    int         hour_;
    int         capacity_;
    std::string classroom_;

private:
    std::map<std::string, StudentBasicInfo*> students_;
};


class MathCourse : public Course {
public:
    MathCourse(int num,
               const std::string& teacher,
               int hour,
               int capacity,
               const std::string& classroom)
        : Course(num, teacher, hour, capacity, classroom) { }

    void CourseInfo() {
        std::cout << "Math course capacity: " << capacity_ << std::endl;
    }
};

class CppCourse : public Course {
public:
    CppCourse(int num,
              const std::string& teacher,
              int hour,
              int capacity,
              const std::string& classroom)
        : Course(num, teacher, hour, capacity, classroom) { }

    void CourseInfo() {
        std::cout << "Cpp course capacity: " << capacity_ << std::endl;
    }
};

class CourseManage {
public:
    CourseManage() {
        courses_.insert(new MathCourse(1, "M", 36, 30, "16-101"));
        courses_.insert(new CppCourse(2, "M", 36, 30, "16-102"));
    }

    void AddCourse(Course* course) { courses_.insert(course); }

    void ShowCourseInfo() {
        for (const auto& course: courses_) {
            course->CourseInfo();
            std::cout << "num:" << course->num_ << std::endl
                      << "teacher:" << course->teacher_ << std::endl
                      << "hour:" << course->hour_ << std::endl
                      << "capacity:" << course->capacity_<< std::endl;
            std::cout << std::endl;
        }
    }

    void AddStudent(int num, const string& id, const StudentBasicInfo* sbi) {
        bool exist = false;
        for (auto& course: courses_) {
            if (course->num_ == num) {
                exist = true;
                if (course->capacity_ > 0) {
                    --course->capacity_;
                    students_[id] = sbi;
                }
                else {
                    std::cout << "choice course failed!\n";
                }
                break;
            }
        }
        if (!exist) std::cout << "There is no course!\n";
    }

private:
    std::set<Course*> courses_;
};


#endif  // COURSE_H_
