#include <iostream>  
#include <vector>  
#include <cmath>  
  
using namespace std;  
  
unsigned long long countNumbers(unsigned long long num, int n, bool include_num = false) {  
    if (num == 0) return include_num ? (n > 0 ? 1 : 0) : 0;  
  
    vector<int> digits;  
    while (num > 0) {  
        digits.push_back(num % 10);  
        num /= 10;  
    }  
  
    unsigned long long count = 0;  
    unsigned long long prev = 0;  
    bool leadingZeros = true;  
  
    for (int i = digits.size() - 1; i >= 0; --i) {  
        int digit = digits[i];  
  
        for (int j = 0; j < (leadingZeros ? n + 1 : (digit + 1)); ++j) {  
            if (!leadingZeros || j > 0) {  
                unsigned long long limit = pow(10, digits.size() - i - 1);  
                count += limit * min(n + 1, (i == digits.size() - 1 && !include_num && j == digit) ? digit : (n + 1));  
  
                // ????????? num ?????,??????? num ?????  
                // ?????? j ?? num ????,???????????????  
                // ?? num ??????????(?? include_num ? true)  
            }  
  
            prev = prev * 10 + j;  
            leadingZeros = false;  
        }  
  
        // ?? include_num ? true,????????? num ??(??????????????)  
        // ????????????,?? num ??????????  
        // ??,???????????????,???????????????????  
        // ??? i == 0 ?,???????? num ??(?????????)  
        // ??:????????????????????????????????  
    }  
  
    // ?? include_num ? true,?? num ??????,????????????  
    // ??,?????????????????,? i == 0 ?  
    // ?? num ????????? n,??????????(??????????)  
    // ?? count ???????? num ??(???????????????????????)  
    // ??,???????????? 1  
    // ??,?? num ??????? n,???????? count,?????  
    // ??,???????? include_num ????,??????????????????  
    // ??,???????????????,???? include_num ????????  
  
    // ??,???? count,?????????? num(??????,??? include_num ??,????????????)  
    // ????????? n ?????  
    // ??,???,?????????,? include_num ? true ?,?? num ??????  
    // ?????????,????????????  
  
    // ???????????? include_num ??,????????????  
    // ?????????? include_num ??,??????  
  
    return count;  
} 
int main() {  
    int n;  
    unsigned long long a, b;  
    cin >> n >> a >> b;  
  
    // ?? countNumbers ????????????????????????  
    // ???????? a-1 ? b ???,?? b ?????? a-1 ???(?? a ????????)  
    unsigned long long result = countNumbers(b, n) - countNumbers(a - 1, n);  
  
    // ?? a ??????,?????????(???????????)  
    if (a > 0 && all_of(a.begin(), a.end() - (to_string(a).find_first_not_of('0')),  
                        [n](char c) { return c - '0' <= n; })) {  
        // ??:??? all_of ? begin/end ???????,?? a ??? unsigned long long  
        // ????????????? a ??????  
        bool a_valid = true;  
        unsigned long long temp_a = a;  
        while (temp_a > 0) {  
            if (temp_a % 10 > n) {  
                a_valid = false;  
                break;  
            }  
            temp_a /= 10;  
        }  
        if (a_valid) {  
            result++;  
        }  
    }  
  
    // ??:??? a ????????? countNumbers ??????????  
    // ?? num ?? a-1 ?,????????? n ????,??????????  
    // ??????? a ??????(?????? countNumbers ?????)  
    // ????,??????????????  
  
    cout << result << endl;  
    return 0;  
}