#ifndef DICTIONARY_KEYVALUE_H
#define DICTIONARY_KEYVALUE_H

template <class K, class V>
class KeyValue {
    K key;
    V value;
public:
    KeyValue();                                                             // Default constructor
    KeyValue(const K, V const);                                             // Parameterized Constructor

    void setKey(const K);
    void setValue(const V);
    K getKey() const;
    V getValue() const;

    KeyValue<K,V>& operator = (KeyValue<K,V> &);                            // Overloading of Assignment Operator
    template <typename A, typename B>
    friend ostream& operator << (ostream&, const KeyValue<A, B>&);          // Output Operator Overloading
};

template <class K, class V>
KeyValue<K, V>::KeyValue() { }

template <class K, class V>
KeyValue<K, V>::KeyValue(const K key, const V value) : key(key), value(value) { }

template <class K, class V>
void KeyValue<K, V>::setKey(const K key) {
    this->key = key;
}

template <class K, class V>
void KeyValue<K, V>::setValue(const V value) {
    this->value = value;
}

template <class K, class V>
K KeyValue<K, V>::getKey() const {
    return key;
}

template <class K, class V>
V KeyValue<K, V>::getValue() const {
    return value;
}

template <class K, class V>
KeyValue<K, V>& KeyValue<K, V>::operator = (KeyValue<K, V>& keyValue) {
    this->key = keyValue.key;
    this->value = keyValue.value;
    return *this;
}

template <class K, class V>
ostream& operator << (ostream& out, const KeyValue<K, V>& keyValue) {
    out << "{" << keyValue.key << ":" << keyValue.value << "}\n";
    return out;
}

#endif //DICTIONARY_KEYVALUE_H