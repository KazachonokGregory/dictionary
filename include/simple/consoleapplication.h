#pragma once

#include <iostream>
#include <memory>

#include "simple/databasebuilder.h"
#include "simple/database.h"
#include "simple/query.h"
#include "simple/entry.h"

class SimpleConsoleApplication {
    std::shared_ptr<DataBase> m_database;
public:
    SimpleConsoleApplication();
    void run(); 
};
