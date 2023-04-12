#pragma once
#include <map>
#include <iostream>
#include <memory>
#include <sstream>
#include <vector>

#include "src/queryanswer.h"
#include "src/query.h"
#include "src/database.h"
#include "simple/query.h"
#include "simple/queryanswer.h"

class SimpleDataBase : public DataBase {
    std::map<std::string, std::string> m_dictionary;
    std::vector<std::string> supported_langs;
public:
    SimpleDataBase(std::map<std::string, std::string> dictionary, std::vector<std::string> langs);
    
    std::shared_ptr<QueryAnswer> search(const std::shared_ptr<Query> query) const override; 
    std::vector<std::string> get_langs() const;
    
};

inline std::vector<std::string> SimpleDataBase::get_langs() const {
    return supported_langs;
}
