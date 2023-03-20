#include "geom.h"
#include <iostream>
#include <math.h>
#include <exception>

Point::Point() {
    x = 0;
    y = 0;
}

Point::Point(double xn, double yn) {
    x = xn;
    y = yn;
}

Point::Point(const Point &other) {
    x = other.x;
    y = other.y;
}

Point& Point::operator= (const Point &point) {
    x = point.x;
    y = point.y;
    return *this;
}

bool Point::operator== (const Point &point) const {
    if (x == point.x && y == point.y)
        return true;
    return false;
}

double Point::length(const Point &point2) const {
    return pow(pow(point2.x - x, 2) + pow(point2.y - y, 2), 0.5);
}


void Point::print() const {
    std::cout << "(" << x << ", " << y << ")" << "\n";

}

double Point::getX() const {
    return x;
}

double Point::getY() const {
    return y;
}

double Point::angle(const Point &p0) const {
    double angle = (p0.getY() - y) / (p0.getX() - x);
    return angle;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////

Polyline::Polyline(const std::vector<Point> &npoints){ 
    if (npoints.size() < 2)
        throw std::invalid_argument("not enough points");
    else
        points = npoints;
}

Polyline::Polyline(const Polyline &other):points(other.points) {
}

Polyline::~Polyline() = default;

Polyline& Polyline::operator= (const Polyline &polyline) {
    for (int i = 0; i < polyline.points.size(); i++)
        points.push_back(polyline.points[i]);

    return *this;
}

void Polyline::print_n(unsigned int num) const {
    if (num <= points.size())
        points[num - 1].print();
    else
        throw std::invalid_argument("not enough points");
}

Point Polyline::get_n_p(unsigned int num) const {
    if (num <= points.size())
        return points[num - 1];
    throw std::invalid_argument("not enough points");
}

double Polyline::perimetr() const {
    double result = 0;
    for (int i = 1; i < points.size(); i++)
        result += points[i].length(points[i - 1]);
    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////

double ClosedPolyline::perimetr() const {
    double result = 0;
    for (int i = 1; i < points.size(); i++)
        result += points[i].length(points[i - 1]);
    result += points[0].length(points[points.size() - 1]);
    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////

int clockwise(const Point &p1, const Point &p2, const Point &p3) {
    double check;
    check = (p2.getX() - p1.getX())*(p3.getY() - p2.getY()) - (p3.getX() - p2.getX())*(p2.getY() - p1.getY());
    if (check > 0)
        return 1;
    if (check < 0)
        return -1;
    return 0;
}

bool bulge_check(const std::vector<Point> &npoints) {
    int count = 0;
    for (int i = 1; i < npoints.size() - 1; i++)
        count += clockwise(npoints[i - 1], npoints[i], npoints[i + 1]);
    count += clockwise(npoints[npoints.size() - 1], npoints[0], npoints[1]);
    count += clockwise(npoints[npoints.size() - 2], npoints[npoints.size() - 1], npoints[0]);
    return abs(count) == npoints.size();
}

Polygon::Polygon(const std::vector<Point> &npoints) {
    if (npoints.size() < 3)
        throw std::invalid_argument("not enough points");
    else if (bulge_check(npoints))
        points = npoints;
    else {
        throw std::invalid_argument("is not a polygon");
    }
}

Polygon::Polygon(const Polygon &other) {
    for (int i = 0; i < other.points.size(); i++)
        points.push_back(other.points[i]);
}

Polygon& Polygon::operator= (const Polygon &polygon) {
    for (int i = 0; i < polygon.points.size(); i++)
        points.push_back(polygon.points[i]);
    return *this;
}

void Polygon::print_n(unsigned int num) const {
    if (num <= points.size() and num > 0)
        points[num - 1].print();
    else
        throw std::invalid_argument("not enough points");
}

Point Polygon::get_n_p(unsigned int num) const {
    if (num <= points.size())
        return points[num - 1];
    throw std::invalid_argument("not enough points");
    return Point(0, 0);
}

double Polygon::perimetr() const {
    double result = 0;
    for (int i = 1; i < points.size(); i++)
        result += points[i].length(points[i - 1]);
    result += points[0].length(points[points.size() - 1]);
    return result;
}

double Polygon::square() const {
    double square_value = 0;
    double intermediate_value = 0;
    for (int i = 0; i < points.size() - 1; i++) {
        intermediate_value += points[i].getX() * points[i + 1].getY();
        intermediate_value -= points[i + 1].getX() * points[i].getY();
    }
    intermediate_value += points[points.size() - 1].getX() * points[0].getY();
    intermediate_value -= points[0].getX() * points[points.size() - 1].getY();
    square_value = 0.5 * fabs(intermediate_value);
    return square_value;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////

Triangle::Triangle(const Point &p1, const Point &p2, const Point &p3) {
    points.push_back(p1);
    points.push_back(p2);
    points.push_back(p3);
}

double Triangle::square() const {
    return 0.5*(points[0].getX()*(points[1].getY()-points[2].getX())+points[1].getX()*(points[2].getY()-points[0].getY())+points[2].getX()*(points[0].getY()-points[1].getY()));
}

bool Triangle::right_triangle() const {
    double a, b, c = 0;
    a = pow(points[0].length(points[1]), 2);
    b = pow(points[1].length(points[2]), 2);
    c = pow(points[0].length(points[2]), 2);
    if (a == b + c || a == b - c || a == c - b)
        return true;
    return false;
}

bool Triangle::isos_triangle() const {
    int n = 0;
    double a, b, c;
    a = points[0].length(points[1]);
    b = points[1].length(points[2]);
    c = points[0].length(points[2]);
    if (a == c)
        n += 1;
    if (b == c)
        n += 1;
    if (b == c)
        n += 1;
    if (n == 1)
        return true;
    return false;
}

bool Triangle::equilateral_triangle() const {
    double a, b, c;
    a = points[0].length(points[1]);
    b = points[1].length(points[2]);
    c = points[0].length(points[2]);
    if (a == c && a == b)
        return true;
    return false;
}

double Triangle::height_len(int i) const {
    double h;
    double tsquare = this->square();
    double footing = points[(i - 1) % 3].length(points[(i + 1) % 3]);
    h = 2 * tsquare / footing;
    return h;
}

double Triangle::radius_vpis() const {
    return 2 * this->square() / this->perimetr();
}

double Triangle::radius_opis() const {
    double a, b, c;
    a = points[0].length(points[1]);
    b = points[1].length(points[2]);
    c = points[0].length(points[2]);
    return (a * b * c) / (4 * this->square());
}

////////////////////////////////////////////////////////////////////////////////////////////////////////

bool right_angle_check(const Point &p1, const Point &p2, const Point &p3) {
    double a = pow(p1.length(p2), 2);
    double b = pow(p3.length(p2), 2);
    double c = pow(p1.length(p3), 2);
    return c == a + b;

}

Trapezoid::Trapezoid(const std::vector <Point> &npoints) {
    if (npoints.size() == 4) {
        std::vector<Point> newpoints;
        for (int i = 0; i < 4; i++)
            newpoints.push_back(npoints[i]);
        if (npoints[0].angle(npoints[1]) == npoints[3].angle(npoints[2]) 
            && npoints[1].angle(npoints[2]) != npoints[0].angle(npoints[3])
            && bulge_check(npoints)) {
                points.push_back(npoints[3]);
                points.push_back(npoints[0]);
                points.push_back(npoints[1]);
                points.push_back(npoints[2]);
            }
        else if (npoints[1].angle(npoints[2]) == npoints[0].angle(npoints[3]) 
            && npoints[0].angle(npoints[1]) != npoints[3].angle(npoints[2])
            && bulge_check(npoints)) {
                for (int i = 0; i < 4; i++)
                    points.push_back(npoints[i]);
            }
    }
    else {
        throw std::invalid_argument("is not a trapezoid");
    }
}
Trapezoid::Trapezoid(const Point &p1, const Point &p2, const Point &p3, const Point &p4) {
    std::vector<Point> npoints;
    npoints.push_back(p1);
    npoints.push_back(p2);
    npoints.push_back(p3);
    npoints.push_back(p4);
    if (npoints[0].angle(npoints[1]) == npoints[3].angle(npoints[2]) 
        && npoints[1].angle(npoints[2]) != npoints[0].angle(npoints[3])
        && bulge_check(npoints)) {
            points.push_back(npoints[3]);
            points.push_back(npoints[0]);
            points.push_back(npoints[1]);
            points.push_back(npoints[2]);
        }
    else if (npoints[1].angle(npoints[2]) == npoints[0].angle(npoints[3]) 
        && npoints[0].angle(npoints[1]) != npoints[3].angle(npoints[2])
        && bulge_check(npoints)) {
            for (int i = 0; i < 4; i++)
                points.push_back(npoints[i]);
        }
    else {
        throw std::invalid_argument("is not a trapezoid");
    }
}

double Trapezoid::square() const{
    return Triangle(points[0], points[1], points[2]).square() + Triangle(points[0], points[2], points[3]).square();
}

bool Trapezoid::right_trapezoid() const {
    if    (right_angle_check(points[0], points[1], points[2]) 
        || right_angle_check(points[0], points[1], points[2])
        || right_angle_check(points[0], points[1], points[2])
        || right_angle_check(points[0], points[1], points[2]))
        return true;
    return false;
}

bool Trapezoid::isos_trapezoid() const {
    if (points[0].length(points[1]) == points[2].length(points[3]))
        return true;
    return false;
}

double Trapezoid::height_len() const {
    return 2 * this->square() / (points[0].length(points[3]) + points[1].length(points[2]));
}

////////////////////////////////////////////////////////////////////////////////////////////////////////

double cos_angle(const Point &p1, const Point &p2, const Point p3) {
    double a = (p1.getX() - p2.getX()) * (p3.getX() - p2.getX()) + (p1.getY() - p2.getY()) * (p3.getY() - p2.getY());
    return a / (p1.length(p2) * p3.length(p2));
}
Regular_Polygon::Regular_Polygon(std::vector<Point> npoints) {//
    int n = npoints.size();
    bool check = true;
    double a = npoints[0].length(npoints[1]);
    double b = cos_angle(npoints[n - 1], npoints[0], npoints[1]);
    if (a != npoints[n - 1].length(npoints[0]) || b != cos_angle(npoints[n - 2], npoints[n - 1], npoints[0]))
        check = false;
    for (int i = 1; i < n - 1; i ++) {
        if (npoints[i].length(npoints[i + 1]) != a || !check) {
            check = false;
            break;
        }
        if (b != cos_angle(npoints[i - 1], npoints[i], npoints[i + 1]) || !check) {
            check = false;
            break;
        }
    }
    if (check)
        for (int i = 0; i < n; i++)
            points.push_back(npoints[i]);
    else
        throw std::invalid_argument("is not a regular polygon");
}