// This is the solution of the https://lexue.bit.edu.cn/mod/programming/result.php?id=468923
// Created by FUGUO on 2024/11/21.
//
#include<iostream>
using namespace std;

long long step[11][11][11];
long long dp(int i,int j,int k){
    if(i<0||j<0||k<0){
        return 0;
    }
    if(step[i][j][k]!=0)
        return step[i][j][k];
    if(i > 0 && step[i-1][j][k]==0)
        step[i-1][j][k]=dp(i-1,j,k);
    if(j > 0 && step[i][j-1][k]==0)
        step[i][j-1][k]=dp(i,j-1,k);
    if(k > 0 && step[i][j][k-1]==0)
        step[i][j][k-1]=dp(i,j,k-1);
    step[i][j][k]=step[i-1][j][k]+step[i][j-1][k]+step[i][j][k-1];
    return step[i][j][k];
};

int main(){
    int x,y,z;
    cin>>x>>y>>z;
    for(int i=0;i<=10;i++){
        step[i][0][0]=1;
        step[0][i][0]=1;
        step[0][0][i]=1;
    }
    cout<<dp(x,y,z)<<endl;
    return 0;
}
