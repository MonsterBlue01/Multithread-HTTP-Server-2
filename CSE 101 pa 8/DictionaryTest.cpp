#include <iostream>
#include "Dictionary.h"

using namespace std;

int main() {
    // abcdefghij k l m n o p q r s t u v w x y z
    // 1234567891011121314151617181920212223242526
    Dictionary D;
    D.setValue("Hill", 1);
    D.setValue("Lemon", 2);
    D.setValue("Demon", 3);
    D.setValue("Bee", 4);
    D.setValue("Font", 5);
    D.setValue("Joker", 6);
    D.setValue("Ninja", 7);
    D.setValue("Apple", 8);
    D.setValue("Cat", 9);
    D.setValue("Egg", 10);
    D.setValue("Ginger", 11);
    D.setValue("Ikon", 12);
    D.setValue("K", 13);
    D.setValue("Mongolia", 14);
    D.setValue("Opera", 15);
    string s;
    s = D.to_string();
    cout << "s: " << s << endl;
    return 0;
}