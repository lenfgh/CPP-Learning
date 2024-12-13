// This is the solution of https://lexue.bit.edu.cn/mod/programming/history.php?id=468917
// created by FUGUOHAO 11.14.24
//
#include<iostream>
using namespace std;

int counter[11]={0};

void count(int x){
    counter[x]+=1;
};

int remain(){
    int temp=0; 
    for(int i=0;i<=9;i++){
        temp+=counter[i]*i;
    }
    return temp%9;
};

void del(int x){
    if(x==0){
        return;
    }
    if(counter[x]!=0){
        counter[x]-=1;
        return;
    }
    else{
        for(int i=x/2;i>=1;i--){
            if(counter[i]!=0&&counter[x-i]!=0){
                counter[i]-=1;
                counter[x-i]-=1;
                return;
            }
        }
    }
}

int main(){
    int n;
    cin >> n;

    for(int i=0;i<n;i++){
        int temp;
        cin >> temp;
        count(temp);
    }

    del(remain());

    for(int i=9;i>=0;i--){
        for(int j=1;j<=counter[i];j++){
            cout << i;
        }
    }
    cout << endl;
    return 0;
}

