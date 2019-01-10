#include <iostream>
#include "student.h"
#include "course.h"
#include "admin.h"
#include "dbms.h"

using namespace std;

void StudentCase(Student* s, DBMS* dbms) {
    system("clear");
    cout << "请输入和账号(100到107)和密码(默认为1): ";
    string id, password;
    cin >> id >> password;
    while (!dbms->CheckUserInfo("student", id, password)) {
        cout << "错误，请输入账号和密码:";
        cin >> id >> password;
    }

    s->setUser(id);

    auto Promote = []() {
        system("clear");
        cout << "******************   学生管理界面 ************************\n";
        cout << "\t1 修改密码，基本信息\n";
        cout << "\t2 课程信息\n";
        cout << "\t3 选课\n";
        cout << "\t4 查询成绩\n";
        cout << "\t5 个人信息\n";
        cout << "******************   学生管理界面 ************************\n";
    };

    int num;
    do {
        Promote();
        cout << "请输入您需要的功能(0 表示退出): ";
        cin >> num;

        switch (num) {
        case 1:
            s->changePassword();
            break;
        case 2:
            s->showCourseInfo();
            break;
        case 3:
            s->choiceCourse();
            break;
        case 4:
            s->queryGrade();
            break;
        case 5:
            s->showIndividualInfo();
            break;
        default:
            break;
        }

        string line;
        getline(cin, line);
        cout << "输入回车键继续:";
        getline(cin, line);
    } while (num != 0);
}

void AdminCase(StudentBasicInfo* sbi, Student* s, CourseManage* cm, DBMS* dbms) {
    system("clear");
    cout << "请输入和账号(100到150)和密码(默认为1): ";
    string id, password;
    cin >> id >> password;

    while (!dbms->CheckUserInfo("admin", id, password)) {
        cout << "错误，请输入账号和密码:";
        cin >> id >> password;
    }

    Admin admin(sbi, s, cm, dbms);

    auto Promote = []() {
        system("clear");
        cout << "*******************  管理员界面  *************************\n";
        cout << "\t1 班级管理\n";
        cout << "\t2 课程管理\n";
        cout << "\t3 学生选课\n";
        cout << "\t4 成绩管理\n";
        cout << "\t5 学生管理\n";
        cout << "*******************  管理员界面  *************************\n";
    };

    int num;
    do {
        Promote();
        cout << "请输入您需要的功能(0 表示退出): ";
        cin >> num;

        switch (num) {
        case 1:
            admin.ManageClass();
            break;
        case 2:
            admin.ManageCourseInfo();
            break;
        case 3:
            admin.ManageSubjectCourse();
            break;
        case 4:
            admin.ManageScore();
            break;
        case 5:
            admin.ManageStudent();
            break;
        default:
            break;
        }

        string line;
        getline(cin, line);
        cout << "输入回车键继续:";
        getline(cin, line);
    } while (num != 0);
}

int main() {

    StudentBasicInfo sbi;
    DBMS dbms("tcp://127.0.0.1:3306", "cf", "qq", "stduent_manage");
    CourseManage cm(&dbms, &sbi);
    string stu_name = "101";
    Student student(stu_name, &sbi, &cm, &dbms);

    int num;
    do {
        system("clear");
        cout << "*******************  学生管理系统 ************************\n";
        cout << "欢迎使用" << endl;
        cout << "\t1: 学生登录" << endl;
        cout << "\t2: 管理员登录" << endl;
        cout << "*******************  学生管理系统 ************************\n";
        cout << "请输入您的选择(0表示退出)";
        cin >> num;

        switch (num) {
        case 1:
            StudentCase(&student, &dbms);
            break;
        case 2:
            AdminCase(&sbi, &student, &cm, &dbms);
            break;
        default:
            break;
        }
    } while (num != 0);

    return 0;
}
