#include "dbms.h"

using namespace std;


DBMS::DBMS(const std::string& host,
           const std::string& user,
           const std::string& password,
           const std::string& database)
    : host_(host), user_(user), password_(password), database_(database),
      driver_(get_driver_instance()),
      con_(driver_->connect(host_, user_, password_)),
      stmt_(nullptr),
      res_(nullptr) {
    con_->setSchema(database_);
    stmt_ = con_->createStatement();
}

bool DBMS::CheckUserInfo(const std::string& table,
                         const std::string& user,
                         const std::string password) {
    std::string query = "SELECT admin_password FROM " + table +
                        " WHERE admin_id = '" + user + "'";
    stmt_ = con_->createStatement();
    res_ = stmt_->executeQuery(query);
    if (res_->next()) {
        if (res_->getString("admin_password") == password) return true;
    }
    return false;
}
