#include <iostream>
using namespace std;

#include "Dictionary.h"

int main() {
    Dictionary D;
    string s;
    D.setValue("Apple", 1);
    s = D.to_string();
    cout << s << endl;
    s = D.pre_string();
    cout << s << endl;
    return 0;
}