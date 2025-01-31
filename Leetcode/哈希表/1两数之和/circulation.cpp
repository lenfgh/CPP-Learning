#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                if(nums[i]+nums[j]==target) {
                    return {i,j};
                }
            }
        }
        return {};
    }
};

int main() {
    Solution solution;
    vector<int> nums;
    int target, n, num;
    
    // 输入数组大小
    cout << "请输入数组大小: ";
    cin >> n;
    
    // 输入数组元素
    cout << "请输入" << n << "个数组元素: ";
    for(int i = 0; i < n; i++) {
        cin >> num;
        nums.push_back(num);
    }
    
    // 输入目标值
    cout << "请输入目标值: ";
    cin >> target;
    
    // 计算结果并输出
    vector<int> result = solution.twoSum(nums, target);
    if(!result.empty()) {
        cout << "结果: [" << result[0] << "," << result[1] << "]" << endl;
    } else {
        cout << "未找到符合条件的两个数" << endl;
    }
    
    return 0;
}
