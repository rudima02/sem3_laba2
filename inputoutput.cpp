#include "inputoutput.h"
#include <fstream>
#include <iostream>

void saveSetToFile(const Set& s, const std::string& filename) {
    std::ofstream file(filename); 
    if (!file) {
        std::cerr << "Ошибка открытия файла для записи: " << filename << "\n";
        return;
    }

    const int TABLE_SIZE = 1000;
    for (int i = 0; i < TABLE_SIZE; ++i) {
        const HashTable::Node* node = s.getChainHead(i);
        while (node) {
            file << node->key << " ";
            node = node->next;
        }
    }
}


void loadSetFromFile(Set& s, const std::string& filename) {
    std::ifstream file(filename);
    if (!file) { std::cerr << "Ошибка открытия файла\n"; return; }

    int value;
    while (file >> value) s.add(value);
}
