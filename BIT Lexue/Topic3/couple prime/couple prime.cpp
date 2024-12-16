// This is the solution using the Prime filter of 【中学】孪生素数（编子函数，未来考试的形式之一）
// Created by FUGUO on 2024/11/2.
//
/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

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

int vis[3000000] = {1,1};
int temp = 1;
void prime_Era(int qwq){
    for(int i=2 ;i <= qwq; i++){
        if(vis[i]){
            continue; // If i is composite, do not carry out.
        }
        for(int j = i * 2; j <= qwq; j += i){
            vis[j] = true;
        }
    }
}
int isPrime(int x){
    if(temp){
        prime_Era(2999999);
        temp = 0;
    }
    return !vis[x];
}

/* PRESET CODE END - NEVER TOUCH CODE ABOVE */