#include <iostream>

#include "List.h"

using namespace std;

int main() {
    List A;
    List B;
    A.insertBefore(1);
    A.insertBefore(2);
    A.insertBefore(2);
    A.insertBefore(1);
    A.insertBefore(2);
    A.insertBefore(3);
    A.insertBefore(1);
    A.findPrev(3);
    A.cleanup();
    if (A.position() != 2) {
        cout << 1 << endl;
    }

    B.insertBefore(1);
    B.insertBefore(2);
    B.insertBefore(2);
    B.insertBefore(1);
    B.insertBefore(2);
    B.insertBefore(3);
    B.insertBefore(1);
    B.findPrev(3);
    B.movePrev();
    B.cleanup();
    if (B.position() != 2)
        cout << 2 << endl;
    return 0;
    // A.insertAfter(1);
    // A.insertAfter(2);
    // A.insertAfter(3);
    // A.insertAfter(1);
    // A.insertAfter(2);
    // A.insertAfter(1);
    // cout << A << endl;
    // A.cleanup();
    // if (A.length() != 3)
    //     cout << A.length() << endl;
    //     return 1;
    // return 0;
    // a.insertBefore(2);
    // a.insertBefore(1);
    // a.insertBefore(0);
    // cout << a.front() << "\n";
    // cout << a.back() << "\n";
    // cout << a.length() << "\n";
    // cout << a.position() << "\n";
    // cout << "Hello World" << "\n";
    return 0;
}