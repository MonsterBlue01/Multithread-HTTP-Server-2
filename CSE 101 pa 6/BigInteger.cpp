#include<iostream>
#include<string>
#include<stdexcept>
#include<bits/stdc++.h>

#include"BigInteger.h"
#include"List.h"

void negateList(List& L) {
    for (L.moveFront(); L.position() != L.length(); L.moveNext()) {
        L.setAfter(0 - L.peekNext());
    }
}

void sumList(List& S, List A, List B, int sgn) {
    List zero;
    zero.insertAfter(0);
    if ((A == zero) && (B == zero)) {
        S = zero;
        return;
    } else if ((!(A == zero)) && (B == zero)) {
        S = A;
        return;
    } else if ((A == zero) && (!(B == zero))) {
        S = B;
        return;
    }

    if (sgn == 1) {
        // std::cout << A << std::endl;
        // std::cout << B << std::endl;
        List tmp;
        A.moveBack();
        B.moveBack();
        while ((A.position() != 0) || (B.position() != 0)) {
            int one = 0;
            int two = 0;
            if (A.position() != 0) {
                one = A.peekPrev();
                A.movePrev();
            }
            if (B.position() != 0) {
                two = B.peekPrev();
                B.movePrev();
            }

            tmp.insertAfter(one + two);
            // std::cout << S << std::endl;
        }
        S = tmp;
    } else if (sgn == 0) {
        S = A;
    } else if (sgn == -1) {
        List tmp;
        negateList(B);
        // std::cout << A << std::endl;
        // std::cout << B << std::endl;
        A.moveBack();
        B.moveBack();
        while ((A.position() != 0) || (B.position() != 0)) {
            int one = 0;
            int two = 0;
            if (A.position() != 0) {
                one = A.peekPrev();
                A.movePrev();
            }
            if (B.position() != 0) {
                two = B.peekPrev();
                B.movePrev();
            }

            tmp.insertAfter(one + two);
        }
        S = tmp;
    }
}

void scalarMultList(List& L, ListElement m) {
    List tmp = L;
    List l;
    for (tmp.moveBack(); tmp.position() != 0; tmp.movePrev()) {
        // std::cout << tmp.peekPrev() << std::endl;
        long dl = tmp.peekPrev() * m;
        // std::cout << "Product: " << dl << std::endl;
        l.insertAfter(dl);
    }
    L = l;
    // std::cout << L << std::endl;
}

int normalizeList(List& L) {
    int num = 1;
    // std::cout << "Before normalizing: " << L << std::endl;
    L.moveFront();
    while ((L.peekNext() == 0) && (L.length() > 1)) {
        L.eraseAfter();
    }
    // std::cout << L << std::endl;
    // std::cout << L.peekNext() << std::endl;
    if (L.peekNext() < 0) {
        negateList(L);
        num = -1;
    }
    List tmp;
    long j = 0;
    long n = 0;
    for (L.moveBack(); L.position() != 0; L.movePrev()) {
        n = L.peekPrev();
        // std::cout << "The number: " << n << std::endl;
        n += j;
        if (n < 0) {
            j = -(n / 1000000000 + 1);
            n = n + 1000000000 * (0 - j);
        } else {
            j = n / 1000000000;
            n = n % 1000000000;
        }
        // std::cout << "The raw number: " << n << std::endl;
        tmp.insertAfter(n);
        if (L.position() == 1) {
            // std::cout << "end: " << j << std::endl;
            if (j > 0) {
                tmp.insertBefore(j);
            }
        }
    }
    L = tmp;
    // std::cout << "After normalizing: " << L << std::endl;
    return num;
}


void shiftList(List& L, int p) {
    // std::cout << "shiftList: " << L << std::endl;
    // std::cout << p << std::endl;
    for (int i = 0; i != p; i++) {
        L.moveBack();
        L.insertBefore(0);
    }
    // std::cout << "After shiftList: " << L << std::endl;
}

BigInteger::BigInteger(){
    signum = 0;
    List digits;
}

// Copy Constructor.
BigInteger::BigInteger(std::string s){
    std::string a;
    if ((s.substr(0, 1) == "-") || (s.substr(0, 1) == "+")) {
        a = s.substr(1);
        if (s.substr(0, 1) == "-") {
            this->signum = -1;
        } else if (s.substr(0, 1) == "+") {
            this->signum = 1;
        } else {
            std::cout << "Something went wrong..." << std::endl;
        }
    } else {
        a = s;
        this->signum = 1;
    }
    int i = a.size() - 9;
    for (; i > 0; i -= 9) {
        this->digits.insertAfter(std::stoi(a.substr(i, 9)));
    }
    if (i + 9 > 0) {
        this->digits.insertAfter(std::stoi(a.substr(0, i + 9)));
    }
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
    List S;
    BigInteger res;
    int sig;
    
    if (this->signum == -1) {
        List tmpthis = this->digits;
        negateList(tmpthis);
        sumList(S, tmpthis, N.digits, N.sign());
        // std::cout << "Sum: " << S << std::endl;
        sig = normalizeList(S);
        // std::cout << S << std::endl;
        res.signum = sig;
        res.digits = S;
        return res;
    } else if (this->signum == 1) {
        List tmpthis = this->digits;
        // std::cout << "this: " << this->digits << std::endl;
        // std::cout << "N.digits: " << N.digits << std::endl;
        // std::cout << "Sign: " << N.sign() << std::endl;
        sumList(S, this->digits, N.digits, N.sign());
        // std::cout << "Sum: " << S << std::endl;
        sig = normalizeList(S);
        // std::cout << S << std::endl;
        res.signum = sig;
        res.digits = S;
        return res;
    } else if (this->signum == 0) {
        res = BigInteger(0);
        res.signum = 0;
        return res;
    } else {
        // std::cout << "Something went wrong..." << std::endl;
    }
}

BigInteger BigInteger::sub(const BigInteger& N) const {
    BigInteger tmp = N;
    tmp.signum = 0 - tmp.signum;

    if (digits == N.digits) {
        tmp = BigInteger("0");
        return tmp;
    }
    // std::cout << "A: " << *this << std::endl;
    // std::cout << "B: " << tmp << std::endl;
    BigInteger res = add(tmp);
    return res;
}

BigInteger BigInteger::mult(const BigInteger& N) const {
    BigInteger tmp = BigInteger("0");
    List one = this->digits;
    List two = N.digits;
    // std::cout << one << std::endl;
    // std::cout << two << std::endl;
    int num = 0;
    for (two.moveBack(); two.position() != 0; two.movePrev()) {
        long owt = two.peekPrev();
        one = this->digits;
        // std::cout << "one: " << one << std::endl;
        // std::cout << "two: " << owt << std::endl;
        scalarMultList(one, owt);
        // std::cout << "Before normalized: " << one << std::endl;
        normalizeList(one);
        // std::cout << "After normalized: " << one << std::endl;
        shiftList(one, num++);
        // std::cout << "After shifted: " << one << std::endl;
        sumList(tmp.digits, tmp.digits, one, 1);
        // std::cout << "sum: " << tmp.digits << std::endl;
        normalizeList(tmp.digits);

    }
    return tmp;
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
    if (sign() == -1) {
        return "-" + s;
    } else {
        return s;
    }
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

BigInteger operator*( const BigInteger& A, const BigInteger& B ) {
    return A.BigInteger::mult(B);
}