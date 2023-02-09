#include "MysqlConnPool.h"

MysqlConnPool *MysqlConnPool::connPool = 
new MysqlConnPool("tcp://localhost:3306/mydatalog", "admin", "Admin1234567890", 10);

MysqlConnPool::MysqlConnPool(const char * url, const char * user, const char * password, int maxSize) {
    this->url = url;
    this->user = user;
    this->pwd = password;
    this->poolSize = maxSize;
    this->driver = get_driver_instance();
    initConnPool();
}

void MysqlConnPool::initConnPool() {
    for (int i = 0; i < this->poolSize; ++i) {
        connList.push_back(createConnection());
    }
}

shared_ptr<Connection> MysqlConnPool::createConnection() {
    //建立连接
    try {
        Connection *conn = driver->connect(this->url, this->user, this->pwd);
        shared_ptr<Connection> conSpt(conn);
        return conSpt;
    } catch (exception &e) {
        cout << "createConnection error:" << e.what() << endl;
    }
    return nullptr;
}


MysqlConnPool *MysqlConnPool::ins()
{
    return connPool;
}


shared_ptr<Connection> MysqlConnPool::getConn() {
    cout << "pool size:" << connList.size() << endl;
    lock.lock();
    if (connList.size() > 0){
        shared_ptr<Connection> conn = connList.front();
        connList.pop_front();
        if (conn->isClosed())  {
            conn.reset();
            return createConnection();
        } 
        lock.unlock();
        return conn;
    } else {
        lock.unlock();
        return createConnection();
    }
}

void MysqlConnPool::releaseConn(shared_ptr<Connection> conn) {
    if (conn->isClosed()) {
        conn.reset();
        lock.lock();
        connList.push_back(createConnection());
        lock.unlock();
    } else {
        connList.push_back(conn);
    }
}

MysqlConnPool::~MysqlConnPool()
{
    while (connList.size() > 0) {
        shared_ptr<Connection> con = connList.front();
        con.reset();
        connList.pop_front();
    }
    delete connPool;
}
