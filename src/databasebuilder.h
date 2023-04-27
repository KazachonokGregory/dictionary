#pragma once

#include <memory>

#include "database.h"
#include "entry.h"

class DataBaseBuilder {
public:
    virtual void addEntry(std::shared_ptr<Entry> entry) = 0;
    virtual std::shared_ptr<DataBase> getDatabase() = 0;
    virtual ~DataBaseBuilder() = default;
};
