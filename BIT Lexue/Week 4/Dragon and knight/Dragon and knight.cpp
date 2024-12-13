// This is the solution of The dragons of BIT.
// Created by FUGUO on 2024/11/2.
//
#include<iostream>
#include<algorithm>
using namespace std;

int n,m;

inline bool compare(int x, int y){
    return x>y;
}

int main(){
    int dragon[110]={0},knight[110]={0};
    cin>>n>>m;

    for(int i = 0; i<n; i++ ){
        cin>>dragon[i];
    }

    sort(dragon,dragon+n, compare);

    int num=0;

    for(int i = 0; i<m; i++){
        cin>>knight[num];
        num+=1;
        if(knight[num-1]<dragon[n-1]){
            knight[num-1]=0;
            num-=1;
        }
    }

    if(0==n){
        cout<<0<<endl;
        return 0;
    }

    if(num < n){
        cout<<"bit is doomed!"<<endl;
        return 1;
    }

    sort(knight,knight+num,compare);

    int sum = 0;

    if(knight[0]<dragon[0]){
        cout<<"bit is doomed!"<<endl;
        return 3;
    }
    int i=num-1,j=n-1;

    while(i>=0&&j>=0){
        if(knight[i]>=dragon[j]){
            sum+=knight[i];
            i--;
            j--;
            if(i<0&&j>=0){
                cout<<"bit is doomed!"<<endl;
                return 0;
            }
        }
        else if(knight[i]<dragon[j]){
            i--;
            if(i<0){
                cout<<"bit is doomed!"<<endl;
                return 0;
            }
        }
    }

    cout<<sum<<endl;

    return 0;
}