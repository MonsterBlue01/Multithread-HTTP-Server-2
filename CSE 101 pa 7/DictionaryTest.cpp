#include <iostream>
using namespace std;

#include "Dictionary.h"

int main() {
    Dictionary D;
    string s;
    D.setValue("Hacks", 8);
    D.setValue("Duck", 4);
    D.setValue("Lucky", 12);
    D.setValue("Bee", 2);
    D.setValue("Ant", 1);
    D.setValue("Cat", 3);
    D.setValue("Funk", 6);
    D.setValue("Elephant", 5);
    D.setValue("Gecko", 7);
    D.setValue("Jack", 10);
    D.setValue("NATO", 14);
    D.setValue("Integer", 9);
    D.setValue("King", 11);
    D.setValue("Map", 13);
    D.setValue("Opinion", 15);
    cout << D << endl;
    // D.begin();
    // D.next();
    // D.next();
    // D.prev();
    // cout << D.currentKey() << endl;
    Dictionary A = D;
    Dictionary E;
    cout << (A == E) << endl;
    return 0;
    // D.remove("Donkey");
    // s = D.to_string();
    // cout << s << endl;
    // s = D.pre_string();
    // cout << s << endl;
    // cout << "Corresponding value: " << D.getValue("Apple") << endl;
    // D.clear();
    // D.setValue("Apple", 1);
    // s = D.to_string();
    // cout << s << endl;
    return 0;
}