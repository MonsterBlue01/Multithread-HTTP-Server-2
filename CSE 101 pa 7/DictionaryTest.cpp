#include <iostream>
using namespace std;

#include "Dictionary.h"

int main() {
    Dictionary D;
    D.setValue("Apple", 1);
    cout << "The num: " << D.size() << endl;
    cout << "Hello World";
    return 0;
}