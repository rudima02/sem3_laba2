#pragma once
#include <string>
#include "stack.h"

class LogicEvaluator {
private:
    static int precedence(char op);
    static int applyOp(char op, int a, int b = 0);

public:
    bool evaluate(const std::string& expr);
}; 