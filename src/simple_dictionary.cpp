#pragma once

#include <iostream>
#include <memory>

#include "simple_databasebuilder.cpp"
#include "simple_database.cpp"
#include "simple_query.cpp"
#include "simple_entry.cpp"

class SimpleDictionary {
    std::shared_ptr<DataBase> m_database;
public:
    SimpleDictionary() {
        SimpleDataBaseBuilder builder;
        builder.addEntry(std::make_shared<SimpleEntry>("cat", "кот"));
        builder.addEntry(std::make_shared<SimpleEntry>("dog", "пёс"));
        m_database = builder.getDatabase();
    }
    void run() {
        while (true) {
            std::string word;
            std::cin >> word;
            std::shared_ptr<Query> query = std::make_shared<SimpleQuery>(word);
            std::shared_ptr<QueryAnswer> answer = m_database->search(query);
            answer->print();
        }
    }
};
