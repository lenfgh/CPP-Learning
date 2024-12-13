// This is the solution provided by claude3.5-sonnet. Actually, it relies on the prompts and your logic.
// If you can describe how the program work and how it works partly, it can give you great response.
// created by FUGUO 11.15.24
//
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool is_self_number(string num_str) {
    // 使用字符串乘法来避免溢出
    string num = num_str;
    string square = "0";
    int length = num_str.length();
    
    // 手动计算平方
    for (char d : num) {
        string temp = "0";
        int digit = d - '0';
        for (int i = 0; i < digit; i++) {
            // 加num到temp
            int carry = 0;
            string t = temp;
            temp = "";
            int j = t.length() - 1, k = num.length() - 1;
            while (j >= 0 || k >= 0 || carry) {
                int sum = carry;
                if (j >= 0) sum += t[j--] - '0';
                if (k >= 0) sum += num[k--] - '0';
                temp = char(sum % 10 + '0') + temp;
                carry = sum / 10;
            }
        }
        // 乘10
        square += "0";
        // 加temp到square
        int carry = 0;
        string t = square;
        square = "";
        int j = t.length() - 1, k = temp.length() - 1;
        while (j >= 0 || k >= 0 || carry) {
            int sum = carry;
            if (j >= 0) sum += t[j--] - '0';
            if (k >= 0) sum += temp[k--] - '0';
            square = char(sum % 10 + '0') + square;
            carry = sum / 10;
        }
    }
    
    // 检查平方数的长度是否足够
    if (square.length() < length) {
        return false;
    }
    
    // 获取平方的后n位
    string square_last_n = square.substr(square.length() - length);
    
    return square_last_n == num_str;
}

vector<string> get_base_self_numbers() {
    // 返回n=1时的自守数列表
    return {"1", "5", "6"};
}

vector<string> find_self_numbers(int n) {
    if (n == 1) {
        return get_base_self_numbers();
    }
    
    // 获取n-1位的自守数
    vector<string> prev_self_numbers = find_self_numbers(n - 1);
    vector<string> results;
    
    // 在n-1位自守数前添加数字(0-9)
    for (const string& prev : prev_self_numbers) {
        for (int d = 0; d < 10; d++) {
            // 跳过前导零            
            string new_num = to_string(d) + prev;
            if (is_self_number(new_num)) {
                results.push_back(new_num);
            }
        }
    }
    
    sort(results.begin(), results.end());
    return results;
}

int main() {
    int n;
    cin >> n;  // 从用户输入获取n
    vector<string> results = find_self_numbers(n);
    for (const string& num : results) {
        if (num.length() == n&& num[0]!='0') {  // 只输出数位为n的结果
            cout << num << endl;
        }
    }
    return 0;
}