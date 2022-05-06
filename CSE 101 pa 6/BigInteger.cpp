#include<iostream>
#include<string>
#include<stdexcept>
#include<bits/stdc++.h>

#include"BigInteger.h"
#include"List.h"

BigInteger::BigInteger(){
    signum = 0;
    List digits;
}

// Copy Constructor.
BigInteger::BigInteger(std::string s){
    signum = 0;

    if (s == "0") {
        digits.insertAfter(0);
        return;
    }

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
    for (int i = s.length() - 9; i > 0; i -= 9) {
        L.insertAfter(stoi(s.substr(i, 9)));
    }
    if (s.length() % 9 != 0) {
        L.insertAfter(stoi(s.substr(0, s.length() % 9)));
    } else {
        L.insertAfter(stoi(s.substr(0, 9)));
    }

    this->digits = L;
}

BigInteger::BigInteger(const BigInteger& N) {
    this->signum = N.signum;
    this->digits = N.digits;
}

int BigInteger::sign() const{
    return signum;
}

int BigInteger::compare(const BigInteger& N) const{
    BigInteger one = *this;
    BigInteger two = N;
    if (one.signum > two.signum) {
        return 1;
    } else if (one.signum < two.signum) {
        return -1;
    } else {
        if ((one.signum == 0) && (two.signum == 0)) {
            return 0;
        } else if ((one.signum == 1) && (two.signum == 1)) {
            std::string s1 = one.to_string();
            std::string s2 = two.to_string();
            if (s1.length() > s2.length()) {
                return 1;
            } else if (s1.length() < s2.length()) {
                return -1;
            } else {
                for (int i = 0; i < s1.length(); i++) {
                    std::string ch1 = s1.substr(i, 1);
                    std::string ch2 = s2.substr(i, 1);
                    if (std::stoi(ch1) > std::stoi(ch2)) {
                        return 1;
                    } else if (std::stoi(ch1) < std::stoi(ch2)) {
                        return -1;
                    } else {
                        continue;
                    }
                }
            }
            return 0;
        } else if ((one.signum == -1) && (two.signum == -1)) {
            std::string s1 = one.to_string().substr(1);
            std::string s2 = two.to_string().substr(1);
            if (s1.length() > s2.length()) {
                return -1;
            } else if (s1.length() < s2.length()) {
                return 1;
            } else {
                for (int i = 0; i < s1.length(); i++) {
                    std::string ch1 = s1.substr(i, 1);
                    std::string ch2 = s2.substr(i, 1);
                    if (std::stoi(ch1) > std::stoi(ch2)) {
                        return -1;
                    } else if (std::stoi(ch1) < std::stoi(ch2)) {
                        return 1;
                    } else {
                        continue;
                    }
                }
                return 0;
            }
        } else {
            std::cout << "Something went wrong..." << std::endl;
            return 0;
        }
        return 0;
    }
}

void BigInteger::makeZero(){
    signum = 0;
    List tmp;
    digits = tmp;
}

void BigInteger::negate(){
    if (signum == 0) {
        return;
    } else if (abs(signum) == 1) {
        signum = 0 - signum;
    }
}

BigInteger BigInteger::add(const BigInteger& N) const {
    BigInteger b1 = *this;
    BigInteger b2 = N;
    BigInteger res;
    int m = 0;
    int n1, n2, j = 0;
    
    b1.digits.moveBack();
    b2.digits.moveBack();

    if ((this->signum == 1) && (N.signum == 1)) {
        res.signum = 1;
        while ((b1.digits.position() != 0) || (b2.digits.position() != 0)) {
            n1 = 0;
            n2 = 0;
            if (b1.digits.position() != 0) {
                n1 = b1.digits.peekPrev();
                b1.digits.movePrev();
            }
            if (b2.digits.position() != 0) {
                n2 = b2.digits.peekPrev();
                b2.digits.movePrev();
            }

            if (j == 1) {
                if (n1 + n2 + 1 >= 1000000000) {
                    std::cout << "sum: " << n1 + n2 + 1 - 1000000000 << std::endl;
                } else {
                    std::cout << "sum: " << n1 + n2 + 1 << std::endl;
                    j = 0;
                }
            } else {
                if (n1 + n2 + 1 >= 1000000000) {
                    std::cout << "sum: " << n1 + n2 - 1000000000 << std::endl;
                    j = 1;
                } else {
                    std::cout << "sum: " << n1 + n2 << std::endl;
                }
            }
        }
    }
    return res;
}

BigInteger BigInteger::sub(const BigInteger& N) const {
    BigInteger o = *this;
    BigInteger t = N;
    o.digits.moveBack();
    t.digits.moveBack();
    int j;
    while ((o.digits.position() != 0) || (t.digits.position() != 0)) {
        int n1 = 0;
        int n2 = 0;
        if (o.digits.position() != 0) {
            std::cout << "out" << std::endl;
            n1 = o.digits.peekPrev();
            o.digits.movePrev();
        }
        if (t.digits.position() != 0) {
            std::cout << "out" << std::endl;
            n2 = t.digits.peekPrev();
            t.digits.movePrev();
        }
        std::cout << "n1: " << n1 << std::endl;
        std::cout << "n2: " << n2 << std::endl;
        if (j == -1) {
            if (n1 - n2 - 1 < 0) {
                std::cout << "diff: " << n1 - n2 - 1 + 1000000000 << std::endl;
            } else {
                std::cout << "diff: " << n1 - n2 - 1 << std::endl;
                j = 0;
            }
        } else {
            if (n1 - n2 < 0) {
                std::cout << "diff: " << n1 - n2 + 1000000000 << std::endl;
                j = -1;
            } else {
                std::cout << "diff: " << n1 - n2 << std::endl;
            }
        }
    }
    return N;
}

std::string BigInteger::to_string(){
    std::string s = "";
    for (this->digits.moveBack(); this->digits.position() != 0; this->digits.movePrev()) {
        std::string t = std::to_string(this->digits.peekPrev());
        if (this->digits.position() != 1) {
            if (this->digits.peekPrev() == 0) {
                t = "000000000";
            } else {
                for (int i = 0; i < 8 - (int)log10(this->digits.peekPrev()); i++) {
                    t = "0" + t;
                }
            }
        }
        s = t + s;
    }
    return s;
}

std::ostream& operator<< ( std::ostream& stream, BigInteger N ) {
    return stream << N.BigInteger::to_string();
}

bool operator== ( const BigInteger& A, const BigInteger& B ) {
    if (A.signum != B.signum) {
        return false;
    } else {
        if (!(A.digits == B.digits)) {
            return false;
        } else {
            return true;
        }
    }
}

BigInteger operator+( const BigInteger& A, const BigInteger& B ) {
    return A.BigInteger::add(B);
}

BigInteger operator-( const BigInteger& A, const BigInteger& B ) {
    return A.BigInteger::sub(B);
}