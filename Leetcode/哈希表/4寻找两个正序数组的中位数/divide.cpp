//
// Created by FUGUO on 2025/1/31.
//
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> total;
        for(auto x: nums1) {
            total.push_back(x);
        }
        for(auto x: nums2) {
            total.push_back(x);
        }
        int n = total.size();
        sort(total.begin(), total.end());
        if(n%2==0) {
            return (double)(total[(int)(n/2-1)]+total[(int)(n/2)])/2;
        } else {
            return (double)total[(int) (n-1) / 2];
        }
    }
};
