#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

struct Circle {
    double x, y, r;
};

double calculateArea(const Circle& c) {
    return M_PI * c.r * c.r;
}

int main() {
    int t, n;
    cin >> t >> n;

    Circle circles[n];
    for (int i = 0; i < n; ++i) {
        cin >> circles[i].x >> circles[i].y >> circles[i].r;
    }

    double totalArea = 0;
    for (int i = 0; i < n; ++i) {
        totalArea += calculateArea(circles[i]);
    }

    cout << fixed << setprecision(2) << totalArea << endl;

    return 0;
}