// This is the solution using the search.
// Created by FUGUO on 2024/12/31.
//
#include<iostream>

using namespace std;

int n,tot,maxn,boys[30][30],girls[30][30];

bool visited[30]={false};

void dfs(int i, int sum) {
    if(i == n+1) {
        tot = max(tot,sum);
        return;
    }// the n-th boy was calculated

    int temp = 0;

    for(int j=i; j<=n; j++) {
        for(int k=1;k<=n;k++) {
            maxn = max(maxn,boys[j][k]*girls[k][j]);
        }
        temp += maxn;
    }

    if(sum + temp <= tot) return;

    for (int j=1; j <= n; j++) {
        if(!visited[j]) {
            visited[j]=true;
            dfs(i+1,sum+boys[i][j]*girls[j][i]);
            visited[j]=false;
        }
    }
}

int main() {
    cin >> n;
    for(int i=1; i<=n; i++) {
        for ( int j=1; j<=n; j++) {
            cin >> boys[i][j];
        }
    }

    for(int i=1; i<=n; i++) {
        for ( int j=1; j<=n; j++) {
            cin >> girls[i][j];
        }
    }

    dfs(1,0);

    cout << tot << endl;

    return 0;
}