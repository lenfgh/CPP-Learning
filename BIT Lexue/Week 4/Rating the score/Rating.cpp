// This is the solution of the 【应用】决赛成绩排序
// Created by FUGUO on 2024/11/2.
//
#include<iostream>
#include<algorithm>
using namespace std;

int input[120];
int num;

inline bool comp(int x,int y){
    return x < y;
}

int main(){
    cin>>num;
    for(int i =1;i<=num;i++){
        cin>>input[i];
    }

    sort(input+1,input+num+1,comp);

    for(int i=1;i<=num;i++){
        if(i==1){
            cout<<input[1];
            continue;
        }
        cout<<" "<<input[i];
    }

    cout<<endl;
    return 0;
}