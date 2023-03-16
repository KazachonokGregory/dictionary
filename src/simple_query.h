#pragma once
#include <iostream>

#include "query.h"

class SimpleQuery : public Query {
    std::string m_word;
public:
    SimpleQuery() = default;
    SimpleQuery(std::string word): m_word(word) {}
    ~SimpleQuery() override = default;
    
    std::string get_word() const {
        return m_word;
    }
};
