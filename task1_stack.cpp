#include "logicevaluator.h"
#include <iostream>


void runTask1() {
    std::string expr;

    std::cin.ignore();

    std::cout << "Введите логическое выражение (0, 1, !, &, |, ^): ";
    std::getline(std::cin, expr);

    if (expr.empty()) {
        std::cout << "Выражение пустое\n";
        return;
    }

    try {
        LogicEvaluator evaluator;
        bool result = evaluator.evaluate(expr);
        std::cout << "Результат: " << result << "\n";
    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << "\n";
    }
}
 