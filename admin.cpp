#include <iostream>
#include "admin.h"

using namespace std;

void Admin::ManageCourseInfo() {
    cm_->ShowCourseInfo();
    cout << "\t1: set hour\n";
    cout << "\t2: set capacity\n";
    cout << "choice func: ";
    int num;
    cin >> num;

    cout << "Plase class num:";
    int class_num = 0;
    cin >> class_num;
    switch (num) {
    case 1:
        cm_->SetCourseTime(class_num);
        break;
    case 2:
        cm_->SetCourseCapacity(class_num);
        break;
    default:
        break;
    }
}
