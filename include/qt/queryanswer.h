#pragma once
#include <iostream>

#include "src/queryanswer.h"

class SimpleQueryAnswer : public QueryAnswer {
    std::string result;
public:
    SimpleQueryAnswer() = default;
    SimpleQueryAnswer(const std::string& result);
    void print() const override;
};
