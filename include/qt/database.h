#pragma once
#include <map>
#include <iostream>
#include <memory>
#include <sstream>
#include <vector>

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QFile>
#include <QDate>
#include <QDebug>

#include "src/queryanswer.h"
#include "src/query.h"
#include "src/database.h"
#include "simple/query.h"
#include "simple/queryanswer.h"

class QtDataBase : public DataBase {
private:
    QSqlDatabase db;
    std::vector<std::string> supported_langs;
public:
    explicit QtDataBase(QSqlDatabase db, std::vector<std::string> supported_langs);
    ~QtDataBase();
    
    std::shared_ptr<QueryAnswer> search(const std::shared_ptr<Query> query) const override; 
    std::vector<std::string> get_langs() const;
    
};

inline std::vector<std::string> QtDataBase::get_langs() const {
    for (auto it : supported_langs) {
        qDebug() << QString::fromStdString(it) << "\n";
    }
    return supported_langs;
}
