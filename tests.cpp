#include <iostream>
#include <vector>
#include <random>
#include <omp.h>
#include "hashtable.h"


void hashTests() {
    std::cout << "Введите количество элементов N и количество запросов M" << std::endl;
    int N,M;  
    std::cout << "N: " << std::endl;
    std::cin >> N;
    std::cout << "M: " << std::endl;
    std::cin >> M;
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> dist(1, 1000000);

    std::vector<int> keys;
    keys.reserve(N);
    for (int i = 0; i < N; ++i)
        keys.push_back(dist(rng));

    std::vector<int> queries;
    queries.reserve(M);
    for (int i = 0; i < M; ++i)
        queries.push_back(keys[i % N]);

    HashTable openTable;
    for (int key : keys)
        openTable.insertOpen(key);

    double startOpen = omp_get_wtime();
    int foundOpen = 0;
    for (int q : queries)
        if (openTable.searchOpen(q))
            ++foundOpen;
    double endOpen = omp_get_wtime();

    double timeOpen = (endOpen - startOpen) * 1000.0; 

    HashTable chainTable;
    for (int key : keys)
        chainTable.insertChain(key);

    double startChain = omp_get_wtime();
    int foundChain = 0;
    for (int q : queries)
        if (chainTable.searchChain(q))
            ++foundChain;
    double endChain = omp_get_wtime();

    double timeChain = (endChain - startChain) * 1000.0; 

    std::cout << "Количество элементов (N): " << N << "\n";
    std::cout << "Количество поисков   (M): " << M << "\n";
    std::cout << "Метод открытой адресации : " << timeOpen  << " мс\n";
    std::cout << "Метод цепочек: " << timeChain << " мс\n";
}
