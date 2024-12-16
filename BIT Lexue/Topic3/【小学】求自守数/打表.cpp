// This is the result of this problem. And I derive this result by python using Cursor.
// created by FUGUO 11.14.24
//
#include<iostream>
using namespace std;

long long self_numbers[] = {
    1, 5, 6, 25, 76, 376, 625, 9376, 90625, 109376, 
    890625, 2890625, 7109376, 12890625, 87109376, 212890625, 
    787109376, 1787109376, 8212890625, 18212890625, 81787109376, 
    918212890625, 9918212890625, 40081787109376, 59918212890625, 
    259918212890625, 740081787109376, 3740081787109376, 
    6259918212890625, 43740081787109376, 56259918212890625, 
    256259918212890625, 743740081787109376, 
    2256259918212890625, 7743740081787109376, 
    92256259918212890625
};

int main() {
    int n;
    cin >> n;
    
    int size = sizeof(self_numbers) / sizeof(self_numbers[0]);
    for (int i = 0; i < size; i++) {
        long long num = self_numbers[i];
        if (to_string(num).length() == n) {
            cout << num << endl;
        }
    }
    
    return 0;
}

