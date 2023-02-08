#pragma once

#include <string>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/sqlstring.h>

using namespace std;
using namespace sql;


class DBManager {
    public:
        DBManager* getInstance();
        Connection* getConnection();

    private:
        DBManager(string url, int port, string dbName, string user, string pwd);
        static DBManager *manager = nullptr;
        Driver *driver = nullptr;
        string url;
        string port;
        string dbName;
        string user;
        string pwd;
};
