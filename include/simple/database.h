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
    SimpleDataBase() = default;
    SimpleDataBase(std::map<std::string, std::string> dictionary): m_dictionary(dictionary) {}
    
    std::shared_ptr<QueryAnswer> search(const std::shared_ptr<Query> query) const override {
        const std::shared_ptr<SimpleQuery> simpleQuery = std::dynamic_pointer_cast<SimpleQuery>(query);
        if (simpleQuery == nullptr) {
            throw std::runtime_error("Error: wrong type of Query");
        }
        std::string word = simpleQuery->get_word();
        if (m_dictionary.find(word) == m_dictionary.end()) {
            return std::make_shared<SimpleQueryAnswer>("Nothing was found!\n");
        }
        std::stringstream ss;
        ss << "The result is:\n";
        ss << m_dictionary.at(word) << "\n";
        return std::make_shared<SimpleQueryAnswer>(ss.str());
    }
};
