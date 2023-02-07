
#include <dbmanager.h>
#include <cppco


DBManager::DBManager(string ip, int port, string dbName, string user, string pwd) {
    mysql_init(&(this->mysql));
}

bool DBManager::connect() {

}

bool DBManager::close() {
    mysql_close(&(this->mysql);
}