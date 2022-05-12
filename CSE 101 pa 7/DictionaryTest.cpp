#include <iostream>
using namespace std;

#include "Dictionary.h"

int main() {
    Dictionary D;
    string s;
    D.setValue("Donkey", 1);
    D.setValue("Bee", 2);
    D.setValue("Font", 3);
    D.setValue("Apple", 4);
    D.setValue("Cat", 5);
    D.setValue("Elon", 6);
    D.setValue("Glad", 7);
    D.remove("Donkey");
    s = D.to_string();
    cout << s << endl;
    s = D.pre_string();
    cout << s << endl;
    // D.clear();
    // D.setValue("Apple", 1);
    // s = D.to_string();
    // cout << s << endl;
    return 0;
}