// This is the solution of the
// Created by FUGUO on 2024/11/2.
//
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n, m;
    int isPrime( int );  // 若是素数函数isPrim返回1，否则返回0

    cin >> n >> m;
    while ( n < m-1 )
    {
        if ( isPrime(n) && isPrime(n+2) )
        {
            cout << n << "," << n+2 << endl;
        }
        n++;
    }
    return 0;
}

int isPrime(int num){
    if (num <= 1) {
        return false;
    }
    if (num <= 3) {
        return true;
    }
    if (num % 2 == 0 || num % 3 == 0) {
        return false;
    }
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}