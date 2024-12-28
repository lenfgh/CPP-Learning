// This is the solution of https://lexue.bit.edu.cn/mod/programming/result.php?id=476066
// Created by FUGUO on 2024/12/24.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int c, n;
    cin >> c >> n;

    vector<int> weights(n);
    for (int i = 0; i < n; ++i) {
        cin >> weights[i];
    }

    vector<int> dp(c + 1, 0);
    vector<vector<int>> solution(c + 1);

    for (int i = 0; i < n; ++i) {
        for (int j = c; j >= weights[i]; --j) {
            if (dp[j - weights[i]] + weights[i] > dp[j]) {
                dp[j] = dp[j - weights[i]] + weights[i];
                solution[j] = solution[j - weights[i]];
                solution[j].push_back(i + 1);
            }
        }
    }

    int max_weight = dp[c];
    cout << max_weight << endl;
    for (int i : solution[c]) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
