#include <iostream>
#include <cassert>
#include "Dictionary.h"

/* Code Standards
    - camelCase
    - each variable starts with a letter
    - each class starts with a capital letter
    - "{}" even where there is a single line of code
    - spaces between operators, after semicolon, after comma, etc.
*/

bool test () {
    Dictionary<int, string, KeyComp<int>> chart, dictionary;
    chart.addPair(1, "Brisbane");
    chart.addPair(2, "Venice");
    chart.addPair(3, "Prague");
    chart.addPair(3, "London");
    chart.addPair(4, "Edinburgh");
    dictionary = chart;

    assert(chart.getSize() == 4);
    assert(chart[1] == "Brisbane");
    assert(chart.containsKey(5) == 0);
    assert(dictionary.getSize() == chart.getSize());

    Dictionary<string, string, KeyComp<string>> animals;
    animals.addPair("Kangaroo", "Marsupial");
    animals.addPair("Oncilla", "Felidae");
    animals.addPair("Blue whale", "Cetacee");

    assert(animals.searchByKey("Blue whale").getValue() == "Cetacee");
    assert(!animals.containsKey("Squirrel"));

    Dictionary<int, int, KeyComp<int>> numbers;
    numbers.addPair(50, 50);
    numbers.addPair(25, 75);
    Dictionary<int, int> copyNumbers(numbers);

    assert(numbers.getSize() == copyNumbers.getSize());
    assert(numbers.getSize() == 2);
    numbers.deletePair(25);
    assert(numbers.getSize() == 1);
    numbers.deleteAll();
    assert(numbers.getSize() == 0);

    return true;
}

int main() {
    bool working = test();
    if (working) {
        cout << "It's working!";
    }
    return 0;
}