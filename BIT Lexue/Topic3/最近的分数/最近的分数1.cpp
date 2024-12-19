#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

int main() {
    int x, y, n;
    cin >> x >> y >> n;

    int best_a = 0, best_b = 1;
    double min_diff = numeric_limits<double>::max();

    for (int b = 1; b <= n; ++b) {
        // 使用 long long 类型避免整数溢出
        long long numerator = static_cast<long long>(x) * b;
        int a = round(static_cast<double>(numerator) / y)-2;
        int up_a = round(static_cast<double>(numerator) / y)+2;
        // 使用 long double 类型提高精度
        while(a<=up_a) {
            long double diff = fabsl(static_cast<long double>(x) / y - static_cast<long double>(a) / b);

            long double difff = fabsl(diff-min_diff);

            if (diff < min_diff || (difff <1e-25 && b < best_b) || (difff<1e-25 && b == best_b && a < best_a)) {
                min_diff = diff;
                best_a = a;
                best_b = b;
            }
            a++;
        }
    }

    cout << best_a << "/" << best_b << endl;
    return 0;
}