#include "simple/database.h"

SimpleDataBase::SimpleDataBase(std::map<std::string, std::string> dictionary, std::vector<std::string> langs): m_dictionary(dictionary), supported_langs(langs) {}

std::shared_ptr<QueryAnswer> SimpleDataBase::search(const std::shared_ptr<Query> query) const {
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

