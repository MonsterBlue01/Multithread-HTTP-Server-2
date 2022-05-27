//-----------------------------------------------------------------------------
// FileIO.cpp
// Illustrates file input-output commands and text processing using the
// string functions find_first_of(), find_first_not_of() and substr().
// 
// compile:
//
//      g++ -std=c++17 -Wall -o FileIO FileIO.cpp
//
//-----------------------------------------------------------------------------
#include<iostream>
#include<fstream>
#include<string>
#include <algorithm>

#include "Dictionary.h"

using namespace std;

#define MAX_LEN 300

int main(int argc, char * argv[]){
    size_t begin, end, len;
    ifstream in;
    ofstream out;
    string line;
    string tokenBuffer;
    string token;
    //string delim = " "; 
    string delim = " \t\\\"\',<.>/?;:[{]}|`~!@#$%^&*()-_=+0123456789";

    Dictionary D;

    // check command line for correct number of arguments
    if( argc != 3 ){
        cerr << "Usage: " << argv[0] << " <input file> <output file>" << endl;
        return(EXIT_FAILURE);
    }

    // open files for reading and writing 
    in.open(argv[1]);
    if( !in.is_open() ){
        cerr << "Unable to open file " << argv[1] << " for reading" << endl;
        return(EXIT_FAILURE);
    }

    out.open(argv[2]);
    if( !out.is_open() ){
        cerr << "Unable to open file " << argv[2] << " for writing" << endl;
        return(EXIT_FAILURE);
    }

    while( getline(in, line) )  {
        len = line.length();

        // get first token
        begin = min(line.find_first_not_of(delim, 0), len);
        end   = min(line.find_first_of(delim, begin), len);
        token = line.substr(begin, end-begin);
        
        while(token != ""){  // we have a token
            // update token buffer
            transform(token.begin(),token.end(),token.begin(),::tolower);
            bool b = D.contains(token);
            if (b == false) {
                D.setValue(token, 1);
            } else {
                D.setValue(token, D.getValue(token) + 1);
            }
            // cout << "token: " << token << endl;

            // get next token
            begin = min(line.find_first_not_of(delim, end+1), len);
            end   = min(line.find_first_of(delim, begin), len);
            token = line.substr(begin, end-begin);
        }
    }

    out << D << endl;

    // close files 
    in.close();
    out.close();

    return(EXIT_SUCCESS);
}
