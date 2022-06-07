1. 

2.  std::string TreeWalk(Node* R, std::string s) {
        if ((s == "pre") || (s == "in") || (s == "post")) {
            std::string tmp;
            if (s == "pre") {
                tmp += to_string(R.i);
            }
            TreeWalk(R->left, s);
            if (s == "in") {
                tmp += to_string(R.i);
            }
            TreeWalk(R->right, s);
            if (s == "post") {
                tmp += to_string(R.i);
            }
            return tmp;
        } else {
            std::string a = "";
            return a;
        }
    }

3.  a. 5 1 9 2 10 7 3 6 8 4
    b.  x:      1   2   3   4   5   6   7   8   9   10
        d[x]:   1   2   4   6   0   3   3   4   1   2
        p[x]:   5   1   2   3   N/A 10  2   7   5   9