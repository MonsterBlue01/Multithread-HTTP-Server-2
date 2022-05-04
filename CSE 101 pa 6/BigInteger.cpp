#include<iostream>
#include<string>
#include<stdexcept>

#include"BigInteger.h"
#include"List.h"

BigInteger::BigInteger(){
    signum = 0;
    List digits;
}

// Copy Constructor.
BigInteger::BigInteger(std::string s){
    signum = 0;
    List digits;

    std::string par;
    List L;
    std::string n = s.substr(0, 1);
    if (n == "-") {
        n = s.substr(1);
    } else {
        n = s;
    }
    for (int i = 0; i < n.size(); i += 9) {
        par = n.substr(i, 9);
        int tmp = stoi(par);
        L.insertBefore(tmp);
    }
}

