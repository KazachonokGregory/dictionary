#pragma once
#include <map>
#include <iostream>
#include <memory>
#include <sstream>

#include "src/queryanswer.h"
#include "src/query.h"
#include "src/database.h"
#include "simple/query.h"
#include "simple/queryanswer.h"

class SimpleDataBase : public DataBase {
    std::map<std::string, std::string> m_dictionary;
public:
    SimpleDataBase(std::map<std::string, std::string> dictionary);
    
    std::shared_ptr<QueryAnswer> search(const std::shared_ptr<Query> query) const override; 
};
