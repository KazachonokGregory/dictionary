#include "simple/queryanswer.h"

SimpleQueryAnswer::SimpleQueryAnswer(const std::string& result): result(result) {}

void SimpleQueryAnswer::print() const {
    std::cout << result << std::endl;
}
