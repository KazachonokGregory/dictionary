#pragma once

#include <memory>

class QueryAnswer {
public:
    virtual void print() const = 0;
    virtual ~QueryAnswer() = default;
};
