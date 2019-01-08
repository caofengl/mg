#include <iostream>
#include "../dbms.h"

using namespace std;

int main() {

    DBMS dbms("tcp://127.0.0.1:3306", "cf", "qq", "stduent_manage");
    if (dbms.CheckUserInfo("admin", "100", "qq")) {
        cout << "login success\n";
    }
    else {
        cout << "login failed\n";
    }

    return 0;
}
