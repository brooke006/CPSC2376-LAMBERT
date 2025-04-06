#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <sstream>
#include <iomanip>

const double PI = 3.141592653589793; // Use PI constant for area calculation

// Define base Shape class with pure virtual getArea
class Shape {
public:
    virtual ~Shape() = default;
    virtual double getArea() const = 0;
};

// Rectangle with width and height
class Rectangle : public Shape {
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double getArea() const override {
        return width * height;
    }
private:
    double width;
    double height;
};

// Circle with radius
class Circle : public Shape {
public:
    Circle(double r) : radius(r) {}
    double getArea() const override {
        return PI * radius * radius;
    }
private:
    double radius;
};

// Prints areas of all shapes
void printAllAreas(const std::vector<std::unique_ptr<Shape>>& shapes) {
    std::cout << std::fixed << std::setprecision(4);
    for (const auto& shape : shapes) {
        std::cout << "Area: " << shape->getArea() << '\n';
    }
}

// Reads a line and returns the corresponding shape
std::unique_ptr<Shape> createShapeFromLine(const std::string& line) {
    std::istringstream iss(line);
    std::string type;
    iss >> type;

    if (type == "rectangle") {
        double w, h;
        if (iss >> w >> h && w > 0 && h > 0) {
            return std::make_unique<Rectangle>(w, h); // use make_unique
        }
    }
    else if (type == "circle") {
        double r;
        if (iss >> r && r > 0) {
            return std::make_unique<Circle>(r); // use make_unique
        }
    }

    return nullptr; // invalid shape input
}

// Optional: prints total count and combined area
void printSummary(const std::vector<std::unique_ptr<Shape>>& shapes) {
    std::cout << "\nSummary:\n";
    std::cout << "Total shapes: " << shapes.size() << '\n';

    double totalArea = 0;
    for (const auto& shape : shapes) {
        totalArea += shape->getArea();
    }

    std::cout << "Combined area: " << std::fixed << std::setprecision(4) << totalArea << '\n';
}

int main() {
    std::ifstream file("shapes.txt"); // read input from file
    if (!file) {
        std::cerr << "Error: Could not open shapes.txt\n";
        return 1;
    }

    std::vector<std::unique_ptr<Shape>> shapes; // vector of unique_ptr to Shape
    std::string line;
    int lineNum = 0;

    while (std::getline(file, line)) {
        ++lineNum;
        auto shape = createShapeFromLine(line);
        if (shape) {
            shapes.push_back(std::move(shape)); // transfer ownership with std::move
        }
        else {
            std::cerr << "Warning: Skipping invalid input on line " << lineNum << ": " << line << '\n';
        }
    }

    if (shapes.empty()) {
        std::cout << "No valid shapes loaded.\n";
        return 0;
    }

    std::cout << "\n--- Calculated Areas ---\n";
    printAllAreas(shapes); // print areas
    printSummary(shapes);  // print summary

    return 0;
}
