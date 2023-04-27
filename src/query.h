#pragma once

class Query {
public:
    virtual ~Query() = 0;
};

inline Query::~Query() {}
