#include "Solve.hpp"
#include "Cube.hpp"

void Solve::solvePLL(Cube &cube) {
    int count = 0;
    checkTwo(cube);
    while (!checkCorners(cube)) {
        ++count;
        solveCorners1(cube);
        checkTwo(cube);
        if (count > 10)
            throw std::logic_error("invalid input");
    }
    count = 0;
    while (!checkEdges(cube)) {
        ++count;
        solveEdges1(cube);
        if (count > 40)
            throw std::logic_error("invalid input");
    }
}

void Solve::checkTwo(Cube &cube) {
    while (cube.side[5][0][2] != Cube::blue || cube.side[2][0][0] != Cube::red)
        cube.sequenceOfTurns("U");
}

void Solve::solveEdges1(Cube &cube) {
    if (cube.side[2][0][1] == Cube::blue && cube.side[3][0][1] == Cube::red && cube.side[4][0][1] == Cube::orange && cube.side[5][0][1] == Cube::green)
        cube.sequenceOfTurns("RRURUrururUr");
    else if (cube.side[2][0][1] == Cube::green && cube.side[3][0][1] == Cube::blue && cube.side[4][0][1] == Cube::orange && cube.side[5][0][1] == Cube::red)
        cube.sequenceOfTurns("RuRURURuruRR");
    else if (cube.side[2][0][1] == Cube::orange && cube.side[3][0][1] == Cube::blue && cube.side[4][0][1] == Cube::red && cube.side[5][0][1] == Cube::green)
        cube.sequenceOfTurns("RRLLDRRLLUURRLLDRRLL");
    else if (cube.side[2][0][1] == Cube::green && cube.side[3][0][1] == Cube::red && cube.side[4][0][1] == Cube::blue && cube.side[5][0][1] == Cube::orange)
        cube.sequenceOfTurns("UruRuRURurURURRurU");
    else {
        cube.sequenceOfTurns("RRURUrururUr");
        checkTwo(cube);
        cube.sequenceOfTurns("RRLLDRRLLUURRLLDRRLL");
        cube.sequenceOfTurns("RRURUrururUr");
        checkTwo(cube);
    }
}

void Solve::solveCorners1(Cube &cube) {
    if (cube.side[2][0][2] == Cube::orange && cube.side[3][0][0] == Cube::blue && cube.side[3][0][2] == Cube::red
        && cube.side[4][0][0] == Cube::green && cube.side[4][0][2] == Cube::green && cube.side[5][0][0] == Cube::orange)
        cube.sequenceOfTurns("rFrBBRfrBBRR");
    else if (cube.side[2][0][2] == Cube::orange && cube.side[3][0][0] == Cube::blue && cube.side[3][0][2] == Cube::green
             && cube.side[4][0][0] == Cube::orange && cube.side[4][0][2] == Cube::red && cube.side[5][0][0] == Cube::green)
        cube.sequenceOfTurns("RbrFRBrFFlBLFlbL");
    else
        cube.sequenceOfTurns("rFrBBRfrBBRR");
}

int Solve::checkCorners(Cube &cube) {
    if (cube.side[2][0][0] != Cube::red || cube.side[2][0][2] != Cube::red || cube.side[3][0][0] != Cube::green || cube.side[3][0][2] != Cube::green || cube.side[4][0][0] != Cube::orange || cube.side[4][0][2] != Cube::orange || cube.side[5][0][0] != Cube::blue || cube.side[5][0][2] != Cube::blue)
        return 0;
    return 1;
}

int Solve::checkEdges(Cube &cube) {
    if (cube.side[2][0][1] == Cube::red && cube.side[3][0][1] == Cube::green && cube.side[4][0][1] == Cube::orange && cube.side[5][0][1] == Cube::blue)
        return 1;
    return 0;
}

