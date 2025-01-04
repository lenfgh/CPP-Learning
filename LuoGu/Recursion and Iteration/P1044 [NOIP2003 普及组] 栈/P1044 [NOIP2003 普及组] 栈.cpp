//
// Created by FUGUO on 2025/1/4.
//
#include<iostream>

using namespace std;

int cache[20][20]={0};

int dfs(int s, int q) {
    if(cache[s][q] != 0) return cache[s][q];
    if(q==0) {
        cache[s][q]=1;
        return 1;
    }
    if(s==0) {
        cache[s][q] = dfs(s+1,q-1);
        return cache[s][q];
    }
    cache[s][q] = dfs(s-1,q)+dfs(s+1,q-1);
    return cache[s][q];
}

int main() {
    int n;
    cin >> n;
    cout << dfs(0,n);
    return 0;
}