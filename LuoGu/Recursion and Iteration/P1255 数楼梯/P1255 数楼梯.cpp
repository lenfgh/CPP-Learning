//
// Created by FUGUO on 2025/1/1.
//

#include<iostream>
using namespace std;

int dfs(int i) {
    if(i==1) return 1;
    if(i==2) return 2;
    return dfs(i-1) + dfs(i-2);
}

int main() {
    int n;
    cin >> n;
    int tot = dfs(n);
    cout << tot;
    return 0;
}