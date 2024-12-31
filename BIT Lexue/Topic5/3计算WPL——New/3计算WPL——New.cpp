// This is the solution of https://lexue.bit.edu.cn/mod/programming/view.php?id=476064
// Created by FUGUO on 2024/12/28.
//
#include<iostream>
#include<queue>

using namespace std;

priority_queue<int,vector<int>,greater<int>> Haffuman;

int main() {
    int n ;
    cin >> n;
    for(int i=0;i<n;i++) {
        int input;
        cin >> input ;
        Haffuman.push((input));
    }

    int wpl=0;

    while(Haffuman.size()>1) {
        int temp;
        temp = Haffuman.top();
        Haffuman.pop();
        temp += Haffuman.top();
        Haffuman.pop();
        wpl+=temp;
        Haffuman.push(temp);
    }

    cout << "WPL=" << wpl << endl;

    return 0;
}