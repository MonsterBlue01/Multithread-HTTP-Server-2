#include <iostream>
using namespace std;

#include "List.h"
#include "BigInteger.h"

int main() {
    BigInteger A = BigInteger("+111122223333");
    BigInteger B = BigInteger("+111122223333");

    BigInteger C = A - B;
    if (C.sign() != 0)
        std::cout << 1 << std::endl;

    // pos - pos < 0
    B = BigInteger("121122223333");
    BigInteger D = BigInteger("-10000000000");
    C = A - B;
    if (C.sign() != -1)
        std::cout << 21 << std::endl;
    if (!(C == D))
        std::cout << 22 << std::endl;

    // pos - pos > 0
    B = BigInteger("101122223333");
    D = BigInteger("10000000000");
    C = A - B;
    if (C.sign() != 1)
        std::cout << 31 << std::endl;
    if (!(C == D))
        std::cout << 32 << std::endl;

    // pos - neg = pos
    B.negate();
    D = BigInteger("212244446666");
    C = A - B;
    if (C.sign() != 1)
        std::cout << 41 << std::endl;
    if (!(C == D))
        std::cout << 42 << std::endl;

    // neg - pos = neg
    D.negate();
    C = B - A;
    if (C.sign() != -1)
        std::cout << 51 << std::endl;
    if (!(C == D))
        std::cout << 52 << std::endl;

    return 0;

    // BigInteger A = BigInteger("+111122223333");
    // BigInteger B = BigInteger("+222211110000");

    // // pos + pos = pos
    // BigInteger D = BigInteger("+333333333333");
    // BigInteger C = A + B;

    // if (!(C == D))
    //     std::cout << 1 << std::endl;

    // // add a positive and a negative integer
    // //-> pos + neg = 0
    // B = BigInteger("-111122223333");
    // C = A + B;
    // // std::cout << A << std::endl;
    // // std::cout << B << std::endl;
    // if (C.sign() != 0)
    //     std::cout << 2 << std::endl;
    //     // std::cout << C << std::endl;

    // //-> pos + neg > 0
    // B = BigInteger("-110122223333");
    // D = BigInteger("1000000000");
    // C = A + B;
    // if (C.sign() != 1)
    //     std::cout << 31 << std::endl;
    // if (!(C == D))
    //     std::cout << 32 << std::endl;

    // //-> pos + neg < 0
    // B = BigInteger("-112122223333");
    // D = BigInteger("-1000000000");
    // C = A + B;
    // if (C.sign() != -1)
    //     std::cout << 41 << std::endl;
    // if (!(C == D))
    //     std::cout << 42 << std::endl;

    // //-> neg + neg = neg
    // A = BigInteger("-221211110000");
    // D = BigInteger("-333333333333");
    // C = A + B;
    // if (!(C == D))
    //     std::cout << 5 << std::endl;

    
    // BigInteger A = BigInteger("9128734667000004389234563456345619187236478");
    // BigInteger B = BigInteger("9876545439000000000000000200000000000006543654365346534");

    // cout << B * A << endl;

    // BigInteger A = BigInteger("-1");
    // BigInteger B = BigInteger("0");
    // BigInteger C = BigInteger("1");
    // BigInteger D = BigInteger("1234567890987654321");
    // BigInteger E = BigInteger("-9991234567890987654321");
    // BigInteger H = BigInteger("2222");
    // BigInteger I = BigInteger("-1");
    // BigInteger F = BigInteger("-333333333333");
    // BigInteger J;
    // BigInteger G;

    // cout << E + D << endl;

    // std::cout << "F: " << F << std::endl;
    // std::cout << "H: " << H << std::endl;
    // std::cout << "I: " << I << std::endl;

    // G = D + E;
    // cout << "A+A: " << A+A << endl;
    // cout << "A+B: " << A+B << endl;
    // cout << "A+C: " << A+C << endl;
    // cout << "B+A: " << B+A << endl;
    // cout << "B+B: " << B+B << endl;
    // cout << "B+C: " << B+C << endl;
    // cout << "C+A: " << C+A << endl;
    // cout << "C+B: " << C+B << endl;
    // cout << "D+E: " << D+E << endl;
    // cout << "H+I: " << H+I << endl;

    // J = H + I;

    // std::cout << "G: " << G <<std::endl;
    // std::cout << "G's sig: " << G.sign() <<std::endl;
    // std::cout << "F: " << F <<std::endl;
    // std::cout << "F's sig: " << F.sign() <<std::endl;
    // std::cout << (F == G) << std::endl;

    // BigInteger A, B, C, D;

    // A = BigInteger("+13378008135");
    // A.makeZero();
    // if (A.sign() != 0)
    //     std::cout << 1 << std::endl;

    // B = BigInteger();
    // // std::cout << "A: " << A << std::endl;
    // // std::cout << "B: " << B << std::endl;
    // if (!(A == B))
    //     std::cout << 2 << std::endl;
    // return 0;

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
