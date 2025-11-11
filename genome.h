#pragma once
#include "set.h"
#include <string>

class Genome {
private:
    Set sequence;

public:
    Genome() = default;
    Genome(const Set& seq);
    Genome(const std::string& str);

    void setSequence(const Set& seq);
    const Set& getSequence() const;

    int similarity(const Genome& other) const; 
};
