//
// Created by FUGUO on 2025/1/31.
//
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution_false {
public:
    bool isMatch(string s, string p) {
        int n1 = s.size();
        int n2 = p.size();
        printf("n1 is %d n2 is %d\n", n1,n2);
        char pre_char;
        char check_char;
        for(int j=0; j<n2; j++) {
            if(p[j]==s[0]||p[j]=='.'){
                pre_char=p[j];
                printf("start at %d",j);
                for (int i = 0; i < n1; i++) {
                    cout << i << ' ' <<s[i] << ' '<< "is processing" << endl;
                    check_char = p[j];
                    if (check_char == '*') {
                        check_char = pre_char;
                        if(check_char==s[i]) {
                            if(i==n1-1) {
                                return true;
                            }
                            continue;
                        } else {
                            j++;
                            check_char = p[j];
                            pre_char = p[j];
                        }
                    } else if (check_char != '.') {
                        pre_char = p[j];
                        check_char = p[j];
                        j++;
//                        printf("j is %d\nn2 is %d\n",j,n2 );
                        if (j >= n2 && i < n1 - 1) {
                            //                    printf("false\n");
                            cout << "return false 1" << endl;
                            return false;
                        }
                    }  // check char value

                    printf("check char is %c\nj is %d\n", check_char, j);

                    if (check_char == '.') {
                        cout << i << "is ok" << endl;
                        j++;
                        if (j >= n2 && i < n1 - 1) {
                            cout << "return false 2" << endl;
                            return false;
                        }
                        continue;
                    }

                    if (s[i] == check_char) {
                        cout << i << "is ok" << endl;
                    } else {
                        cout << "break 3" << endl;
                        break;
                    }
                    if(i==n1-1) {
                        cout << "return true" << endl;
                        return true;
                    }
                } // check if right
            }
        }
        return false;
    }
};
class Solution_right {
public:
    bool isMatch(const std::string s, const std::string p) {
        int m = s.size();
        int n = p.size();
        std::vector<std::vector<bool>> dp(m + 1, std::vector<bool>(n + 1, false));

        // 初始化：空字符串与空模式匹配
        dp[0][0] = true;

        // 处理模式 p 的前缀为 * 的情况
        for (int j = 2; j <= n; j += 2) {
            if (p[j - 1] == '*') {//j-1为实际位置
                dp[0][j] = dp[0][j - 2];
            }
        }

        // 填充 dp 表
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == '*') {
                    // * 表示前面的字符出现零次
                    dp[i][j] = dp[i][j - 2];
                    // * 表示前面的字符出现多次
                    if (p[j - 2] == '.' || p[j - 2] == s[i - 1]) {
                        dp[i][j] = dp[i][j] || dp[i - 1][j];
                    }
                } else if (p[j - 1] == '.' || p[j - 1] == s[i - 1]) {
                    // 当前字符匹配
                    dp[i][j] = dp[i - 1][j - 1];
                }
            }
        }

        return dp[m][n];
    }
};
int main() {
    string s="aa";
    string p="a*";
    Solution_right ans;
    bool match = ans.isMatch(s,p);
    if(match) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    return 0;
}