#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<utility>
using namespace std;
int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
string reps[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
pair<int,string> Roman_p[] = {
        {1000, "M"},
        {900, "CM"},
        {500, "D"},
        {400, "CD"},
        {100, "C"},
        {90, "XC"},
        {50, "L"},
        {40, "XL"},
        {10, "X"},
        {9, "IX"},
        {5, "V"},
        {4, "IV"},
        {1, "I"},
};

class Solution {
public:
    string intToRoman_1(int num) {
        string ans;
        for(int i=0; i<13; i++) {
            while (num>=values[i]) {
                num -= values[i];
                ans += reps[i];
            }
        }
        return ans;
    }

    string intToRoman_2(int num) {
        string ans;
        for( auto [value, symbol] : Roman_p) {
            while (num>=value) {
                num -= value;
                ans += symbol;
            }
            if (num==0) {
                break;
            }
        }
        return ans;
    }
};