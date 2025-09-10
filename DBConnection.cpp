#include <iostream>
#include <gmock/gmock.h>
#include <gtest/gtest.h>
using namespace std;

class DBConnection
{
public:
    DBConnection() {}
    virtual ~DBConnection() {}
    virtual bool open(const string& database) = 0;
    virtual bool execQuery(const string& query) = 0;
    virtual void close() = 0;
};

class ClassThatUsesDB
{
protected:
    DBConnection* dbconnect;
public:
    ClassThatUsesDB(DBConnection* db) : dbconnect(db) {}
    virtual ~ClassThatUsesDB() { }
    bool openConnection(const string& database)
    {
        dbconnect->open(database);
        return true;
    }
    bool useConnection(const string& query)
    {
        dbconnect->execQuery(query);
        return true;
    }
    void closeConnection()
    {
        dbconnect->close();
    }
};

class MockDBConnection : public DBConnection
{
public:
    MOCK_METHOD(bool, open, (const string& database), (override));
    MOCK_METHOD(bool, execQuery, (const string& query), (override));
    MOCK_METHOD(void, close, (), (override));
};

TEST(DBConnectionTest, testcase1)
{
    MockDBConnection mockDBC;
    EXPECT_CALL(mockDBC, open).Times(1).WillOnce(testing::Return(true));
    EXPECT_CALL(mockDBC, execQuery).Times(1).WillOnce(testing::Return(true));
    EXPECT_CALL(mockDBC, close).Times(1);
    mockDBC.open("DataBase");                       // пример базы данных
    mockDBC.execQuery("SELECT * FROM users");       // пример вызовов для теста
    mockDBC.close();
}

int main()
{
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}