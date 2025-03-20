#include <iostream>

struct Point {
    float x;
    float y;
};

// Function to calculate the midpoint between two points (returns a Point object)
Point calcMidpoint(const Point* p1, const Point* p2) {
    return Point{ (p1->x + p2->x) / 2.0f, (p1->y + p2->y) / 2.0f };
}

int main() {
    // Step 1: Create two points with user input
    Point a, b;
    std::cout << "Enter coordinates for point A (x y): ";
    while (!(std::cin >> a.x >> a.y)) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Invalid input. Enter numeric values for point A (x y): ";
    }

    std::cout << "Enter coordinates for point B (x y): ";
    while (!(std::cin >> b.x >> b.y)) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Invalid input. Enter numeric values for point B (x y): ";
    }

    // Step 2: Call calcMidpoint using pointers to 'a' and 'b'
    Point mid = calcMidpoint(&a, &b);

    // Step 3: Print the midpoint coordinates
    std::cout << "Midpoint is at (" << mid.x << ", " << mid.y << ")" << std::endl;

    return 0;
}
