#include <iostream>
#include "Dictionary.h"

using namespace std;

int main() {
    Dictionary A, B;
    std::string ideal1 = "b\na\nf\ne\nh\ni\n";
    std::string ideal2 =
        "heat\neradicate\nbolstering\nabjuration\nfeather\ninsignia\n";
    std::string ideal3 = "heat\neradicate\nabjuration\nabbreviation\n"
                            "bolstering\nfeather\ngodsend\njustify\n"
                            "insignia\nquizzical\nleaflet\nsolemnly\n";
    A.setValue("a", 1);
    A.setValue("b", 5);
    A.setValue("e", 10);
    A.setValue("h", 15);
    A.setValue("f", 20);
    A.setValue("i", 100);

    if (A.pre_string() != ideal1)
        cout << 1 << endl;

    B.setValue("insignia", 100);
    B.setValue("feather", 20);
    B.setValue("heat", 15);
    B.setValue("eradicate", 10);
    B.setValue("bolstering", 5);
    B.setValue("abjuration", 1);

    if (B.pre_string() != ideal2)
        cout << B.pre_string() << endl;
        cout << ideal2 << endl;
        cout << 2 << endl;

    B.setValue("justify", 100);
    B.setValue("leaflet", 20);
    B.setValue("godsend", 15);
    B.setValue("quizzical", 10);
    B.setValue("solemnly", 5);
    B.setValue("abbreviation", 1);

    if (B.pre_string() != ideal3)
        cout << 3 << endl;
    return 0;
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
    //     cout << 3 << endl;;
    // return 0;
    // A.setValue("a", 1);
    // A.setValue("b", 2);
    // A.setValue("c", 3);
    // A.setValue("e", 5);
    // if (A.size() != 4)
    //     cout << 1 << endl;
    // return 0;
    // abcdefghij k l m n o p q r s t u v w x y z
    // 1234567891011121314151617181920212223242526
    // Dictionary D;
    // D.setValue("Hill", 1);
    // D.setValue("Lemon", 2);
    // D.setValue("Demon", 3);
    // D.setValue("Bee", 4);
    // D.setValue("Font", 5);
    // D.setValue("Joker", 6);
    // D.setValue("Ninja", 7);
    // D.setValue("Apple", 8);
    // D.setValue("Cat", 9);
    // D.setValue("Egg", 10);
    // D.setValue("Ginger", 11);
    // D.setValue("Ikon", 12);
    // D.setValue("K", 13);
    // D.setValue("Mongolia", 14);
    // D.setValue("Opera", 15);
    // string s;
    // s = D.to_string();
    // cout << "s: " << s << endl;
    return 0;
}