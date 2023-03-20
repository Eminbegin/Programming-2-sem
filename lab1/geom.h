#include <vector>


class Point {
    private:
        double x;
        double y;
    public:
        Point();
        Point(double, double);
        Point(const Point &other);
        Point& operator= (const Point &);
        bool operator== (const Point &) const;
        double angle(const Point &) const;
        double length(const Point &) const;
        void print() const;
        double getX() const;
        double getY() const;
};

class Polyline {
    protected:
        std::vector <Point> points;
    public:
        Polyline(const std::vector <Point> &);
        Polyline(const Polyline &other);
        ~Polyline();
        Polyline& operator= (const Polyline &);
        void print_n(unsigned int) const;
        Point get_n_p(unsigned int) const;
        virtual double perimetr() const;
};

class ClosedPolyline: public Polyline {
    // protected:
    //     std::vector <Point> points;
    public:
        using Polyline::Polyline;
        double perimetr() const override;
        // ClosedPolyline& operator= (const Polyline &);
        // void print_n(unsigned int) const;
        // Point get_n_p(unsigned int) const;       
        // void square() const override;
};

class Polygon {
    protected:
        std::vector <Point> points;
    public:
        Polygon(){}
        Polygon(const std::vector <Point> &);
        Polygon(const Polygon &);
        Polygon& operator= (const Polygon &);
        void print_n(unsigned int) const;
        Point get_n_p(unsigned int) const;
        double perimetr() const;
        virtual double square() const;
};

class Triangle: public Polygon {
    // protected:
    //     std::vector <Point> points;
    public:
        Triangle(){}
        Triangle(const std::vector <Point> &points) :Polygon(points){};
        Triangle(const Polygon & pol) : Polygon(pol){};
        Triangle(const Point &, const Point &, const Point &);
        double square() const override;
        bool right_triangle() const;
        bool isos_triangle() const;
        bool equilateral_triangle() const;
        double height_len(int) const;
        double radius_vpis() const;
        double radius_opis() const;
};

class Trapezoid: public Polygon {
    // protected:
    //     std::vector <Point> points;
    public:
        Trapezoid(){}
        Trapezoid(const std::vector <Point> &);
        Trapezoid(const Point &, const Point &, const Point &, const Point &);
        Trapezoid(const Polygon & pol) : Polygon(pol){};
        double square() const override;
        bool right_trapezoid() const;
        bool isos_trapezoid() const;
        double height_len() const;
};

class Regular_Polygon: public Polygon {
    // protected:
    //     std::vector <Point> points;
    public:
        Regular_Polygon(){}
        Regular_Polygon(std::vector <Point>);
        Regular_Polygon(const Polygon & pol) : Polygon(pol){};
        
};