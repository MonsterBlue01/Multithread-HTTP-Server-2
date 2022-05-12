#include <iostream>
using namespace std;

#include "Dictionary.h"

int main() {
    Dictionary D;
    string s;
    D.setValue("Apple", 1);
    D.setValue("Battery", 2);
    D.setValue("Cat", 3);
    s = D.to_string();
    // cout << s << endl;
    return 0;
}