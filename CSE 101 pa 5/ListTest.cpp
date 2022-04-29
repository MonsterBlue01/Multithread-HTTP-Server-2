#include <iostream>

#include "List.h"

using namespace std;

int main() {
    List a;
    a.insertBefore(2);
    a.insertBefore(1);
    a.insertBefore(0);
    cout << a.front() << "\n";
    cout << a.back() << "\n";
    cout << a.length() << "\n";
    cout << "Hello World" << "\n"; //
    return 0;
}