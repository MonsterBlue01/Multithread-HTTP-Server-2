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

    std::string par;
    List L;
    std::string n = s.substr(0, 1);
    if (n == "-") {
        n = s.substr(1);
        signum = -1;
    } else {
        n = s;
        signum = 1;
    }
    for (int i = 0; i < n.size(); i += 9) {
        par = n.substr(i, 9);
        int tmp = stoi(par);
        this->digits.insertBefore(tmp);
    }
}

std::string BigInteger::to_string(){
    std::string tmp = "";
    List L;
    if (this->digits == L) {
        return tmp;
    }
    if (this->signum == -1) {
        tmp = "-" + tmp;
    }
    for (this->digits.moveFront(); this->digits.position() != this->digits.length(); this->digits.moveNext()) {
        int num = this->digits.peekNext();
        std::string s = std::to_string(num);
        tmp = tmp + s;
    }
    return tmp;
}

std::ostream& operator<< ( std::ostream& stream, BigInteger N ) {
    return stream << N.BigInteger::to_string();
}

