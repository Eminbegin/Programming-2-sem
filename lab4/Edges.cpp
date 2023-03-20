#include "Cube.hpp"
#include "Solve.hpp"

void Solve::solveEdges(Cube &cube) {
    int count = 0;
    while (!(cube.side[2][1][0] == Cube::red && cube.side[2][1][2] == Cube::red &&
             cube.side[3][1][0] == Cube::green && cube.side[3][1][2] == Cube::green &&
             cube.side[4][1][0] == Cube::orange && cube.side[4][1][2] == Cube::orange &&
             cube.side[5][1][0] == Cube::blue && cube.side[5][1][2] == Cube::blue)) {
        solveEdge2(cube);
        ++count;
        if (count > 20)
            throw std::logic_error("invalid input");

    }
}

void Solve::solveEdge2(Cube &cube) {
    if (cube.side[1][0][1] != Cube::yellow && cube.side[4][0][1] != Cube::yellow) {
        if (cube.side[1][0][1] == Cube::red) {
            if (cube.side[4][0][1] == Cube::green)
                cube.sequenceOfTurns("UrururURUR");
            else if (cube.side[4][0][1] == Cube::blue)
                cube.sequenceOfTurns("BUBUBubub");
        }
        else if (cube.side[1][0][1] == Cube::green) {
            if (cube.side[4][0][1] == Cube::orange)
                cube.sequenceOfTurns("bububUBUB");
            else if (cube.side[4][0][1] == Cube::red)
                cube.sequenceOfTurns("UUFUFUFufuf");
        }
        else if (cube.side[1][0][1] == Cube::orange) {
            if (cube.side[4][0][1] == Cube::blue)
                cube.sequenceOfTurns("ulululULUL");
            else if (cube.side[4][0][1] == Cube::green)
                cube.sequenceOfTurns("bububUBUB");
        }
        else if (cube.side[1][0][1] == Cube::blue) {
            if (cube.side[4][0][1] == Cube::red)
                cube.sequenceOfTurns("UUfufufUFUF");
            else if (cube.side[4][0][1] == Cube::orange)
                cube.sequenceOfTurns("lululULUL");
        }
    }

    else if (cube.side[1][1][2] != Cube::yellow && cube.side[3][0][1] != Cube::yellow) {
        if (cube.side[1][1][2] == Cube::red) {
            if (cube.side[3][0][1] == Cube::green)
                cube.sequenceOfTurns("rururURUR");
            else if (cube.side[3][0][1] == Cube::blue)
                cube.sequenceOfTurns("UULULULulul");
        }
        else if (cube.side[1][1][2] == Cube::green) {
            if (cube.side[3][0][1] == Cube::orange)
                cube.sequenceOfTurns("ubububUBUB");
            else if (cube.side[3][0][1] == Cube::red)
                cube.sequenceOfTurns("UFUFUFufuf");
        }
        else if (cube.side[1][1][2] == Cube::orange) {
            if (cube.side[3][0][1] == Cube::blue)
                cube.sequenceOfTurns("UUlululULUL");
            else if (cube.side[3][0][1] == Cube::green)
                cube.sequenceOfTurns("RURURurur");
        }
        else if (cube.side[1][1][2] == Cube::blue) {
            if (cube.side[3][0][1] == Cube::red)
                cube.sequenceOfTurns("UfufufUFUF");
            else if (cube.side[3][0][1] == Cube::orange)
                cube.sequenceOfTurns("uBUBUBubub");
        }
    }
    else if (cube.side[1][2][1] != Cube::yellow && cube.side[2][0][1] != Cube::yellow) {
        if (cube.side[1][2][1] == Cube::red) {
            if (cube.side[2][0][1] == Cube::green)
                cube.sequenceOfTurns("urururURUR");
            else if (cube.side[2][0][1] == Cube::blue)
                cube.sequenceOfTurns("ULULULulul");
        }
        else if (cube.side[1][2][1] == Cube::green) {
            if (cube.side[2][0][1] == Cube::orange)
                cube.sequenceOfTurns("UUbububUBUB");
            else if (cube.side[2][0][1] == Cube::red)
                cube.sequenceOfTurns("FUFUFufuf");
        }
        else if (cube.side[1][2][1] == Cube::orange) {
            if (cube.side[2][0][1] == Cube::blue)
                cube.sequenceOfTurns("UlululULUL");
            else if (cube.side[2][0][1] == Cube::green)
                cube.sequenceOfTurns("uRURURurur");
        }
        else if (cube.side[1][2][1] == Cube::blue) {
            if (cube.side[2][0][1] == Cube::red)
                cube.sequenceOfTurns("fufufUFUF");
            else if (cube.side[2][0][1] == Cube::orange)
                cube.sequenceOfTurns("UUBUBUBubub");
        }
    }
    else if (cube.side[1][1][0] != Cube::yellow && cube.side[5][0][1] != Cube::yellow) {
        if (cube.side[1][1][0] == Cube::red) {
            if (cube.side[5][0][1] == Cube::green)
                cube.sequenceOfTurns("UUrururURUR");
            else if (cube.side[5][0][1] == Cube::blue)
                cube.sequenceOfTurns("LULULulul");
        }
        else if (cube.side[1][1][0] == Cube::green) {
            if (cube.side[5][0][1] == Cube::orange)
                cube.sequenceOfTurns("UbububUBUB");
            else if (cube.side[5][0][1] == Cube::red)
                cube.sequenceOfTurns("uFUFUFufuf");
        }
        else if (cube.side[1][1][0] == Cube::orange) {
            if (cube.side[5][0][1] == Cube::blue)
                cube.sequenceOfTurns("lululULUL");
            else if (cube.side[5][0][1] == Cube::green)
                cube.sequenceOfTurns("UURURURurur");
        }
        else if (cube.side[1][1][0] == Cube::blue) {
            if (cube.side[5][0][1] == Cube::red)
                cube.sequenceOfTurns("ufufufUFUF");
            else if (cube.side[5][0][1] == Cube::orange)
                cube.sequenceOfTurns("UBUBUBubub");
        }
    }
    else if (cube.side[2][1][0] != Cube::red || cube.side[5][1][2] != Cube::blue)
        cube.sequenceOfTurns("LULULulul");
    else if (cube.side[2][1][2] != Cube::red || cube.side[3][1][0] != Cube::green)
        cube.sequenceOfTurns("FUFUFufuf");
    else if (cube.side[3][1][2] != Cube::green || cube.side[4][1][0] != Cube::orange)
        cube.sequenceOfTurns("RURURurur");
    else if (cube.side[4][1][2] != Cube::orange || cube.side[5][1][0] != Cube::blue)
        cube.sequenceOfTurns("BUBUBubub");
}