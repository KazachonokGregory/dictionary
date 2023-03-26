#pragma once
#include <iostream>

#include "src/query.h"

class SimpleQuery : public Query {
    std::string m_word;
public:
    SimpleQuery() = default;
    SimpleQuery(std::string word);
    ~SimpleQuery() override = default;
    
    std::string get_word() const;
};
