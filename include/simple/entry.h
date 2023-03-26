#pragma once

#include <iostream>
#include <map>

#include "src/entry.h"

class SimpleEntry : public Entry {
    std::string m_original;
    std::string m_translation;

public:
    SimpleEntry() = default;
    SimpleEntry(std::string original, std::string translation);
    ~SimpleEntry() override = default;

    void updateMap(std::map<std::string, std::string>& dictionary);
};
