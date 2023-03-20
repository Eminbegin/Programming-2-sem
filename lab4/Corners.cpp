#include "Solve.hpp"
#include "Cube.hpp"

void Solve::solveCorners(Cube &cube) {
    int count = 0;
    while (checkBottomLayer(cube)) {

        if (cube.side[0][0][0] == Cube::white || cube.side[2][2][0] == Cube::white || cube.side[5][2][2] == Cube::white) {
            while (cube.side[1][2][0] == Cube::white || cube.side[2][0][0] == Cube::white || cube.side[5][0][2] == Cube::white )
                cube.sequenceOfTurns("U");
            cube.sequenceOfTurns("FUf");
        }
        if (cube.side[0][0][2] == Cube::white || cube.side[2][2][2] == Cube::white || cube.side[3][2][0] == Cube::white) {
            while (cube.side[1][2][2] == Cube::white || cube.side[2][0][2] == Cube::white || cube.side[3][0][0] == Cube::white )
                cube.sequenceOfTurns("U");
            cube.sequenceOfTurns("RUr");
        }
        if (cube.side[0][2][0] == Cube::white || cube.side[4][2][2] == Cube::white || cube.side[5][2][0] == Cube::white) {
            while (cube.side[1][0][0] == Cube::white || cube.side[4][0][2] == Cube::white || cube.side[5][0][0] == Cube::white )
                cube.sequenceOfTurns("U");
            cube.sequenceOfTurns("LUl");
        }
        if (cube.side[0][2][2] == Cube::white || cube.side[3][2][2] == Cube::white || cube.side[4][2][0] == Cube::white) {
            while (cube.side[1][0][2] == Cube::white || cube.side[3][0][2] == Cube::white || cube.side[4][0][0] == Cube::white)
                cube.sequenceOfTurns("U");
            cube.sequenceOfTurns("BUb");
        }

        count++;
        if (count > 100)
            throw std::logic_error("invalid input");
    }
    count = 0;

    while (!(cube.side[0][0][0] == Cube::white && cube.side[0][0][2] == Cube::white && cube.side[0][2][0] == Cube::white && cube.side[0][2][2] == Cube::white)) {

        if (cube.side[1][2][2] == Cube::white) {
            if (cube.side[2][0][2] == Cube::red)
                cube.sequenceOfTurns("UFUUfuFUf");
            else if (cube.side[2][0][2] == Cube::green)
                cube.sequenceOfTurns("RUUruRUr");
            else if (cube.side[2][0][2] == Cube::orange)
                cube.sequenceOfTurns("uBUUbuBUb");
            else if (cube.side[2][0][2] == Cube::blue)
                cube.sequenceOfTurns("UULulUULUl");
        }

        else if (cube.side[3][0][0] == Cube::white) {
            if (cube.side[2][0][2] == Cube::red)
                cube.sequenceOfTurns("RUr");
            else if (cube.side[2][0][2] == Cube::green)
                cube.sequenceOfTurns("uBUb");
            else if (cube.side[2][0][2] == Cube::orange)
                cube.sequenceOfTurns("UULUl");
            else if (cube.side[2][0][2] == Cube::blue)
                cube.sequenceOfTurns("UFUf");
        }

        else if (cube.side[2][0][2] == Cube::white){
            if (cube.side[3][0][0] == Cube::red)
                cube.sequenceOfTurns("UluL");
            else if (cube.side[3][0][0] == Cube::green)
                cube.sequenceOfTurns("fuF");
            else if (cube.side[3][0][0] == Cube::orange)
                cube.sequenceOfTurns("UruR");
            else if (cube.side[3][0][0] == Cube::blue)
                cube.sequenceOfTurns("UUbuB");
        }
        else
            cube.sequenceOfTurns("U");

        count++;
        if (count > 100)
            throw std::logic_error("invalid input");
    }
}


int Solve::checkBottomLayer(Cube &cube) {
    if (cube.side[0][0][0] && cube.side[0][0][2] && cube.side[0][2][0] && cube.side[0][2][2]
        && cube.side[2][2][0] && cube.side[2][2][2] && cube.side[3][2][0] && cube.side[3][2][2]
        && cube.side[4][2][0] && cube.side[4][2][2] && cube.side[5][2][0] && cube.side[5][2][2])
        return 0;

    else if (cube.side[0][0][0] == Cube::white && cube.side[0][0][2] == Cube::white && cube.side[0][2][0] == Cube::white && cube.side[0][2][2] == Cube::white)
        return 0;

    else
        return 1;
}