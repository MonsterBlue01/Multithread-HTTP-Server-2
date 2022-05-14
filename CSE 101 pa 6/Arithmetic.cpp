#include <fstream>
#include <iomanip>
#include <iostream>

#include "List.h"
#include "BigInteger.h"

using namespace std;

int main (int argh, char * argv[]) {


    char buf[16384];
    string tmp;

    string one, two;
    int num = q;

    ifstream infile; 
    infile.open(argv[1]); 

    ofstream outfile;
    outfile.open(argv[2], ios::out | ios::trunc );

    while (!(infile.eof())) {
        infile.getline(buf, 16384);
        tmp = buf;
        if (num == 0) {
            one = tmp;
        } else if (num == 2) {
            two = tmp;
        }
        num++;
    }

    BigInteger A = BigInteger(one);
    BigInteger B = BigInteger(two);

    outfile << A << endl;
    outfile << endl;
    outfile << B << endl;
    outfile << endl;
    outfile << A + B << endl;
    outfile << endl;
    outfile << A - B << endl;
    outfile << endl;
    outfile << A - A << endl;
    outfile << endl;
    outfile << A + A + A - B - B << endl;
    outfile << endl;
    outfile << A * B << endl;
    outfile << endl;
    outfile << A * A << endl;
    outfile << endl;
    outfile << B * B << endl;
    outfile << endl;
    BigInteger b = (A * A * A * A) + (A * A * A * A) + (A * A * A * A) + (A * A * A * A) + (A * A * A * A) +(A * A * A * A) + (A * A * A * A) + (A * A * A * A) + (A * A * A * A) + (B * B * B * B * B)+ (B * B * B * B * B)+ (B * B * B * B * B)+ (B * B * B * B * B)+ (B * B * B * B * B)+ (B * B * B * B * B)+ (B * B * B * B * B)+ (B * B * B * B * B)+ (B * B * B * B * B)+ (B * B * B * B * B)+ (B * B * B * B * B)+ (B * B * B * B * B)+ (B * B * B * B * B)+ (B * B * B * B * B)+ (B * B * B * B * B)+ (B * B * B * B * B);
    outfile << b << endl;

    outfile.close();
    infile.close();

    return 0;
}
