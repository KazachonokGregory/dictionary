#pragma once

#include "queryanswer.h"
#include "query.h"
#include <memory>

class DataBase {
public:
    virtual std::shared_ptr<QueryAnswer> search(const std::shared_ptr<Query> query) const = 0;
    virtual ~DataBase() = default;
};
