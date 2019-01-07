#include <iostream>
#include <string>
#include <mysql/mysql.h>

class DMBS {
public:
    DMBS(const std::string& host,
         const std::string& user,
         const std::string& password)
        : host_(host), user_(user), password_(password) {
        dp_ptr_ = mysql_init(NULL);
        if (dp_ptr_ == NULL) {
            std::cout << "Mysql init error\n";
            return;
        }

        if (mysql_real_connect(dp_ptr_, host_, user_, password_, NULL, 0, NULL, 0) == NULL) {

        }
    }

private:
    std::string host_;
    std::string user_;
    std::string password_;
    MYSQL*      dp_ptr_;
};
