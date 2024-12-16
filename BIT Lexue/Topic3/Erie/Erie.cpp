// This is the solution of Erie的早餐：【同学出题】梁思源
// Created by FUGUO on 2024/11/4.
//
#include<iostream>
#include<algorithm>
using namespace std;
struct dish{
    int spicy;
    int sweat;
    int good;
}Erie[3005];

inline bool comp(dish x, dish y){
    return x.good > y.good;
}

int main(){
    int p,m,n,num;
    cin>>p>>m>>n;
    num=0;
    for(int i=0;i<p;i++){
        cin>>Erie[num].spicy>>Erie[num].sweat;
        Erie[num].good = Erie[num].sweat - Erie[num].spicy;
        if(Erie[num].spicy>=m||Erie[num].sweat<=n){
            Erie[num] = {0};
            continue;
        }
        num++;
    }

    sort(Erie,Erie+num,comp);

    int tot=1,temp=Erie[0].good,max_num=1;

    for(int i=0;i<num;i++){
        if(temp == Erie[i+1].good + 1){
            tot+=1;
            temp = Erie[i+1].good;
        }
        else if(temp == Erie[num+1].good){
            continue;
        }
        else{
            max_num=max(max_num,tot);
            tot = 1;
            temp = Erie[i+1].good;
            continue;
        }
    }
    max_num = max(max_num,tot);
    cout<<max_num<<endl;
    return 0;
}