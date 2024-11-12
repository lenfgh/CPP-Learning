// This is the solution of the 【小学】求自守数
// Created by FUGUO on 2024/11/12.
//
#include<iostream>

using namespace std;

int n;

long pow(int x){
    long re = 1;
    for(int i=1;i<=x;i++){
        re*=10;
    }
    return re;
}

int mantissa(long x){
    long temp=x,result=0;
    temp *= temp;
    
    for(int i=0; i<n; i++){
        result += (temp%10)*(pow(i));
        temp /= 10;
    }
    
    return result;
}

int main(){

    cin >> n;
    
    for(long i=0;i<9*pow(n-1);i++){
        int temp = mantissa(pow(n-1)+i);
        if((pow(n-1)+i)==temp){
            cout << pow(n-1) + i << endl;
        }
    }

    return 0;
}