#include <iostream>
using namespace std;

#include "Dictionary.h"

int main() {
    Dictionary A;
    string ideal = "a : 1\nb : 5\ne : 10\nf : 20\nh : 15\ni : 100\n";
    A.setValue("a", 1);
    A.setValue("b", 5);
    A.setValue("e", 10);
    A.setValue("h", 15);
    A.setValue("f", 20);
    A.setValue("i", 100);
    string val = A.to_string();
    cout << val << endl;
    cout << ideal << endl;
    if (val != ideal)
        cout << 1 << endl;
    return 0;
    // Dictionary A;
    // A.setValue("d", 2);
    // A.setValue("d", 5);

    // if (A.size() != 1)
    //     cout << 1 << endl;

    // if (A.getValue("d") != 5)
    //     cout << 2 << endl;

    // A.setValue("d", 1);

    // if (A.getValue("d") != 1)
    //     cout << 3 << endl;

    // A.remove("d");

    // if (A.size() != 0)
    //     cout << 4 << endl;

    // return 0;
    // Dictionary A;
    // A.setValue("d", 1);
    // A.setValue("b", 5);
    // A.setValue("a", 10);
    // A.setValue("c", 15);
    // A.setValue("f", 20);
    // A.setValue("e", 25);
    // A.setValue("g", 30);
    // A.begin();
    // A.remove("a");
    // if (A.hasCurrent())
    //     cout << 1 << endl;
    // A.end();
    // A.remove("d");
    // if (A.currentKey() != "g" || A.currentVal() != 30)
    //     cout << 2 << endl;
    // A.remove("g");
    // if (A.hasCurrent())
    //     cout << 3 << endl;
    // return 0;
    // Dictionary A;
    // A.setValue("a", 1);
    // A.setValue("b", 5);
    // A.setValue("e", 10);
    // A.end();
    // A.setValue("h", 15);
    // A.setValue("f", 20);
    // A.setValue("i", 100);
    // if (A.currentKey() != "e" || A.currentVal() != 10)
    //     cout << 1 << endl;
    // A.end();
    // cout << A.currentKey() << endl;
    // A.prev();
    // cout << A.currentKey() << endl;
    // A.prev();
    // cout << A.currentKey() << endl;
    // if (A.currentKey() != "f" || A.currentVal() != 20)
    //     cout << 2 << endl;
    // return 0;
    // Dictionary A;
    // A.setValue("c", 3);
    // A.setValue("b", 2);
    // A.setValue("a", 1);
    // A.begin();
    // A.clear();
    // if (A.size() != 0) {
    //     cout << 1 << endl;
    // }
    // try {
    //     A.currentKey();
    //     cout << 2 << endl;
    // } catch (logic_error const &) {
    // }
    // return 0;
    // Dictionary A;
    // A.setValue("a", 1);
    // A.setValue("b", 5);
    // A.setValue("c", 16);
    // A.setValue("d", 176);
    // A.setValue("e", 3214);
    // A.begin();
    // A.next();
    // A.next();

    // if (A.currentKey() != "c" || A.currentVal() != 16)
    //     cout << 1 << endl;
    // A.next();
    // A.next();
    // A.next();
    // if (A.hasCurrent())
    //     cout << 2 << endl;
    // return 0;
    // Dictionary A;
    // try {
    //     A.begin();
    //     A.currentVal();
    //     cout << 1 << endl;
    // } catch (logic_error const &) {
    // }
    // try {
    //     A.end();
    //     A.currentVal();
    //     cout << 2 << endl;
    // } catch (logic_error const &) {
    // }
    // try {
    //     A.currentVal();
    //     cout << 3 << endl;
    // } catch (logic_error const &) {
    // }
    // try {
    //     A.currentKey();
    //     cout << 4 << endl;
    // } catch (logic_error const &) {
    // }

    // return 0;
    // Dictionary A;
    // A.setValue("c", 3);
    // A.setValue("a", 1);
    // A.setValue("b", 2);
    // A.remove("a");
    // if (A.size() != 2)
    //     cout << 1 << endl;
    // A.setValue("e", 5);
    // A.remove("c");
    // if (A.size() != 2)
    //     cout << 2 << endl;
    // return 0;
    // Dictionary D;
    // string s;
    // D.setValue("Hacks", 8);
    // D.setValue("Duck", 4);
    // D.setValue("Lucky", 12);
    // D.setValue("Bee", 2);
    // D.setValue("Ant", 1);
    // D.setValue("Cat", 3);
    // D.setValue("Funk", 6);
    // D.setValue("Elephant", 5);
    // D.setValue("Gecko", 7);
    // D.setValue("Jack", 10);
    // D.setValue("NATO", 14);
    // D.setValue("Integer", 9);
    // D.setValue("King", 11);
    // D.setValue("Map", 13);
    // D.setValue("Opinion", 15);
    // cout << D << endl;
    // D.begin();
    // D.next();
    // D.next();
    // D.prev();
    // cout << D.currentKey() << endl;
    // Dictionary A = D;
    // Dictionary E;
    // cout << (A == E) << endl;
    // return 0;
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