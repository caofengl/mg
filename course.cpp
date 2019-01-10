#include "course.h"

using namespace std;

void Course::CourseInfo() {
    cout << "这是: " << num_ << " 号课程\n";
}

void CourseManage::ShowStudentInfo(int num) {
    cout << "姓名:\n";
    for (auto& student : sbi_->students) {
        if (student.second->major.find(num) ==
                student.second->major.end()) {
            continue;
        }
        cout << "\t" << student.second->id << " : "
             << student.second->name << endl;
    }
}

void Course::SetGrade(const string& id, const string& grade) {
    students_[id]->major[num_] = stoi(grade);
}

void CourseManage::SetGrade(int num,
                            const std::string& id,
                            const std::string& grade) {
    // courses_[num]->students_[id]->major[num] = std::stoi(grade);
    sbi_->students[id]->major[num] = std::stoi(grade);
}


void CourseManage::AddStudent(int num,
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
    std::string query =
        "UPDATE course SET course_capacity=" + std::to_string(courses_[num]->capacity_) + " WHERE course_num=" + std::to_string(num);
    dbms_->Execute(query);
    sbi->major[num] = 0;
    sbi_->students[id]->major[num] = 0;
}
