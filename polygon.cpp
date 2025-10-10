#include <iostream>
#include <cmath>
using namespace std;

// Abstract base class
class Polygon {
public:
    virtual double area() const = 0; // Pure virtual function
    virtual const char* name() const = 0; // Pure virtual function
    virtual ~Polygon() {}
};

// Derived class for Rectangle
class Rectangle : public Polygon {
    double height, width;
public:
    Rectangle(double h, double w) : height(h), width(w) {}

    double area() const override {
        return height * width;
    }

    const char* name() const override {
        return "Rectangle";
    }
};

// Derived class for Triangle
class Triangle : public Polygon {
    double height, width;
public:
    Triangle(double h, double w) : height(h), width(w) {}

    double area() const override {
        return 0.5 * height * width;
    }

    const char* name() const override {
        return "Triangle";
    }
};

// Derived class for Square
class Square : public Polygon {
    double side;
public:
    Square(double s) : side(s) {}

    double area() const override {
        return side * side;
    }

    const char* name() const override {
        return "Square";
    }
};

void showDetails(Polygon *p) {
    cout << "It's a " << p->name() << endl;
    cout << "Area: " << p->area() << endl;
}

void showDetailsRtti(Polygon *p) {
    if (dynamic_cast<Rectangle*>(p)) {
        cout << "It's a Rectangle" << endl;
    } else if (dynamic_cast<Triangle*>(p)) {
        cout << "It's a Triangle" << endl;
    } else if (dynamic_cast<Square*>(p)) {
        cout << "It's a Square" << endl;
    }
    cout << "Area: " << p->area() << endl;
}

int main() {
    Rectangle rect(10, 5);
    Triangle tri(10, 5);
    Square sq(5);

    Polygon* shapes[] = { &rect, &tri, &sq };

    cout << "Using name() method:\n";
    for (Polygon* shape : shapes) {
        showDetails(shape);
    }

    cout << "\nUsing RTTI and dynamic_cast:\n";
    for (Polygon* shape : shapes) {
        showDetailsRtti(shape);
    }

    return 0;
}
