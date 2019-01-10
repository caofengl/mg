#include <iostream>
#include <memory>
#include "student.h"
#include "course.h"

using namespace std;

Student::Student(const std::string& user,
                 StudentBasicInfo* sbi,
                 CourseManage* cm,
                 DBMS* dbms)
    : user_(user),
      student_info_(sbi),
      course_manage_(cm),
      dbms_(dbms) {
    // for (int i = 100; i < 108; ++i) {
    //     string cur_id = to_string(i);
    //     student_info_->students[cur_id] = new StudentBasicInfo();
    //     student_info_->students[cur_id]->name = "stu_" + to_string(i);
    //     student_info_->students[to_string(i)]->id = cur_id;
    // }

    string query = "SELECT * FROM student";
    unique_ptr<sql::ResultSet> res(dbms_->ExecuteQuery(query));
    string id, password, name, age, class_num;
    while (res->next()) {
        id        = res->getString("student_id");
        password  = res->getString("student_password");
        name      = res->getString("student_name");
        age       = res->getString("student_age");
        class_num = res->getString("student_classnum");

        student_info_->students[id] =
            new StudentBasicInfo(id, password, name, age, class_num);
    }

    query = "SELECT * FROM subject";
    unique_ptr<sql::ResultSet> res_2(dbms_->ExecuteQuery(query));
    string student_id, course_num, course_grade;
    while (res_2->next()) {
        student_id = res_2->getString("student_id");
        course_num = res_2->getString("course_num");
        course_grade = res_2->getString("course_grade");
        student_info_->students[student_id]->major[stoi(course_num)] =
            stoi(course_grade);
    }
}

Student::~Student() {
    for (auto& student : student_info_->students) {
        delete student.second;
        student.second = NULL;
    }
    student_info_->students.clear();
}

void Student::changePassword() {
    cout << "请输入您的新密码: ";
    string password;
    cin >> password;
    student_info_->students[user_]->password = password;
    string query =
        "UPDATE student SET student_password=" + password + " WHERE student_id=" + user_;
    dbms_->Execute(query);
}

void Student::showCourseInfo() {
    course_manage_->ShowCourseInfo();
}

void Student::choiceCourse() {
    showCourseInfo();
    cout << "请输入您要选择的课程编号: ";
    int num;
    cin >> num;
    if (student_info_->students[user_]->major.find(num) !=
            student_info_->students[user_]->major.end()) {
        cout << "已经选过该课程，请重新选择\n";
        return;
    }

    string query = "SELECT course_num, student_id FROM subject";
    unique_ptr<sql::ResultSet> res(dbms_->ExecuteQuery(query));
    string stu_num, id;
    bool exist = false;
    while (res->next()) {
        stu_num = res->getString("course_num");
        id      = res->getString("student_id");
        if (id == user_ && stu_num == to_string(num)) exist = true;
    }
    if (exist) return;

    query = "INSERT INTO subject(student_id, course_num, course_grade) VALUE(" + user_ + ", " + to_string(num) + ", " + "0)";
    dbms_->Execute(query);

    course_manage_->AddStudent(num, user_, student_info_->students[user_]);
    student_info_->students[user_]->major[num] = 0;
}

void Student::queryGrade() {
    cout << "id: " << user_
         << ", name: " << student_info_->students[user_]->name << endl;
    for (const auto& subject : student_info_->students[user_]->major) {
        cout << "\t课程标号: " << subject.first
             << ", 成绩: " << subject.second << endl;
    }
}

void Student::showIndividualInfo() {
    cout << "学生信息\n";
    cout << "\t 学号: " << user_ << endl;
    cout << "\t 姓名: " << student_info_->students[user_]->name << endl;
    cout << "\t 年龄: " << student_info_->students[user_]->age << endl;
}

void Student::AddStudentInfo() {
    std::string num, name, password, age, classroom;
    std::cout << "请输入学号，密码，name, 年龄，班级:";
    std::cin >> num >> password >> name >> age >> classroom;

    if (student_info_->students.find(num) != student_info_->students.end()) {
        std::cout << "学号已存在，请您重新输入\n";
        return;
    }
    student_info_->students[num] =
        new StudentBasicInfo(num, name, password, age, classroom);

    std::string query =
        "INSERT INTO student(student_id, student_password, student_name, student_age, student_classnum) VALUE(" + num + ", " + password + ", " + "'" + name + "'" + ", " + age + ", " + classroom + ")";
    dbms_->Execute(query);
}

void Student::DeleteStudentInfo() {
    std::string num;
    std::cout << "请输入要删除学生的学号:";
    std::cin >> num;

    if (student_info_->students.find(num) == student_info_->students.end()) {
        std::cout << "没有此学号，您不需要删除\n";
        return;
    }

    std::string query =
        "DELETE FROM student WHERE student_id=" + num;
    dbms_->Execute(query);

    delete student_info_->students[num];
    student_info_->students.erase(num);
}

