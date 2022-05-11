#include <iostream>
using namespace std;

#include "Dictionary.h"

int main() {
    Dictionary D;
    D.setValue("Apple", 1);
    string s;
    D.inOrderString(s, D.root);
    cout << "Hello World";
    cout << s << endl;
    return 0;
}