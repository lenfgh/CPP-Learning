// This is the solution of the https://lexue.bit.edu.cn/mod/programming/history.php?id=468937
// Created by FUGUO on 2024/11/15.
//
#include<iostream>
#include<cstdio>
using namespace std;

int input[1000010];

int main(){

    int n;
    cin >> n;

    for(int i=1;i<=n;i++){
        if(scanf("%d",&input[i])){
            continue;
        } else {
            i-=1;
        }
    }

    int temp=0,temp_start=1,temp_end=1;
    int max_num=0;
    int start = 1;
    int end = 1;

    for(int j=2;j<=n;j++){
        if(input[j]<=input[j-1]) {
            temp_end += 1;
            temp += 1;
        } else {
            if(temp > max_num) {
                start = temp_start;
                end = temp_end;
                temp_start = j;
                temp_end = j;
                max_num = temp;
                temp = 0;
            }
            else {
                temp_start = j;
                temp_end = j;
                temp = 0;
            }
        }
    }
    if(temp > max_num) {
        start = temp_start;
        end = temp_end;
        max_num = temp;
    }

    cout << start << " " << end << endl;
    return 0;
}
