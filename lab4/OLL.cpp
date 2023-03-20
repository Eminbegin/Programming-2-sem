#include "Cube.hpp"
#include "Solve.hpp"

void Solve::solveOLL(Cube &cube) {
    int count = 0;
    if (!(cube.side[1][0][1] == Cube::yellow && cube.side[1][1][0] == Cube::yellow && cube.side[1][1][2] == Cube::yellow && cube.side[1][2][1] == Cube::yellow)) {
        int position = findEdges(cube);
        while (position == 0) {
            ++count;
            cube.sequenceOfTurns("U");
            position = findEdges(cube);
            if (count > 5)
                throw std::logic_error("invalid input");
        }
        solveCase(cube, position);
    }
    count = 0;
    if (!checkOLL(cube)) {
        int position = findPosition(cube);
        while (position == 0) {
            ++count;
            cube.sequenceOfTurns("U");
            position = findPosition(cube);
            if (count > 5)
                throw std::logic_error("invalid input");
        }
        solveCase(cube, position);
    }
}

int Solve::checkOLL(Cube &cube) {
    for (int i=0; i<9; ++i)
        if (cube.side[1][i / 3][i % 3] != Cube::yellow)
            return 0;
    return 1;
}

void Solve::solveCase(Cube &cube, int position) {
    switch(position) {
        case 1:
            cube.sequenceOfTurns("FRUruf");
            solveOLL(cube);
            break;
        case 2:
            cube.sequenceOfTurns("BULulb");
            solveOLL(cube);
            break;
        case 3:
            cube.sequenceOfTurns("FRUrufBULulb");
            solveOLL(cube);
            break;
        case 4:
            cube.sequenceOfTurns("RUrURUUr");
            break;
        case 5:
            cube.sequenceOfTurns("ruRurUUR");
            break;
        case 6:
            cube.sequenceOfTurns("FRUruRUruRUruf");
            break;
        case 7:
            cube.sequenceOfTurns("RUURRuRRuRRUUR");
            break;
        case 8:
            cube.sequenceOfTurns("RRDrUURdrUUr");
            break;
        case 9:
            cube.sequenceOfTurns("LFrflFRf");
            break;
        case 10:
            cube.sequenceOfTurns("fLFrflFR");
            break;
        default:
            break;
    }
}

int Solve::findPosition(Cube &cube) {
    int upSide[9];
    int frontSide[3];
    int rightSide[3];
    int backSide[3];
    int leftSide[3];

    for (int j = 0; j < 9; ++j)
        upSide[j] = cube.side[1][j / 3][j % 3] == Cube::yellow ? 1 : 0;

    for (int j = 0; j < 3; ++j)
        frontSide[j] = cube.side[2][0][j] == Cube::yellow ? 1 : 0;

    for (int j = 0; j < 3; ++j)
        rightSide[j] = cube.side[3][0][j] == Cube::yellow ? 1 : 0;

    for (int j = 0; j < 3; ++j)
        backSide[j] = cube.side[4][0][j] == Cube::yellow ? 1 : 0;

    for (int j = 0; j < 3; ++j)
        leftSide[j] = cube.side[5][0][j] == Cube::yellow ? 1 : 0;

    if (upSide[0] != Cube::yellow && upSide[1] == Cube::yellow && upSide[2] != Cube::yellow && upSide[3] == Cube::yellow &&
        upSide[4] == Cube::yellow && upSide[5] == Cube::yellow && upSide[6] == Cube::yellow && upSide[7] == Cube::yellow &&
        upSide[8] != Cube::yellow && frontSide[2] == Cube::yellow && rightSide[2] == Cube::yellow && backSide[2] == Cube::yellow)
        return 4;

    else if (upSide[0] == Cube::yellow && upSide[1] == Cube::yellow && upSide[2] != Cube::yellow && upSide[3] == Cube::yellow &&
             upSide[4] == Cube::yellow && upSide[5] == Cube::yellow && upSide[6] != Cube::yellow && upSide[7] == Cube::yellow &&
             upSide[8] != Cube::yellow && frontSide[0] == Cube::yellow && rightSide[0] == Cube::yellow && backSide[0] == Cube::yellow)
        return 5;

    else if (upSide[0] != Cube::yellow && upSide[1] ==Cube::yellow&& upSide[2] !=Cube::yellow&& upSide[3] ==Cube::yellow&&
             upSide[4] == Cube::yellow && upSide[5] ==Cube::yellow&& upSide[6] !=Cube::yellow&& upSide[7] ==Cube::yellow&&
             upSide[8] != Cube::yellow && frontSide[0] ==Cube::yellow&& frontSide[2] ==Cube::yellow&& backSide[0] ==Cube::yellow&& backSide[2] == 1)
        return 6;

    else if (upSide[0] !=Cube::yellow&& upSide[1] ==Cube::yellow&& upSide[2] !=Cube::yellow&& upSide[3] ==Cube::yellow&&
             upSide[4] ==Cube::yellow&& upSide[5] ==Cube::yellow&& upSide[6] !=Cube::yellow&& upSide[7] ==Cube::yellow&&
             upSide[8] !=Cube::yellow&& frontSide[2] ==Cube::yellow&& backSide[0] ==Cube::yellow&& leftSide[0] ==Cube::yellow&& leftSide[2] == 1)
        return 7;

    else if (upSide[0] ==Cube::yellow&& upSide[1] ==Cube::yellow&& upSide[2] ==Cube::yellow&& upSide[3] ==Cube::yellow&&
             upSide[4] ==Cube::yellow&& upSide[5] ==Cube::yellow&& upSide[6] !=Cube::yellow&& upSide[7] ==Cube::yellow&&
             upSide[8] !=Cube::yellow&& frontSide[0] ==Cube::yellow&& frontSide[2] == 1)
        return 8;

    else if (upSide[0] !=Cube::yellow&& upSide[1] ==Cube::yellow&& upSide[2] ==Cube::yellow&& upSide[3] ==Cube::yellow&&
             upSide[4] ==Cube::yellow&& upSide[5] ==Cube::yellow&& upSide[6] !=Cube::yellow&& upSide[7] ==Cube::yellow&&
             upSide[8] ==Cube::yellow&& frontSide[0] ==Cube::yellow&& backSide[2] == 1)
        return 9;

    else if (upSide[0] !=Cube::yellow&& upSide[1] ==Cube::yellow&& upSide[2] ==Cube::yellow&& upSide[3] ==Cube::yellow&&
             upSide[4] ==Cube::yellow&& upSide[5] ==Cube::yellow&& upSide[6] ==Cube::yellow&& upSide[7] ==Cube::yellow&&
             upSide[8] !=Cube::yellow&& frontSide[2] ==Cube::yellow&& leftSide[0] == 1)
        return 10;
    return 0;
}

int Solve::findEdges(Cube &cube) {
    int upSide[9];
    for (int i = 0; i < 9; ++i)
        upSide[i] = cube.side[1][i / 3][i % 3] ==Cube::yellow? 1 : 0;
    if (upSide[3] ==Cube::yellow&& upSide[4] ==Cube::yellow&& upSide[5] == 1)
        return 1;
    else if (upSide[5] ==Cube::yellow&& upSide[7] == 1)
        return 2;
    else if (upSide[1] !=Cube::yellow&& upSide[3] !=Cube::yellow&& upSide[5] !=Cube::yellow&& upSide[7] != 1)
        return 3;
    return 0;
}
