#include "Solve.hpp"
#include "Cube.hpp"

void Solve::solveRotate(Cube& cube) {
    fullSolve.clear();
    int checkpos = 0;
    for (int i = 0 ; i < 6; ++i)
        checkpos += (cube.side[i][1][1] == i ? 0 : 1);
    if (checkpos != 0) {
        if (cube.side[1][1][1] == 0)
            cube.sequenceOfTurns("xx");
        else if (cube.side[2][1][1] == 0)
            cube.sequenceOfTurns("X");
        else if (cube.side[3][1][1] == 0)
            cube.sequenceOfTurns("z");
        else if (cube.side[4][1][1] == 0)
            cube.sequenceOfTurns("x");
        else if (cube.side[5][1][1] == 0)
            cube.sequenceOfTurns("Z");
        if (cube.side[3][1][1] == 2)
            cube.sequenceOfTurns("y");
        else if (cube.side[5][1][1] == 2)
            cube.sequenceOfTurns("Y");
        else if (cube.side[4][1][1] == 2)
            cube.sequenceOfTurns("yy");
        checkpos = 0;
        for (int i = 0 ; i < 6; ++i)
            checkpos += (cube.side[i][1][1] == i ? 0 : 1);
        if (checkpos != 0) {
            throw std::logic_error("invalid input");
        }
    }
}
