#include<iostream>
struct Point {
    public:
        int x, y;
    public:
        // Constructor that initializes x and y
        Point(int a, int b) : x(a), y(b) {}

        // Copy constructor that creates a deep copy of another Point object
        Point(const Point &p) {
            this->x = p.x;
            this->y = p.y;
        }
};

int main() {
    // Create a Point object p1 with coordinates (10, 20)
    Point p1 = Point(10, 20);

    // Create a Point object p2 as a copy of p1
    Point p2 = p1;

    std::cout << p2.x << p2.y;
    return 0;
}