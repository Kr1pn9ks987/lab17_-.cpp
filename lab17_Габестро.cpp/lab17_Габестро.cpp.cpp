// lab17_Габестро.cpp.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>

class Point {
protected:
    double x, y;

public:
    Point(double x = 0, double y = 0) : x(x), y(y) {
        std::cout << "Point created: (" << x << ", " << y << ")\n";
    }

    virtual ~Point() {
        std::cout << "Point destroyed: (" << x << ", " << y << ")\n";
    }

    virtual void print() const {
        std::cout << "Point: (" << x << ", " << y << ")\n";
    }
};

class Circle : public Point {
protected:
    double radius;

public:
    Circle(double x = 0, double y = 0, double r = 1) : Point(x, y), radius(r) {
        std::cout << "Circle created with radius: " << radius << "\n";
    }

    ~Circle() override {
        std::cout << "Circle destroyed with radius: " << radius << "\n";
    }

    double area() const {
        return atan(1.0) * 4;  radius * radius;
    }

    void print() const override {
        std::cout << "Circle: center = (" << x << ", " << y << "), radius = " << radius
            << ", area = " << area() << "\n";
    }
};

class Ring : public Circle {
private:
    double inner_radius;

public:
    Ring(double x = 0, double y = 0, double r1 = 1, double r2 = 0.5)
        : Circle(x, y, r1), inner_radius(r2) {
        std::cout << "Ring created with outer radius: " << radius
            << " and inner radius: " << inner_radius << "\n";
    }

    ~Ring() override {
        std::cout << "Ring destroyed with outer radius: " << radius
            << " and inner radius: " << inner_radius << "\n";
    }

    double area() const {
        return atan(1.0) * 4; (radius * radius - inner_radius * inner_radius);
    }

    void print() const override {
        std::cout << "Ring: center = (" << x << ", " << y << "), outer radius = " << radius
            << ", inner radius = " << inner_radius << ", area = " << area() << "\n";
    }
};

class Ellipse : public Point {
private:
    double semi_major, semi_minor;

public:
    Ellipse(double x = 0, double y = 0, double a = 1, double b = 0.5)
        : Point(x, y), semi_major(a), semi_minor(b) {
        std::cout << "Ellipse created with semi-major axis: " << semi_major
            << " and semi-minor axis: " << semi_minor << "\n";
    }

    ~Ellipse() override {
        std::cout << "Ellipse destroyed with semi-major axis: " << semi_major
            << " and semi-minor axis: " << semi_minor << "\n";
    }

    double area() const {
        return atan(1.0) * 4; semi_major * semi_minor;
    }

    void print() const override {
        std::cout << "Ellipse: center = (" << x << ", " << y << "), semi-major axis = "
            << semi_major << ", semi-minor axis = " << semi_minor
            << ", area = " << area() << "\n";
    }
};

int main() {
    Point p(1, 2);
    p.print();

    Circle c(3, 4, 5);
    c.print();

    Ring r(5, 6, 7, 3);
    r.print();

    Ellipse e(7, 8, 4, 2);
    e.print();

    return 0;
}