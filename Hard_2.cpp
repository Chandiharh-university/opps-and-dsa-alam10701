#include <iostream>
#include <cmath>
using namespace std;

class Shape {
public:
    virtual double area() = 0; // Pure virtual function
    virtual double perimeter() = 0; // Pure virtual function
    virtual void displayProperties() {
        cout << "Area: " << area() << endl;
        cout << "Perimeter: " << perimeter() << endl;
    }
};

class Square : public Shape {
private:
    double side;
public:
    Square(double s) : side(s) {}
    double area() override {
        return side * side;
    }
    double perimeter() override {
        return 4 * side;
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
    double perimeter() override {
        return 2 * (length + width);
    }
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() override {
        return M_PI * radius * radius;
    }
    double perimeter() override {
        return 2 * M_PI * radius;
    }
};

int main() {
    Shape* shapes[3];
    shapes[0] = new Square(5);
    shapes[1] = new Rectangle(4, 6);
    shapes[2] = new Circle(3);

    for (int i = 0; i < 3; ++i) {
        shapes[i]->displayProperties();
        delete shapes[i];
    }

    return 0;
}
