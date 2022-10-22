#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
    ifstream grade;
    grade.open("grade.csv");

    string name;
    int score;
    pair<string, int> student;
    while (grade >> name >> score) {
        student = make_pair(name, score);
        cout << student.first << " " << student.second << endl;
    }

    grade.close();
}