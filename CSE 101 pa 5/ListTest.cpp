#include <iostream>

#include "List.h"

using namespace std;

int main() {
    List a;
    a.insertAfter(2);
    a.insertAfter(1);
    a.insertAfter(0);
    cout << a.front() << "\n";
    cout << a.back() << "\n";
    cout << "Hello World" << "\n"; //
    return 0;
}