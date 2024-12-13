// This is the solution of the 【小学】角谷猜想（学长出题）
// Created by FUGUO on 2024/11/4.
//
#include<stdio.h>
int even_print(int x){
    printf("%d/2=%d\n",x,x/2);
    return x/2;
}

int odd_print(int x){
    printf("%d*3+1=%d\n",x,x*3+1);
    return x*3+1;
}

int main(){
    int n,x;
    if(1!=scanf("%d",&n)) return -1;
    x = n;

    for(int i=1;(x!=1)&&(i<=20);i++){
        if(x%2==0){
            x = even_print(x);
        }
        else {
            x = odd_print(x);
        }
    }
    return 0;
}