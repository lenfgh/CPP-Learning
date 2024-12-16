// This is the solution of https://lexue.bit.edu.cn/mod/programming/view.php?id=468914
// Created by FUGUO on 11.21.2024
//
#include<iostream>

using namespace std;

void generateBeautifulNumbers(int n, int w, string current, int lastDigit) {
    if (current.length() == n) {
        if (current.back() - '0' == w) {
            cout << current << endl;
        }
        return;
    }

    for (int i = lastDigit; i <= 9; ++i) {
        generateBeautifulNumbers(n, w, current + to_string(i), i);
    }
}

int main() {
    int n, w;
    cin >> n >> w;

    for (int i = 1; i <= 9; ++i) {
        generateBeautifulNumbers(n, w, to_string(i), i);
    }

    return 0;
}


