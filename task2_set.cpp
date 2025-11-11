#include "set.h"
#include <iostream>
#include <string>
#include "inputoutput.h"
void runTask2(int argc, char* argv[]) {
    Set s;
    loadSetFromFile(s, "set.txt");
    if (argc > 1) {
        for (int i = 1; i < argc; ++i) {
            std::string cmd = argv[i];

            if (cmd == "SETADD" && i + 1 < argc) {
                int value = std::stoi(argv[++i]);
                if (s.add(value))
                    std::cout << "Добавлено " << value << "\n";
                else
                    std::cout << value << " Уже существует\n";
            }
            else if (cmd == "SETDEL" && i + 1 < argc) {
                int value = std::stoi(argv[++i]);
                if (s.remove(value))
                    std::cout << "Удалено " << value << "\n";
                else
                    std::cout << value << " не найдено\n";
            }
            else if (cmd == "SET_AT" && i + 1 < argc) {
                int value = std::stoi(argv[++i]);
                std::cout << (s.contains(value) ? "YES" : "NO") << "\n";
            }
            else if (cmd == "PRINT") {
                s.print();
            }
            else if (cmd == "EXIT") {
                break;
            }
            else {
                std::cerr << "Неизвестная команда: " << cmd << "\n";
            }
            saveSetToFile(s, "set.txt");
        }
    }
    
    
}
