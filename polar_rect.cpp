#include <iostream>
#include <cmath>

class Rectangle;

class Polar {
private:
    double radius;
    double angle;  // Angle in radians

public:
    Polar() : radius(0), angle(0) {}
    Polar(double r, double a) : radius(r), angle(a) {}

    // Conversion routine from Rectangle to Polar
    Polar(const Rectangle& rect);

    void display() const {
        std::cout << "Polar Coordinates: (Radius = " << radius << ", Angle = " << angle << " radians)" << std::endl;
    }

    double getRadius() const { return radius; }
    double getAngle() const { return angle; }
};

class Rectangle {
private:
    double x;
    double y;

public:
    Rectangle() : x(0), y(0) {}
    Rectangle(double xCoord, double yCoord) : x(xCoord), y(yCoord) {}

    // Conversion routine from Polar to Rectangle
    Rectangle(const Polar& polar) {
        x = polar.getRadius() * cos(polar.getAngle());
        y = polar.getRadius() * sin(polar.getAngle());
    }

    void display() const {
        std::cout << "Rectangular Coordinates: (x = " << x << ", y = " << y << ")" << std::endl;
    }

    double getX() const { return x; }
    double getY() const { return y; }
};

// Implementing Polar's conversion constructor
Polar::Polar(const Rectangle& rect) {
    radius = sqrt(rect.getX() * rect.getX() + rect.getY() * rect.getY());
    angle = atan2(rect.getY(), rect.getX());
}

int main() {
    // Rectangular coordinates
    Rectangle rect(3, 4);
    rect.display();

    // Convert Rectangle to Polar
    Polar polar(rect);
    polar.display();

    // Polar coordinates
    Polar polar2(5, M_PI / 4);
    polar2.display();

    // Convert Polar to Rectangle
    Rectangle rect2(polar2);
    rect2.display();

    return 0;
}
