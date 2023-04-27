#pragma once

class Entry {
public:
    virtual ~Entry() = 0;
};

inline Entry::~Entry() {}
