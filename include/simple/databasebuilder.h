#pragma once

#include <iostream>
#include <map>
#include <memory>
#include <stdexcept>
#include <fstream>

#include "src/databasebuilder.h"
#include "src/database.h"
#include "src/entry.h"
#include "simple/database.h"
#include "simple/entry.h"

class SimpleDataBaseBuilder : public DataBaseBuilder {
    std::map<std::string, std::string> m_dictionary;
    std::vector<std::string> supported_langs;
public:
    void addEntry(std::shared_ptr<Entry> entry) override;
    void addLangs();
    std::shared_ptr<DataBase> getDatabase() override;
};

