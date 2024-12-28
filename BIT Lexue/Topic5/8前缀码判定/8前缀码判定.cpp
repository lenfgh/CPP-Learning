// This is the solution of the https://lexue.bit.edu.cn/mod/programming/view.php?id=476068
// Created by FUGUO on 2024/12/25.
//
#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<string> cache;

int main() {
    int n;
    cin >> n;
    bool yes = true;
    for(int i=0;i<n;i++) {
        string input;
        cin >> input;
        if(yes&&i!=0){
            for(auto &word: cache) {
                int existence = -1;
                string large = word.size()>input.size()?word:input;
                string small = word.size()>input.size()?input:word;
                existence = large.find(small);
                if(existence==0) {
                    yes = false;
                    cout << input << endl;
                }
            }
        }
        cache.push_back(input);
    }
    if(yes) cout << "YES" << endl;
    return 0;
}