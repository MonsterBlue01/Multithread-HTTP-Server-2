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

4. 7 4 5b 1a 8 3 ab 5a 2c 6 2b 2a

5.  vertex  adj     color   distance    parent
    1       2       black   1           4
    2       5, 6    black   1           4
    3       null    black   3           6
    4       1, 2    black   0           null
    5       4, 7    black   2           2
    6       3, 9    black   2           2
    7       null    black   3           5
    8       5       white   INF         null
    9       null    black   3           6

    Queue: 4 1 2 5 6 7 3 9
    BFS Tree: 4
             / \
            1   2
               / \
              5   6
             /   / \
            7   3   9

6.  vertex  adj         discover    finish  parent 
    1       2, 4        1           16      null
    2       5, 6        2           15      1
    3       null        12          13      6
    4       null        4           5       5
    5       4, 7, 8     3           10      2
    6       3, 5        11          14      2
    7       null        6           7       5
    8       null        8           9       5

    DFS Forest: 1
                | 
                2   
               / \
              5   6
             /|\   \
            4 7 8   3

    Stack: 1 2 6 3 5 8 7 4

    Tree:       (1, 2), (2, 5), (2, 6), (5, 4), (5, 7), (5, 8), (6, 3)
    Back:       
    Forward:    (1, 4)
    Cross:      (6, 5)

Note: 1. Copy the eccentricity functions in quiz1solu.
