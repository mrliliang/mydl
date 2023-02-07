#pragma once

#include <string>
#include <mysql.h>


class DBManager {
    public:

        DBManager(string ip, int port, string dbName, string user, string pwd);

        bool connect();
        bool close();
        void exec(string sql);

    private:
        MYSQL mysql;

};
