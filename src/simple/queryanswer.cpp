#include "simple/queryanswer.h"

SimpleQueryAnswer::SimpleQueryAnswer(const std::string& result): result(result) {}

const std::string& SimpleQueryAnswer::getData() const {
    return result;
}

void SimpleQueryAnswer::print() const {
    std::cout << result << std::endl;
}
