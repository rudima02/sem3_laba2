#pragma once
#include <string>
#include "set.h"

void saveSetToFile(const Set& s, const std::string& filename);
void loadSetFromFile(Set& s, const std::string& filename);
