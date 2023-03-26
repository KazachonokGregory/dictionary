#include "simple/query.h"

SimpleQuery::SimpleQuery(std::string word): m_word(word) {}

std::string SimpleQuery::get_word() const {
    return m_word;
}
