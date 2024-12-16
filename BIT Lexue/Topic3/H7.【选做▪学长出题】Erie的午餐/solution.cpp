// This is the solution of the https://lexue.bit.edu.cn/mod/programming/view.php?id=468919
// Created by FUGUO on 2024/11/15.
//
#include<iostream>
#include<algorithm>

using namespace std;

struct day{
    int index,val;
}ram[35];

bool comp(day x, day y){
    return x.val < y.val;
}

int count(int* x, int n){
    int sum=0;
    for(int i=1;i<n;i++){
        int temp=0;
        for(int j=n;j>i;j--){
            if(*(x+j) < *(x+i)){
                temp += 1;
            }
        }
        sum += temp;
    }
    return sum;
}

int main(){
    int n;
    cin >> n;

    for(int i=1;i<=n;i++){
        int num;
        int tempa[5010];
        cin >> num;
        for(int j=1;j<=num;j++){
            cin >> tempa[j];
        }
        ram[i].index = i;
        ram[i].val = count(tempa,num);
    }

    sort(ram+1,ram+n+1,comp); // 修改这里，确保排序范围正确

    cout << ram[1].index << " " << ram[1].val << endl;
    return 0;
}
