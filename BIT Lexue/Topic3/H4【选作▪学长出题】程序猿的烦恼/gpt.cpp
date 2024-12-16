#include <iostream>
using namespace std;

// Function to calculate factorial
long long factorial(int n) {
    long long result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

// Function to calculate the number of unique paths
long long uniquePaths(int x, int y, int z) {
    return factorial(x + y + z) / (factorial(x) * factorial(y) * factorial(z));
}

int main() {
    int x, y, z;
    cin >> x >> y >> z;

    if (x < 10 && y < 10 && z < 10 && x > 0 && y > 0 && z > 0) {
        cout << uniquePaths(x, y, z) << endl;
    } else {
        cout << "Coordinates should be positive integers less than 10." << endl;
    }

    return 0;
}