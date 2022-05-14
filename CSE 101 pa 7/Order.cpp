#include <iostream>
#include <fstream>

#include "Dictionary.h"

using namespace std;

int main (int argh, char * argv[]) {
    ifstream infile;
    ofstream outfile; 
    infile.open(argv[1]);
    outfile.open(argv[2]);
    string s1, s2;
    int i = 1;
    Dictionary D;

    while (!infile.eof()) { 
        getline(infile, s1);
        D.setValue(s1, i++);
        // cout << s << endl; 
    }

    outfile << D << endl;
    s2 = D.pre_string();
    outfile << s2 << endl;

    infile.close();
    outfile.close();
    return 0;
}