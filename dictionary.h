#pragma once
#include "array.h"
#include <string>

class Dictionary {
private:
    Array dict;

public:
    Dictionary(const Array& d);
    int checkText(const Array& text) const;
};
