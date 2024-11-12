// This is the solution of the 【学长出题】插入排序
// Created by FUGUO on 2024/11/12.
//

#include<iostream>
#include<algorithm>

using namespace std;

int input[35];

int n;

void print(int x){
    cout << input[1];
    for(int i=2;i<=n;i++){
        cout << " " << input[i];
    }
    cout << endl;
    if(x==n){
        cout << "Result: ";
        cout << input[1];
        for(int i=2;i<=n;i++){
            cout << " " << input[i];
        }
        cout << endl;
    }
}

void insert(int x){
    sort(input,input+x+1);
    print(x);
}

int main(){
    cin>>n;

    for(int i=1; i<=n; i++){
        cin >> input[i];
    }

    for(int i=2;i<=n;i++){
        if(input[i] < input[i-1]){
            insert(i);
        }
    }

    return 0;
}