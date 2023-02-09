#pragma once

#include <string>
#include <list>
#include <thread>
#include <mutex>
// #include <cppconn/driver.h>
// #include <cppconn/exception.h>
// #include <cppconn/resultset.h>
// #include <cppconn/statement.h>
// #include <cppconn/sqlstring.h>
#include <mysql/jdbc.h>

using namespace std;
using namespace sql;

class MysqlConnPool {
    public:
        ~MysqlConnPool();
        shared_ptr<Connection> getConn();
        void releaseConn(shared_ptr<Connection> conn);
        static MysqlConnPool *ins();

    private:
        shared_ptr<Connection> createConnection(); //创建一个连接
        void initConnPool();
        MysqlConnPool(const char *url, const  char *user, const char *password, int maxSize); //构造方法
        list<shared_ptr<Connection>> connList;
        mutex lock; //线程锁
        static MysqlConnPool *connPool;
        Driver *driver;
        SQLString url;
        SQLString user;
        SQLString pwd;
        int poolSize;
};