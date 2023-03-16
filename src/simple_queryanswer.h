#pragma once
#include <iostream>

#include "queryanswer.h"

class SimpleQueryAnswer : public QueryAnswer {
    std::string result;
public:
    SimpleQueryAnswer() = default;
    SimpleQueryAnswer(const std::string& result): result(result) {}
    void print() const override {
        std::cout << result << std::endl;
    }
};
