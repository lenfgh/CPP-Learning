#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

struct Circle {
    int x, y, r;
};

double calculateArea(const Circle& circle) {
    return M_PI * circle.r * circle.r;
}

bool isOverlap(const Circle& c1, const Circle& c2) {
    int dx = c1.x + c1.r - c2.x - c2.r;
    int dy = c1.y + c1.r - c2.y - c2.r;
    int distanceSquared = dx * dx + dy * dy;
    int radiusSum = c1.r + c2.r;
    return distanceSquared < radiusSum * radiusSum;
}

double calculateTotalArea(const vector<Circle>& circles) {
    double totalArea = 0.0;
    for (const auto& circle : circles) {
        totalArea += calculateArea(circle);
    }
    // Note: This is a simplified version and does not account for overlapping areas.
    return totalArea;
}

int main() {
    int n;
    cin >> n;
    vector<Circle> circles(n);
    for (int i = 0; i < n; ++i) {
        cin >> circles[i].x >> circles[i].y >> circles[i].r;
    }

    double totalArea = calculateTotalArea(circles);
    cout << fixed << setprecision(3) << totalArea << endl;

    return 0;
}