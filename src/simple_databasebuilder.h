#pragma once

#include <iostream>
#include <map>
#include <memory>
#include <stdexcept>

#include "databasebuilder.h"
#include "database.h"
#include "simple_database.h"
#include "entry.h"
#include "simple_entry.h"

class SimpleDataBaseBuilder : public DataBaseBuilder {
    std::map<std::string, std::string> m_dictionary;
public:
    void addEntry(std::shared_ptr<Entry> entry) override {
        std::shared_ptr<SimpleEntry> simpleEntry = std::dynamic_pointer_cast<SimpleEntry>(entry);
        if (simpleEntry == nullptr) {
            throw std::runtime_error("Error: wrong type of Entry");
        }
        simpleEntry->updateMap(m_dictionary);
    }
    std::shared_ptr<DataBase> getDatabase() override {
        return std::make_shared<SimpleDataBase>(m_dictionary);
    }
};

