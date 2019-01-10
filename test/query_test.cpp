#include "../dbms.h"
using namespace std;

int main() {

    try {
        DBMS dbms("tcp://127.0.0.1", "cf", "qq", "stduent_manage");
        string query =
            "UPDATE student SET student_password=100 WHERE student_id=100";
        dbms.Execute(query);
        dbms.Execute(query);
    }
    catch (sql::SQLException& e) {
        cout << "# ERR: SQLException in " << __FILE__;
        cout << " (MYSQL error code: " << e.getErrorCode() << "on line " << __LINE__ << endl;
        cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }

    return 0;
}
