#pragma once

#include <iostream>
#include <memory>

#include "simple_databasebuilder.h"
#include "simple_database.h"
#include "simple_query.h"
#include "simple_entry.h"

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
            std::cout << "Welcome to the dictionary! Enter any word and see if the dictionary has it.\n\n";
            std::string word;
            std::cin >> word;
            std::shared_ptr<Query> query = std::make_shared<SimpleQuery>(word);
            std::shared_ptr<QueryAnswer> answer = m_database->search(query);
            answer->print();
        }
    }
};
