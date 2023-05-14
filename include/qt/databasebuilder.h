#pragma once

#include <iostream>
#include <map>
#include <memory>
#include <stdexcept>
#include <fstream>

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QFile>
#include <QDate>
#include <QDebug>
#include <QDir>

#include "src/databasebuilder.h"
#include "src/database.h"
#include "src/entry.h"
#include "qt/database.h"
#include "simple/entry.h"

class QtDataBaseBuilder : public DataBaseBuilder {
private:
    QSqlDatabase db;
public:
    QtDataBaseBuilder();
    ~QtDataBaseBuilder() override;
    bool addEntry(std::string, std::string);
    void connectToDataBase();
    void addEntry(std::shared_ptr<Entry> entry) override;
    std::shared_ptr<DataBase> getDatabase() override;
private:
    bool openDataBase();
    bool restoreDataBase();
    void closeDataBase();
    bool createTable();
    bool parseEngRus();
};

inline void QtDataBaseBuilder::addEntry(std::shared_ptr<Entry>) {}
