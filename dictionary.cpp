#include "dictionary.h"

Dictionary::Dictionary(const Array& d) {
    for (int i = 0; i < d.length(); ++i) {
        dict.add(d.get(i));
    }
}

int Dictionary::checkText(const Array& text) const {
    int errors = 0;

    for (int i = 0; i < text.length(); ++i) {
        std::string w = text.get(i);

        int accents = 0;
        for (size_t k = 0; k < w.size(); ++k)
            if (w[k] >= 'A' && w[k] <= 'Z') accents++;

        bool inDict = false;
        for (int j = 0; j < dict.length(); ++j) {
            if (dict.get(j) == w) {
                inDict = true;
                break;
            }
        }

        if (inDict) {
            bool match = false;
            for (int j = 0; j < dict.length(); ++j) {
                std::string dw = dict.get(j);
                if (dw.size() != w.size()) continue;

                bool same = true;
                for (size_t k = 0; k < dw.size(); ++k) {
                    bool isUpperText = w[k] >= 'A' && w[k] <= 'Z';
                    bool isUpperDict = dw[k] >= 'A' && dw[k] <= 'Z';
                    if (isUpperText != isUpperDict) {
                        same = false;
                        break;
                    }
                }
                if (same) {
                    match = true;
                    break;
                }
            }
            if (!match) errors++;
        } else {
            if (accents != 1) errors++;
        }
    }

    return errors;
}
