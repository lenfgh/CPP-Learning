//
// Created by FUGUO on 2025/2/2.
//
//#include<iostream>
//#include<vector>
//#include<string>
//#include<cmath>
//#include<unordered_set>
//using namespace std;
//int mod = 998244353;
//int N,M;
//vector<vector<int>> dp;
//
//int unique_char(const string s) {
//    unordered_set<char> char_set;
//    for (char x : s) {
//        char_set.insert(x);
//    }
//    return (int) char_set.size();
//}
//
//int evo(int i, int j) {
//    if (dp[i][j]!=-1) return dp[i][j]%mod;
//    dp[i][j] = 25*evo(i-1,j) +
//}
//
//int main() {
//
//    cin >> N >> M;
//    dp.resize(M + 1, vector<int>(N + 1, -1));
//    string S;
//    int val = unique_char(S);
//    dp[0][0] = 1;
//    dp[0][1] = 0;
//    dp[1][0] = 26-val;
//    for (int i=1; i<=M; i++) {
//        for (int j=1; j<=N; j++) {
//            if (i<j) dp[i][j] = 0;
//            if (j==0) dp[i][j] = (int) pow(26-val,i);
//            if (i==0) dp[i][j] = 0;
//        }
//    }
//
//
//    return 0;
//
//}
#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int main() {
    int N, M;
    cin >> N >> M;
    string S;
    cin >> S;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        A[i] = S[i] - 'a'; // Convert characters to integers (0-25)
    }

    // DP state: a tuple representing the LCS lengths at each step
    // Initialize with a tuple of N+1 zeros and count 1
    map<vector<int>, int> dp;
    vector<int> initial(N + 1, 0);
    dp[initial] = 1;

    // Iterate over each character in the new string of length M
    for (int _ = 0; _ < M; ++_) {
        map<vector<int>, int> ndp; // New DP state for the next character
        for (auto& [arr, cnt] : dp) {
            for (int i = 0; i < 26; ++i) { // Try all lowercase letters
                vector<int> narr(N + 1, 0); // New LCS lengths
                for (int j = 0; j < N; ++j) {
                    narr[j + 1] = max(narr[j], arr[j + 1]); // Propagate LCS length
                    if (A[j] == i) { // If characters match, update LCS length
                        narr[j + 1] = max(narr[j + 1], arr[j] + 1);
                    }
                }
                ndp[narr] = (ndp[narr] + cnt) % MOD; // Update count for new state
            }
        }
        dp = ndp; // Move to the next DP state
    }

    // Collect results for each possible LCS length k (0 to N)
    vector<int> ans(N + 1, 0);
    for (auto& [arr, cnt] : dp) {
        ans[arr[N]] = (ans[arr[N]] + cnt) % MOD;
    }

    // Output the results
    for (int i = 0; i <= N; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}