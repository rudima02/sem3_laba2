#include "hashtable.h"
#include <iostream>
void runTask6() {
    HashTable ht;
    int choice, key, value;
    std::cout << "Выберите действие:\n";
    std::cout << "1 - Insert Open\n";
    std::cout << "2 - Search Open\n";
    std::cout << "3 - Remove Open\n";
    std::cout << "4 - Insert Chain\n";
    std::cout << "5 - Search Chain\n"; 
    std::cout << "6 - Remove Chain\n";
    std::cout << "7 - Fold Hash\n";
    std::cout << "8 - Print Open\n";
    std::cout << "9 - Print Chain\n";
    std::cout << "0 - Exit\n";
    while (true) {
        std::cin >> choice;

        if (choice == 0) break;

        switch (choice) {
            case 1:
                std::cout << "Введите ключ: "; std::cin >> key;
                std::cout << "Введите значение: "; std::cin >> value;
                ht.insertOpen(key, value);
                std::cout << "Ключ " << key << " -> " << value << " добавлен в Open\n";
                break;
            case 2:
                std::cout << "Введите ключ: "; std::cin >> key;
                if (ht.searchOpen(key, value))
                    std::cout << "Значение: " << value << "\n";
                else
                    std::cout << "-1\n";
                break;
            case 3:
                std::cout << "Введите ключ: "; std::cin >> key;
                ht.removeOpen(key);
                break;
            case 4:
                std::cout << "Введите ключ: "; std::cin >> key;
                std::cout << "Введите значение: "; std::cin >> value;
                ht.insertChain(key, value);
                break;
            case 5:
                std::cout << "Введите ключ: "; std::cin >> key;
                if (ht.searchChain(key, value))
                    std::cout << "Значение: " << value << "\n";
                else
                    std::cout << "-1\n";
                break;
            case 6:
                std::cout << "Введите ключ: "; std::cin >> key;
                ht.removeChain(key);
                break;
            case 7:
                std::cout << "Введите число: "; std::cin >> key;
                std::cout << "Результат: " << ht.foldHash(key) << "\n";
                break;
            case 8:
                ht.printOpen();
                break;
            case 9:
                ht.printChain();
                break;
        }
    }
}
