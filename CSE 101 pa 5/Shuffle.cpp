#include <iostream>
#include <stdio.h>

#include "List.h"

using namespace std;

void shuffle(List& D) {
    List ori = D;
    List pa, pb;
    int k = D.length() / 2;
    while (true) {
        for (ori.moveFront(); ori.position() != k; ori.moveNext());
        while (ori.position() != 0) {
            pa.insertAfter(ori.peekPrev());
            ori.eraseBefore();
        }
        for (ori.moveBack(); ori.position() != 0; ori.eraseBefore()) {
            pb.insertAfter(ori.peekPrev());
        }
        pa.moveBack();
        pb.moveBack();
        while ((pa.position() != 0) || (pb.position() != 0)) {
            if (pb.position() != 0) {
                ori.insertAfter(pb.peekPrev());
                pb.eraseBefore();
            }
            if (pa.position() != 0) {
                ori.insertAfter(pa.peekPrev());
                pa.eraseBefore();
            }
        }
        break;
    }
    D = ori;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cout << "Less or more than two parameters are passed." << endl;
        return 0;
    }

    for (char * i = argv[1]; *i != NULL; i++) {
        if (!isdigit(*i)) {
            cout << "The input does not meet the requirements." << endl;
            return 0;
        }
    }

    int v;

    sscanf (argv[1], "%d", &v);

    cout << "deck size       shuffle count" << endl;
    cout << "------------------------------" << endl;
    for (int i = 2; i <= v + 1; i++) {
        cout << " " << i - 1;
        if (i <= 10) {
            cout << "               ";
        } else if (i <= 100) {
            cout << "              ";
        } else if (i <= 1000) {
            cout << "             ";
        } else if (i <= 10000) {
            cout << "            ";
        } else if (i <= 100000) {
            cout << "           ";
        } else if (i <= 1000000) {
            cout << "          ";
        } else if (i <= 10000000) {
            cout << "         ";
        } else if (i <= 100000000) {
            cout << "        ";
        } else if (i <= 1000000000) {
            cout << "       ";
        } else if (i <= 10000000000) {
            cout << "      ";
        } else {
            cout << "     ";
        }
        
        int tmp = 0;
        List B;
        List L;
        for (int j = 1; j <= i; j++) {
            L.insertBefore(j);
        }
        B = L;
        do {
            shuffle(L);
            tmp++;
        } while (!(B == L));
        cout << tmp << endl;
    }

    return 0;
}