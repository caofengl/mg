#include <iostream>
#include "student.h"
#include "course.h"
#include "admin.h"

using namespace std;

void StudentCase(Student* s) {
    cout << "请输入和账号(100到150)和密码(默认为1): ";
    string id, password;
    cin >> id >> password;
    s->setUser(id);

    cout << "\t1 修改密码，基本信息\n";
    cout << "\t2 课程信息\n";
    cout << "\t3 选课\n";
    cout << "\t4 查询成绩\n";
    cout << "\t5 个人信息\n";

    int num;
    do {
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
    } while (num != 0);
}

void AdminCase(StudentBasicInfo* sbi, CourseManage* cm) {
    cout << "请输入和账号(100到150)和密码(默认为1): ";
    string id, password;
    cin >> id >> password;

    Admin admin(sbi, cm);

    cout << "\t1 班级管理\n";
    cout << "\t2 课程管理\n";
    cout << "\t3 学生选课\n";
    cout << "\t4 成绩管理\n";
    cout << "\t5 学生管理\n";

    int num;
    do {
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
    } while (num != 0);
}

int main() {

    StudentBasicInfo sbi;
    CourseManage cm;
    string stu_name = "101";
    Student student(stu_name, &sbi, &cm);

    int num;
    do {
        cout << "欢迎使用(0 表示退出)" << endl;
        cout << "\t1: 学生登录" << endl;
        cout << "\t2: 管理员登录" << endl;
        cin >> num;

        switch (num) {
        case 1:
            StudentCase(&student);
            break;
        case 2:
            AdminCase(&sbi, &cm);
            break;
        default:
            break;
        }
    } while (num != 0);

    return 0;
}
