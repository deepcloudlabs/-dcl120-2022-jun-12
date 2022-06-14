#include <string>
#include <list>
using namespace std;

class Connection {};

struct ConnectionManager { // interface
    virtual Connection createConnection(string& username,string &password) =0;
};

class MySQLConnectionManager : public ConnectionManager {
public:
    Connection createConnection(string& username,string &password) override {
        return Connection();
    }
};
class RedisConnectionManager : public ConnectionManager {
public:
    Connection createConnection(string& username,string &password) override {
        return Connection();
    }
};
class MongoConnectionManager : public ConnectionManager {
public:
    Connection createConnection(string& username,string &password) override {
        return Connection();
    }
};
list<int> numbers;

struct ConnectionPool { // abstract
    ConnectionManager& connectionManager;
    ConnectionPool(ConnectionManager& connectionManager): connectionManager(connectionManager){}
    virtual Connection& getConnection() = 0;
    virtual void releaseConnection(Connection &connection) = 0;
};
struct ConnectionPoolFactory {
    virtual ConnectionPool createConnectionPool() = 0;
};

class CachedConnectionPool : public ConnectionPool {};
class FixedConnectionPool : public ConnectionPool  {};
class ElasticConnectionPool : public ConnectionPool {};

class A {
    int x; // 4-byte
    bool z; // 1-byte
    // 3-byte
    double y; // 8-byte
}; // 16-byte

A a;
