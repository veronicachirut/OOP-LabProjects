#ifndef DICTIONARY_DICTIONARY_H
#define DICTIONARY_DICTIONARY_H

#include "KeyComp.h"
#include "KeyValue.h"

template <class K, class V, class F = KeyComp<K>>
class Dictionary {
    KeyValue<K, V>* dict;
    unsigned int size;
    KeyComp<K> comp;

public:
    Dictionary();                                                           // Default constructor
    Dictionary(const Dictionary<K, V, F>&);                                 // Copy constructor

    unsigned int getSize() const;
    void addPair(const K, const V);                                         // Adding a new key-value pair
    void deletePair(const K);                                               // Deleting a key-value pair
    bool containsKey(const K) const;                                        // Searching a pair knowing the key
    KeyValue<K, V> searchByKey(const K) const;
    void deleteAll();                                                       // Deleting all elements

    Dictionary<K, V, F>& operator = (const Dictionary<K, V, F>&);           // Overloading of Assignment Operator
    V operator [] (const K) const;                                          // [] Operator Overloading
    template <typename A, typename B, typename C>
    friend ostream& operator << (ostream&, const Dictionary<A, B, C>&);     // Output Operator Overloading

    virtual ~Dictionary();                                                  // Destructor
};

// Default constructor, initializes an empty dictionary
template <class K, class V, class F>
Dictionary<K, V, F>::Dictionary() : dict(NULL), size(0) { }

// Copy constructor
template <class K, class V, class F>
Dictionary<K, V, F>::Dictionary(const Dictionary<K, V, F>& dictionary) {
    if (dictionary.dict == NULL) {
        this->dict = NULL;
        return;
    }
    this->size = dictionary.size;
    this->dict = new KeyValue<K, V>[this->size];
    copy(dictionary.dict, dictionary.dict + dictionary.size, this->dict);
}

// Returns the size of the dictionary
template<class K, class V, class F>
unsigned int Dictionary<K, V, F>::getSize() const {
    return size;
}

// Comparing two keys
template <typename U>
bool equals(const U key1, const U key2) {
    return key1 == key2;
}

// The template equals function for chars
template <>
bool equals <char*> (char* const key1, char* const key2) {
    return strcmp(key1, key2) == 0;
}

// Adding a new key-value pair
// if a key that already exists in the dictionary is added, the old value will be overwritten
template <class K, class V, class F>
void Dictionary<K, V, F>::addPair(const K key, const V value) {
    for (unsigned int i = 0; i < size; i++) {
        if (equals(dict[i].getKey(), key)) {
            dict[i].setValue(value);
            return;
        }
    }

    KeyValue<K, V>* aux = new KeyValue<K, V>[size + 1];
    copy(dict, dict + size, aux);
    aux[size] = KeyValue<K, V>(key, value);
    delete[] dict;
    size++;
    dict = aux;
}

// Deleting a key-value pair using the key
template <class K, class V, class F>
void Dictionary<K, V, F>::deletePair(const K key) {
    int position = -1;
    for (unsigned int i = 0; i < size; i++) {
        if (equals(dict[i].getKey(), key)) {
            position = i;
            break;
        }
    }

    if (position != -1) {
        KeyValue<K, V> *aux = new KeyValue<K, V>[size - 1];
        copy(dict, dict + position, aux);
        copy(dict + position + 1, dict + size, aux + position);
        delete[] dict;
        dict = aux;
        size--;
    } else {
        throw domain_error("Non-existent key");
    }
}

// Checks if the given key is in the dictionary
template <class K, class V, class F>
bool Dictionary<K, V, F>::containsKey (const K key) const {
    for (unsigned int i = 0; i < size; i++) {
        if (equals(dict[i].getKey(), key)) {
            return true;
        }
    }
    return false;
}

// Returns the key-value pair that contains the given key
template <class K, class V, class F>
KeyValue<K, V> Dictionary<K, V, F>::searchByKey(const K key) const {
    for (unsigned int i = 0; i < size; i++) {
        if (equals(dict[i].getKey(), key)) {
            return dict[i];
        }
    }
    KeyValue<K, V> keyValue;
    return keyValue;
}

// Deletes all elements
template <class K, class V, class F>
void Dictionary<K, V, F>::deleteAll() {
    if (this->size == 0) {
        throw out_of_range("Empty");
    }
    for (unsigned int i = 0; i < size; i++) {
        deletePair(dict[i].getKey());
    }
}

// Overloading of Assignment Operator
template <class K, class V, class F>
Dictionary<K, V, F>& Dictionary<K, V, F>::operator = (const Dictionary<K, V, F>& dictionary) {
    delete[] this->dict;
    this->size = dictionary.size;
    this->dict = new KeyValue<K, V>[dictionary.size];
    copy(dictionary.dict, dictionary.dict + dictionary.size, this->dict);
    return *this;
}

// [] Operator Overloading
template <class K, class V, class F>
V Dictionary<K, V, F>::operator [] (const K key) const {
    for (unsigned int i = 0; i < size; i++) {
        if (equals(dict[i].getKey(), key)) {
            return dict[i].getValue();
        }
    }
    throw domain_error("Non-existent key");
}

// << Operator Overloading
template <class K, class V, class F>
ostream& operator << (ostream& out, const Dictionary<K, V, F>& dictionary) {
    out << "{ ";
    for (unsigned int i = 0; i < dictionary.size; i++) {
        out << dictionary.dict[i].getKey() << " : " << dictionary.dict[i].getValue();
        if (i != dictionary.size - 1) {
            out << ", ";
        }
    }
    out << " }\n";
    return out;
}

// Destructor
template<class K, class V, class F>
Dictionary<K, V, F>::~Dictionary() {
    delete [] dict;
    size = 0;
}

#endif //DICTIONARY_DICTIONARY_H