#include <iostream>
#include <string>
#include "set.h"

void runTask1();
void runTask2(int argc, char* argv[]);
void runTask3();
void runTask4();
void runTask5();
void runTask6();
void runTask7();
void hashTests();
int main(int argc, char* argv[]) {
    int choice;
    if (argc >1){
        runTask2(argc, argv);
        return 1;
    }
    while (true) {
        std::cout << "\nМеню\n";
        std::cout << "1 - Логическое выражение\n";
        std::cout << "2 - Множество\n";
        std::cout << "3 - Степень близости генома\n";
        std::cout << "4 - Словарь ударений\n";
        std::cout << "5 - AVL дерево\n";
        std::cout << "6 - Хэш таблицы\n";
        std::cout << "7 - LRU кэш\n";
        std::cout << "8 - Тесты\n";
        std::cout << "0 - Выход\n";
        std::cout << "Введите номер задания: ";
        std::cin >> choice;

        switch (choice) {
            case 1: runTask1(); break;
            case 2: runTask2(argc, argv); break;
            case 3: runTask3(); break;
            case 4: runTask4(); break;
            case 5: runTask5(); break;
            case 6: runTask6(); break;
            case 7: runTask7(); break;
            case 8: hashTests(); break;
            case 0: std::cout << "Выход..\n"; return 0;
            default: std::cout << "Неверный выбор\n"; break;
        }
    }

    return 0;
}
