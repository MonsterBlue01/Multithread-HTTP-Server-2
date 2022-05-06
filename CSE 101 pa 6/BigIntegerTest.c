#include <iostream>
using namespace std;

#include "List.h"
#include "BigInteger.h"

int main() {
    BigInteger A, B, C, D;

    A = BigInteger("+13378008135");
    A.makeZero();
    if (A.sign() != 0)
        std::cout << 1 << std::endl;

    B = BigInteger();
    // std::cout << "A: " << A << std::endl;
    // std::cout << "B: " << B << std::endl;
    if (!(A == B))
        std::cout << 2 << std::endl;
    return 0;

    // A = BigInteger("+13378008135");
    // A.negate();
    // if (A.sign() != -1)
    //     std::cout << 1 << std::endl;

    // A.negate();
    // if (A.sign() != 1)
    //     std::cout << 2 << std::endl;

    // B = BigInteger();
    // B.negate();
    // if (B.sign() != 0)
    //     std::cout << 3 << std::endl;

    // return 0;

    // if (A.sign() != 0)
    //     std::cout << 1 << std::endl;
    //     B = BigInteger("13378008135");
    //     C = BigInteger("+13378008135");
    //     D = BigInteger("-13378008135");
    //     if (B.sign() != 1)
    //         std::cout << 2 << std::endl;
    //     if (C.sign() != 1)
    //         std::cout << 3 << std::endl;
    //     if (D.sign() != -1)
    //         std::cout << 4 << std::endl;
    //     return 0;
    // return 0;
}