#ifndef COURSE_H_
#define COURSE_H_

#include <iostream>
#include <string>
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

    void ShowStudentInfo();

    void SetGrade();

    void RecordStudentInfo(const std::string& name,
                           StudentBasicInfo* cbi) {
        students_[name] = cbi;
    }

    void SetHour(int hour) { hour_ = hour; }

    void SetCapacity(int capacity) { capacity_ = capacity; }

    int         num_;
    std::string teacher_;
    int         hour_;
    int         capacity_;
    std::string classroom_;

// private:
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
        std::cout << "高数课，容量: " << capacity_ << std::endl;
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
        std::cout << "C++ 课程，容量: " << capacity_ << std::endl;
    }
};

class CourseManage {
public:
    CourseManage() {
        courses_.insert({1, new MathCourse(1, "M", 36, 30, "16-101")});
        courses_.insert({2, new CppCourse(2, "M", 36, 30, "16-102")});
    }

    void AddCourse(int num, Course* course) { courses_[num] = course; }

    void ShowCourseInfo() {
        for (const auto& course: courses_) {
            course.second->CourseInfo();
            std::cout << "课程编号:" << course.second->num_ << std::endl
                      << "老师:" << course.second->teacher_ << std::endl
                      << "课时:" << course.second->hour_ << std::endl
                      << "容量:" << course.second->capacity_<< std::endl;
            std::cout << std::endl;
        }
    }

    void AddStudent(int num,
                    const std::string& id,
                    StudentBasicInfo* sbi) {
        if (courses_.find(num) == courses_.end()) {
            std::cout << "没有这门课程\n";
            return;
        }

        if (courses_[num]->capacity_ <= 0) {
            std::cout << "选择该课程的人数已达上限\n";
            return;
        }

        --courses_[num]->capacity_;
        courses_[num]->RecordStudentInfo(id, sbi);
    }

    void SetCourseTime(int num) {
        std::cout << "请输入调整后的课程时长:";
        int hour;
        std::cin >> hour;
        courses_[num]->SetHour(hour);
    }

    void SetCourseCapacity(int num) {
        std::cout << "请输入调整后的课程容量:";
        int capacity;
        std::cin >> capacity;
        courses_[num]->SetCapacity(capacity);
    }

// private:
    std::map<int, Course*> courses_;
};


#endif  // COURSE_H_
