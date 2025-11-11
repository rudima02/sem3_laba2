#include "genome.h"
#include <iostream>

void runTask3() {
    std::string seq1, seq2;
    std::cout << "Введите первый геном: ";
    std::cin >> seq1;
    std::cout << "Введите второй геном: ";
    std::cin >> seq2;

    Genome g1(seq1);
    Genome g2(seq2);

    int sim = g1.similarity(g2);
    std::cout << "Степень близости: " << sim << "\n";
}
 