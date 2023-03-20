/* #include "point.cpp"
#include "polylines.cpp"
#include "trapezoid.cpp"
#include "triangle.cpp"
#include "polygon.cpp" */
#include "geom.cpp"

void check_Point(){
    Point poi1;
    poi1.print();
    Point poi2 = Point(3.0, 4.0);
    Point poi3 = poi1;
    poi2.print();
    std::cout << poi3.getX() << " " << poi3.getY() << "\n";
}

void check_Polyline(){
    Point poi1;
    Point poi2 = Point(0, 4);
    Point poi3 = Point(3, 4);
    std::vector <Point> ppp;
    std::vector <Point> qqq;
    ppp.push_back(poi1);
    ppp.push_back(poi2);
    ppp.push_back(poi3);
    // Polyline pollll = Polyline(qqq); //
    Polyline poly1 = Polyline(ppp);
    Polyline poly2 = poly1;
    poly2.print_n(2);
    Point end = poly2.get_n_p(3);
    double per = poly1.perimetr();
    std::cout << per << "\n";
}

void check_ClosedPolyline(){
    Point poi1;
    Point poi2 = Point(0, 4);
    Point poi3 = Point(3, 4);
    std::vector <Point> ppp;
    std::vector <Point> qqq;
    ppp.push_back(poi1);
    ppp.push_back(poi2);
    ppp.push_back(poi3);
    ClosedPolyline poly1 = ClosedPolyline(ppp);
    ClosedPolyline poly2 = poly1; 
    poly2.print_n(1);
    // Polygon pool = Polygon(qqq); //
    std::cout << poly2.perimetr() << "\n";
}

void check_Polygon(){
    Point poi1;
    Point poi2 = Point(0, 4);
    Point poi3 = Point(3, 4);
    std::vector <Point> ppp;
    ppp.push_back(poi1);
    ppp.push_back(poi2);
    ppp.push_back(poi3);
    Polygon poly1 = Polygon(ppp);
    poly1.print_n(2);
    std::cout << poly1.perimetr() << "\n";   
    std::cout << poly1.square() << "\n";   
}

void check_Triangle(){
    Point poi1 = Point(0, 0);
    Point poi2 = Point(0, 8);
    Point poi3 = Point(6, 8);
    std::vector <Point> ppp;
    
    ppp.push_back(poi1);
    ppp.push_back(poi2);
    ppp.push_back(poi3);
    Triangle triug2 = Triangle(poi1, poi2, poi3);
    // Triangle triug2 = Triangle(ppp);
    triug2.print_n(2);
    triug2.print_n(1);
    Triangle tri = triug2;
    // std::cout << triug2.perimetr() << "\n";   
    // std::cout << triug2.square() << "\n";   
    // std::cout << tri.height_len(5) << "\n";
    // std::cout << triug2.right_triangle() << " " << triug2.equilateral_triangle() << " " << triug2.isos_triangle() << "\n";
}

void check_Trapezoid(){
    Point poi0 = Point(0, 0);
    Point poi1 = Point(3, 3);
    Point poi2 = Point(6, 3);
    Point poi3 = Point(9, 0);
    std::vector<Point> ppp;
    ppp.push_back(poi0);
    ppp.push_back(poi1);
    ppp.push_back(poi2);
    ppp.push_back(poi3);
    Trapezoid trap = Trapezoid(ppp);
    // Trapezoid trap = Trapezoid(poi1, poi3, poi0, poi2);
    trap.print_n(4);
    std::cout << trap.square() << "\n";
    std::cout << trap.height_len() << "\n";
}
int main() {
    try {
        // check_Point();
        // check_Polyline();
        // check_ClosedPolyline();
        // check_Polygon();
        // check_Triangle();
        // check_Trapezoid();
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}