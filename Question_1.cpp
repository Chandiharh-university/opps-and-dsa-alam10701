#include <iostream>
using namespace std;


class Shape {
public:

    int area(int side) {
        cout << "Area of Square: ";
        return side * side;
    }


    int area(int length, int breadth) {
        cout << "Area of Rectangle: ";
        return length * breadth;
    }


    virtual void display() {
        cout << "This is a shape." << endl;
    }
};

class Circle : public Shape {
public:

    double area(double radius) {
        cout << "Area of Circle: ";
        return 3.14 * radius * radius;
    }


    void display() override {
        cout << "This is a circle." << endl;
    }
};

int main() {
    Shape shape;
    Circle circle;


    int side, length, breadth;
    double radius;

    
    cout << "Enter the side of the square: ";
    cin >> side;
    cout << "Enter the length and breadth of the rectangle: ";
    cin >> length >> breadth;
    cout << "Enter the radius of the circle: ";
    cin >> radius;

    
    cout << shape.area(side) << endl;
    cout << shape.area(length, breadth) << endl;
    cout << circle.area(radius) << endl;

    
    shape.display();
    circle.display();

    return 0;
}
