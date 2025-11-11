#pragma once
#include <iostream>

class LRUCache {
private:
    struct Node {
        int key;
        int value;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
    };

    int capacity;
    int size;
    Node* head;
    Node* tail;

    Node* findNode(int key) const;

    void moveToHead(Node* node);
    void removeNode(Node* node);
    void addNode(Node* node);

public:
    LRUCache(int cap);
    ~LRUCache();

    void set(int key, int value);
    int get(int key) const;
    void printCache() const;
};
 