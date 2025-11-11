#include "genome.h"

Genome::Genome(const Set& seq) {
    sequence = seq;
}

Genome::Genome(const std::string& str) {
    for (char c : str) {
        sequence.add(static_cast<int>(c)); 
    }
}

void Genome::setSequence(const Set& seq) {
    sequence = seq;
}

const Set& Genome::getSequence() const {
    return sequence;
}

int Genome::similarity(const Genome& other) const {
    int count = 0;
    const int TABLE_SIZE = 1000;
    for (int i = 0; i < TABLE_SIZE; ++i) {
        const HashTable::Node* node = sequence.getChainHead(i);
        while (node) {
            if (other.getSequence().contains(node->key)) {
                count++;
            }
            node = node->next;
        }
    }
    return count;
}
