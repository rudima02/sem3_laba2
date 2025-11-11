#include "lrucache.h"

LRUCache::LRUCache(int cap) {
    capacity = cap;
    size = 0;
    head = nullptr;
    tail = nullptr;
}

LRUCache::~LRUCache() {
    Node* curr = head;
    while (curr) {
        Node* tmp = curr;
        curr = curr->next;
        delete tmp;
    }
}

LRUCache::Node* LRUCache::findNode(int key) const {
    Node* curr = head;
    while (curr) {
        if (curr->key == key) return curr;
        curr = curr->next;
    }
    return nullptr;
}

void LRUCache::moveToHead(Node* node) {
    if (node == head) return;
    removeNode(node);
    addNode(node);
}

void LRUCache::removeNode(Node* node) {
    if (!node) return;
    if (node->prev) node->prev->next = node->next;
    else head = node->next;
    if (node->next) node->next->prev = node->prev;
    else tail = node->prev;
    size--;
}

void LRUCache::addNode(Node* node) {
    node->prev = nullptr;
    node->next = head;
    if (head) head->prev = node;
    head = node;
    if (!tail) tail = head;
    size++;
}

void LRUCache::set(int key, int value) {
    Node* node = findNode(key);
    if (node) {
        node->value = value;
        moveToHead(node);
    } else {
        if (size >= capacity) {
            Node* oldTail = tail;
            removeNode(tail);
            delete oldTail;
        }
        Node* newNode = new Node(key, value);
        addNode(newNode);
    }
}

int LRUCache::get(int key) const {
    Node* node = findNode(key);
    if (!node) return -1;
    const_cast<LRUCache*>(this)->moveToHead(node);
    return node->value;
}

void LRUCache::printCache() const {
    Node* curr = head;
    std::cout << "Кэш: ";
    while (curr) {
        std::cout << "(" << curr->key << ":" << curr->value << ") ";
        curr = curr->next;
    }
    std::cout << "\n";
}
 