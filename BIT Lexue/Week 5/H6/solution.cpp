// This is the solution of https://lexue.bit.edu.cn/mod/programming/view.php?id=468910
// Created by FUGUO on 2024/11/21.
//
#include<iostream>
using namespace std;

long long mcommonFactor(long long a,long long b){
    long long x,y,c;
    if(a<b){
        x=b;
        y=a;
    }
    else{
        x=a;
        y=b;
    }
    c = x%y;
    while(c!=0){
        x=y;
        y=c;
        c=x%y;
    }
    return y;
};

int main(){
    int n;
    cin>>n;
    long long a[30],b[30];
    long long temp1=1,temp2=1;
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
    }
    for(int i=0;i<n;i++){
        long long c;
        if (a[i] == 0 || b[i] == 0) {
            cout << 0 << endl;
            return 1;
        }
        temp1 *= a[i];
        temp2 *= b[i];
        c = mcommonFactor(temp1,temp2);
        temp1 /= c;
        temp2 /= c;
    }
    if(temp2!=1){
        cout<<temp1<<"/"<<temp2<<endl;
    }
    else{
        cout<<temp1<<endl;
    }
    return 0;
}
