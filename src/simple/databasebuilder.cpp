#include "simple/databasebuilder.h"

void SimpleDataBaseBuilder::addEntry(std::shared_ptr<Entry> entry) {
    std::shared_ptr<SimpleEntry> simpleEntry = std::dynamic_pointer_cast<SimpleEntry>(entry);
    if (simpleEntry == nullptr) {
        throw std::runtime_error("Error: wrong type of Entry");
    }
    simpleEntry->updateMap(m_dictionary);
}

std::shared_ptr<DataBase> SimpleDataBaseBuilder::getDatabase() {
    return std::make_shared<SimpleDataBase>(m_dictionary);
}

