// This is the solution of https://lexue.bit.edu.cn/mod/programming/view.php?id=468933
// Created by FUGUO on 2024/12/17.
//
/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

//  Copy is waiting for you.

#include <iostream>
using namespace std;


void copy(int &dest, int src) {
    dest = src;
}

void copy(double &dest, double src) {
    dest = src;
}

void copy(char * dest, const char * src) {
    while (*src) {
        *dest++ = *src++;
    }
    *dest = '\0';
}

int main()
{
    int x, y;
    double a, b;
    char s[100], s2[100];
    cin >> y; copy(x, y);
    cin >> b; copy(a, b);
    cin >> s2;    copy(s, s2);
    cout << "x=" << x << endl;
    cout << "a=" << a << endl;
    cout << "s=" << s << endl;
    return 0;
}

/* PRESET CODE END - NEVER TOUCH CODE ABOVE */



