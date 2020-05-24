#ifndef DICTIONARY_KEYCOMP_H
#define DICTIONARY_KEYCOMP_H

#include <string>
#include <algorithm>
using namespace std;

template <typename K>
class KeyComp {
public:
    bool operator () (const K& key1, const K& key2) const {
        return key1 < key2;
    }
};

// class KeyComp for strings
template <>
class KeyComp<string> {
public:
    bool operator () (const string& key1, const string& key2) const {
        int minim = min(key1.length(), key2.length());
        if (!(minim % 2)) {
            minim /= 2;
        } else {
            minim /= 2;
            minim += 1;
        }
        return key1.substr(0, minim) > key2.substr(0, minim);
    }
};

#endif //DICTIONARY_KEYCOMP_H