#include <iostream>
#include <fstream>

#include "Dictionary.h"

using namespace std;

int main (int argh, char * argv[]) {
    ifstream infile0;
    string s0;
    infile0.open(argv[1]);
    int num = 0;

    while (!infile0.eof()) {
        getline(infile0, s0);
        num++;
    }

    infile0.close();
    cout << num << endl;

    ifstream infile;
    ofstream outfile; 
    infile.open(argv[1]);
    outfile.open(argv[2]);
    string s1, s2;
    int i = 1;
    Dictionary D;

    for (int a = num; a > 1; a--) { 
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