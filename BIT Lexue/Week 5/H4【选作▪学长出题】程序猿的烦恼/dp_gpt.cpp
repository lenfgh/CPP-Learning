#include<iostream>
using namespace std;

long long step[13][13][13] = {0}; // 初始化数组

long long dp(int i, int j, int k) {
    if (i < 0 || j < 0 || k < 0) {
        return 0;
    }
    if(i==0&&j==0&&k==0){
        step[0][0][0]=1;
        return 1;
    }   
    if(i==0&&j==0){
        step[0][0][k]=1;
        return 1;
    }
    if(j==0&&k==0){
        step[i][0][0]=1;
        return 1;
    }
    if(k==0&&i==0){
        step[0][j][0]=1;
        return 1;
    }
    if (step[i][j][k] != 0) {
        return step[i][j][k];
    }
    if (i > 0 && step[i-1][j][k] == 0) {
        step[i-1][j][k] = dp(i-1, j, k);
    }
    if (j > 0 && step[i][j-1][k] == 0) {
        step[i][j-1][k] = dp(i, j-1, k);
    }
    if (k > 0 && step[i][j][k-1] == 0) {
        step[i][j][k-1] = dp(i, j, k-1);
    }
    step[i][j][k] = (i > 0 ? step[i-1][j][k] : 0) + (j > 0 ? step[i][j-1][k] : 0) + (k > 0 ? step[i][j][k-1] : 0);
    return step[i][j][k];
}

int main() {
    int x, y, z;
    cin >> x >> y >> z;
    cout << dp(x, y, z) << endl;
    return 0;
}
