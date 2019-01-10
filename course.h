#ifndef COURSE_H_
#define COURSE_H_

#include <iostream>
#include <string>
#include <memory>
#include <map>
#include <set>
#include "student.h"
#include "dbms.h"

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

    void CourseInfo();

    void SetGrade(const std::string& id, const std::string& grade);

    // void RecordStudentInfo(const std::string& name,
    //                        StudentBasicInfo* cbi) {
    //     students_[name] = cbi;
    // }

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
    CourseManage(DBMS* dbms, StudentBasicInfo* sbi) : dbms_(dbms), sbi_(sbi) {
        std::string query = "SELECT * FROM course";
        std::unique_ptr<sql::ResultSet> res(dbms_->ExecuteQuery(query));
        std::string num, teacher, hour, capacity, classroom;
        while (res->next()) {
            num       = res->getString("course_num");
            teacher   = res->getString("course_teacher");
            hour      = res->getString("course_hour");
            capacity  = res->getString("course_capacity");
            classroom = res->getString("course_classroom");

            Course* course = new Course(stoi(num), teacher, stoi(hour),
                                        stoi(capacity), classroom);
            courses_[stoi(num)] = course;
        }
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
                    StudentBasicInfo* sbi);

    void SetCourseTime(int num) {
        std::cout << "请输入调整后的课程时长:";
        int hour;
        std::cin >> hour;
        courses_[num]->SetHour(hour);

        std::string query = "UPDATE course SET course_hour=" + std::to_string(hour) + " WHERE course_num=" + std::to_string(num);
        dbms_->Execute(query);
    }

    void SetCourseCapacity(int num) {
        std::cout << "请输入调整后的课程容量:";
        int capacity;
        std::cin >> capacity;
        courses_[num]->SetCapacity(capacity);

        std::string query = "UPDATE course SET course_capacity=" + std::to_string(capacity) + " WHERE course_num=" + std::to_string(num);
        dbms_->Execute(query);
    }

    void SetGrade(int num, const std::string& id, const std::string& grade);
    void ShowStudentInfo(int num);

// private:
    DBMS*                  dbms_;
    std::map<int, Course*> courses_;
    StudentBasicInfo*      sbi_;
};


#endif  // COURSE_H_
