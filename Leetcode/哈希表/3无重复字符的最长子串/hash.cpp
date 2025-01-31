#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> occ;
        int right=-1, ans=0, n=s.size();
        for (int i=0; i<n; i++) {
            if( i!=0) {
                occ.erase(s[i-1]);
            }
            while(right + 1 <n && !occ.count(s[right+1])) {
                occ.insert(s[right+1]);
                right++;
            }
            ans = max(ans, right-i+1);
        }
        return ans;
    }
};