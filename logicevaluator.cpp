#include "logicevaluator.h"

int LogicEvaluator::precedence(char op) {
    if (op == '!') return 3;
    if (op == '&') return 2;
    if (op == '|' || op == '^') return 1;
    return 0;
}

int LogicEvaluator::applyOp(char op, int a, int b) {
    switch (op) {
        case '!': return !a;
        case '&': return a && b;
        case '|': return a || b;
        case '^': return a ^ b;
    }
    return 0;
}

bool LogicEvaluator::evaluate(const std::string& expr) {
    Stack values(1000);
    Stack ops(1000);

    for (size_t i = 0; i < expr.size(); ++i) {
        char c = expr[i];
        if (c == ' ') continue;

        if (c == '0' || c == '1') {
            values.push(c - '0');
        } else if (c == '(') {
            ops.push(c);
        } else if (c == ')') {
            while (!ops.isEmpty() && ops.peek() != '(') {
                char op = ops.pop();
                if (op == '!') {
                    int a = values.pop();
                    values.push(applyOp(op, a));
                } else {
                    int b = values.pop();
                    int a = values.pop();
                    values.push(applyOp(op, a, b));
                }
            }
            if (!ops.isEmpty()) ops.pop();
        } else { 
            while (!ops.isEmpty() && precedence(ops.peek()) >= precedence(c)) {
                char op = ops.pop();
                if (op == '!') {
                    int a = values.pop();
                    values.push(applyOp(op, a));
                } else {
                    int b = values.pop();
                    int a = values.pop();
                    values.push(applyOp(op, a, b));
                }
            }
            ops.push(c);
        }
    }

    while (!ops.isEmpty()) {
        char op = ops.pop();
        if (op == '!') {
            int a = values.pop();
            values.push(applyOp(op, a));
        } else {
            int b = values.pop();
            int a = values.pop();
            values.push(applyOp(op, a, b));
        }
    }

    return values.pop();
}
 