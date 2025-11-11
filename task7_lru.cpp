#include "lrucache.h"
#include <iostream>
#include <string>

void runTask7() {
    int cap, Q;
    std::cout << "Введите ёмкость кеша: ";
    std::cin >> cap;
    std::cout << "Введите количество запросов: ";
    std::cin >> Q;
    std::cout << "Введите команду (SET x y, GET x):\n";

    LRUCache cache(cap);
    std::string cmd;
    int x, y;

    for (int i = 0; i < Q; ++i) {
        std::cin >> cmd;
        if (cmd == "SET") {
            std::cin >> x >> y;
            cache.set(x, y);
        } else if (cmd == "GET") {
            std::cin >> x;
            int val = cache.get(x);
            std::cout << val << "\n";
        } 
    }
}
 