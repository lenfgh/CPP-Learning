// This is the solution of https://lexue.bit.edu.cn/mod/programming/view.php?id=476065
// Created by FUGUO on 2024/12/24.
//
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> P(n, vector<int>(n));
    vector<vector<int>> Q(n, vector<int>(n));

    // Input matrix P
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> P[i][j];
        }
    }

    // Input matrix Q
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> Q[i][j];
        }
    }

    vector<int> dp(1 << n, 0);

    // Iterate over all possible states
    for (int mask = 0; mask < (1 << n); ++mask) {
        int i = __builtin_popcount(mask); // Number of pairs already made
        for (int j = 0; j < n; ++j) {
            if (!(mask & (1 << j))) { // If the j-th female athlete is not yet paired
                int new_mask = mask | (1 << j);
                dp[new_mask] = max(dp[new_mask], dp[mask] + P[i][j] * Q[j][i]);
            }
        }
    }

    // Output the maximum sum of competition advantages
    cout << dp[(1 << n) - 1] << endl;

    return 0;
}