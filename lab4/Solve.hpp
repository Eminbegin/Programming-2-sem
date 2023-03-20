#ifndef SOLVE_H
#define SOLVE_H
#include "Cube.hpp"

class Solve{
    friend class Cube;
public:
    static void solve(Cube&);
    static void clearSolve();
    static void formatSolve();
    static std::string& getSolve();
private:
    static void solveRotate(Cube&);
    static void solveCorners(Cube&);
    static void solveCross(Cube&);
    static void solveEdges(Cube &cube);
    static void solveOLL(Cube&);
    static void solvePLL(Cube &);
    static void sequenceOfTurns(const std::string &, Cube&);
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
    static std::string fullSolve;
    static int rotateCount;
    static int checkBottomLayer(Cube &);
    static void solveEdge1(Cube&);
    static void solveEdge2(Cube &cube);
    static int findPosition(Cube&);
    static int findEdges(Cube&);
    static void solveCase(Cube&, int);
    static int checkOLL(Cube&);
    static void checkTwo(Cube &);
    static void solveCorners1(Cube &);
    static int checkCorners(Cube &);
    static int checkEdges(Cube &);
    static void solveEdges1(Cube &);
};



#endif
