#ifndef ROTATE_HPP
#define ROTATE_HPP
#include "Cube.hpp"

class Rotate {
public:
    static void Rot1(Cube&, int);
    static void Rot1_(Cube&, int);
    static void Rot2(Cube&, int, int, int, int);
    static void Left(Cube&);
    static void Right(Cube&);
    static void Front(Cube&);
    static void Back(Cube&);
    static void Up(Cube&);
    static void Down(Cube&);
    static void Xrot(Cube&);
    static void Yrot(Cube&);
    static void Zrot(Cube&);
    static void Left_(Cube&);
    static void Right_(Cube&);
    static void Front_(Cube&);
    static void Back_(Cube&);
    static void Up_(Cube&);
    static void Down_(Cube&);
};


#endif
