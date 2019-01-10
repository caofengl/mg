#include "dbms.h"

using namespace std;

DBMS::DBMS(const std::string& host,
           const std::string& user,
           const std::string& password,
           const std::string& database)
    : host_(host), user_(user), password_(password), database_(database),
      driver_(get_driver_instance()),
      con_(driver_->connect(host_, user_, password_)) {
    con_->setSchema(database_);
}

sql::Statement* DBMS::GetStatement() {
    return con_->createStatement();
}


bool DBMS::CheckUserInfo(const std::string& table,
                         const std::string& user,
                         const std::string& password) {
    std::string query = "SELECT " + table + "_password FROM " + table + " WHERE " + table + "_id =" + user;
    unique_ptr<sql::Statement> stmt(GetStatement());
    unique_ptr<sql::ResultSet> res(stmt->executeQuery(query));

    if (res->next()) {
        if (res->getString(table + "_password") == password) return true;
    }
    return false;
}

void DBMS::Execute(const std::string& query) {
    unique_ptr<sql::Statement> stmt(GetStatement());
    stmt->execute(query);
}

sql::ResultSet* DBMS::ExecuteQuery(const std::string& query) {
    unique_ptr<sql::Statement> stmt(GetStatement());
    return stmt->executeQuery(query);
}

