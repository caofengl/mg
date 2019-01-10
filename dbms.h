#ifndef DBMS_H_
#define DBMS_H_

#include <iostream>
#include <string>
#include <memory>
#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

class DBMS {
public:
    DBMS(const std::string& host,
         const std::string& user,
         const std::string& password,
         const std::string& database);

    bool CheckUserInfo(const std::string& table,
                       const std::string& user,
                       const std::string& password);

    sql::Statement* GetStatement();

    void Execute(const std::string& query);

    sql::ResultSet* ExecuteQuery(const std::string& query);

private:
    std::string host_;
    std::string user_;
    std::string password_;
    std::string database_;

    sql::Driver*                     driver_;
    std::unique_ptr<sql::Connection> con_;
};

#endif  // DBMS_H_
