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