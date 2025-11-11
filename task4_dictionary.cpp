#include "array.h"
#include "dictionary.h"
#include <iostream>
#include <string>

void runTask4() {
    Array dict;
    int n;
    std::cout << "Введите количество слов в словаре: ";
    std::cin >> n;

    std::string word;
    for (int i = 0; i < n; ++i) {
        std::cin >> word;
        dict.add(word);
    }

    std::cin.ignore();
    std::string line;
    std::cout << "Введите текст для проверки: ";
    std::getline(std::cin, line);

    Array text;
    std::string temp = "";
    for (size_t i = 0; i <= line.size(); ++i) {
        if (i == line.size() || line[i] == ' ') {
            if (!temp.empty()) {
                text.add(temp);
                temp = "";
            }
        } else {
            temp += line[i];
        }
    }

    Dictionary checker(dict);
    int errors = checker.checkText(text);

    std::cout << "Количество ошибок: " << errors << "\n";
}
