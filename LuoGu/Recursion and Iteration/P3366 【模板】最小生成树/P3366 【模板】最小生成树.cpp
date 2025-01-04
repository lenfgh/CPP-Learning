//
// Created by FUGUO on 2025/1/4.
//
#include<iostream>
#include<algorithm>
using namespace std;

struct edge {
    int start,to,val;
}bian[200010];

int f[5010];

int find(int x) {
    if(f[x] == x) return x;
    f[x] = find(f[x]);
    return f[x];
}

bool cmp(edge a, edge b) {
    return a.val<b.val;
}

int ans=0,tot=0,m,n;
void krustal() {
    for(int i=1; i<=m;i++ ) {
        int s = find(bian[i].start);
        int t = find(bian[i].to);
        if(s==t) continue;
        ans += bian[i].val;
        f[t] = s;
        tot++;
        if(tot==n-1) break;
    }
}

int main() {
    cin >> n >> m;
    for(int i=1;i<=n;i++) f[i]=i;
    for(int i=1;i<=m;i++) {
        cin >> bian[i].start >> bian[i].to >> bian[i].val;
    }
    sort(bian+1,bian+m+1,cmp);
    krustal();
    cout << ans;
    return 0;
}