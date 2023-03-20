#ifndef CUBE_HPP
#define CUBE_HPP
#include <iostream>
#include "vector"
class Cube {
    friend class Solve;
    friend class Rotate;

public:
    Cube();
    friend std::ostream& operator << (std::ostream &, const Cube &);
    friend Cube& operator >> (std::istream &, Cube &);
    void sequenceOfTurns(const std::string&);
    void scramble();
private:
    enum Colors { white , yellow, red, green, orange, blue};
    Colors side[6][3][3]{};
};
#endif