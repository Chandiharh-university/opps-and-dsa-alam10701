#include <iostream>
#include <cmath>
using namespace std;

class Shape {
public:
    virtual double area() = 0; // Pure virtual function
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() override {
        return M_PI * radius * radius;
    }
};

class Rectangle : public Shape {
private:
    double length, width;
public:
    Rectangle(double l, double w) : length(l), width(w) {}
    double area() override {
        return length * width;
    }
};

int main() {
    Shape* shapes[2];
    shapes[0] = new Circle(5);
    shapes[1] = new Rectangle(4, 6);

    for (int i = 0; i < 2; ++i) {
        cout << "Area: " << shapes[i]->area() << endl;
    }

    for (int i = 0; i < 2; ++i) {
        delete shapes[i];
    }
    return 0;
}
