#include "Solve.hpp"
#include "Cube.hpp"

void Solve::solveCross(Cube &cube) {
    int count = 0;
    while (!(cube.side[0][0][1] == Cube::white && cube.side[0][1][0] == Cube::white &&
            cube.side[0][1][2] == Cube::white && cube.side[0][2][1] == Cube::white &&
            cube.side[2][2][1] == Cube::red && cube.side[3][2][1] == Cube::green &&
            cube.side[4][2][1] == Cube::orange && cube.side[5][2][1] == Cube::blue)) {
        solveEdge1(cube);
        ++count;
        if (count > 100)
            throw std::logic_error("invalid input");
    }
}

void Solve::solveEdge1(Cube &cube) {
    for (int i=0; i<6; ++i) {
        for (int j = 1; j<9; j+=2) {
            if (cube.side[i][j/3][j%3] == Cube::white) {
                switch (i) {
                    case 1: {
                        if (j == 1) {
                            switch (cube.side[4][0][1]) {
                                case Cube::red:
                                    cube.sequenceOfTurns("UUFF");
                                    break;
                                case Cube::green:
                                    cube.sequenceOfTurns("URR");
                                    break;
                                case Cube::orange:
                                    cube.sequenceOfTurns("BB");
                                    break;
                                case Cube::blue:
                                    cube.sequenceOfTurns("uLL");
                                    break;
                                default:
                                    break;
                            }
                        }
                        else if (j == 3) {
                            switch (cube.side[5][0][1]) {
                                case Cube::red:
                                    cube.sequenceOfTurns("uFF");
                                    break;
                                case Cube::green:
                                    cube.sequenceOfTurns("UURR");
                                    break;
                                case Cube::orange:
                                    cube.sequenceOfTurns("UBB");
                                    break;
                                case Cube::blue:
                                    cube.sequenceOfTurns("LL");
                                    break;
                                default:
                                    break;
                            }
                        }
                        else if (j == 5) {
                            switch(cube.side[3][0][1]) {
                                case Cube::red:
                                    cube.sequenceOfTurns("UFF");
                                    break;
                                case Cube::green:
                                    cube.sequenceOfTurns("RR");
                                    break;
                                case Cube::orange:
                                    cube.sequenceOfTurns("uBB");
                                    break;
                                case Cube::blue:
                                    cube.sequenceOfTurns("UULL");
                                    break;
                                default:
                                    break;
                            }
                        }
                        else if (j == 7) {
                            switch (cube.side[2][0][1]) {
                                case Cube::red:
                                    cube.sequenceOfTurns("FF");
                                    break;
                                case Cube::green:
                                    cube.sequenceOfTurns("uRR");
                                    break;
                                case Cube::orange:
                                    cube.sequenceOfTurns("UUBB");
                                    break;
                                case Cube::blue:
                                    cube.sequenceOfTurns("ULL");
                                    break;
                                default:
                                    break;
                            }
                        }
                        break;
                    }
                    case 2: {

                        if (j == 1) {
                            switch(cube.side[1][2][1]) {
                                case Cube::red:
                                    cube.sequenceOfTurns("urFR");
                                    break;
                                case Cube::green:
                                    cube.sequenceOfTurns("Frf");
                                    break;
                                case Cube::orange:
                                    cube.sequenceOfTurns("uRbr");
                                    break;
                                case Cube::blue:
                                    cube.sequenceOfTurns("fLF");
                                    break;
                                default:
                                    break;
                            }
                        }
                        else if (j == 3) {
                            switch(cube.side[5][1][2]) {
                                case Cube::red:
                                    cube.sequenceOfTurns("LDl");
                                    break;
                                case Cube::green:
                                    cube.sequenceOfTurns("UUFUU");
                                    break;
                                case Cube::orange:
                                    cube.sequenceOfTurns("lULBB");
                                    break;
                                case Cube::blue:
                                    cube.sequenceOfTurns("L");
                                    break;
                                default:
                                    break;

                            }
                        }
                        else if (j == 5) {
                            switch(cube.side[3][1][0]) {
                                case Cube::red:
                                    cube.sequenceOfTurns("rdR");
                                    break;
                                case Cube::green:
                                    cube.sequenceOfTurns("r");
                                    break;
                                case Cube::orange:
                                    cube.sequenceOfTurns("RurBB");
                                    break;
                                case Cube::blue:
                                    cube.sequenceOfTurns("RUUrLL");
                                    break;
                                default:
                                    break;
                            }
                        }
                        else if (j == 7) {
                            switch (cube.side[0][0][1]) {
                                case Cube::red:
                                    cube.sequenceOfTurns("fDrd");
                                    break;
                                case Cube::green:
                                    cube.sequenceOfTurns("fr");
                                    break;
                                case Cube::orange:
                                    cube.sequenceOfTurns("FFuRbr");
                                    break;
                                case Cube::blue:
                                    cube.sequenceOfTurns("FL");
                                    break;
                                default:
                                    break;
                            }
                        }

                        break;
                    }
                    case 3:
                        if (j == 1) {
                            switch(cube.side[1][1][2]) {
                                case Cube::red:
                                    cube.sequenceOfTurns("rFR");
                                    break;
                                case Cube::green:
                                    cube.sequenceOfTurns("UFrf");
                                    break;
                                case Cube::orange:
                                    cube.sequenceOfTurns("Rbr");
                                    break;
                                case Cube::blue:
                                    cube.sequenceOfTurns("UfLF");
                                    break;
                                default:
                                    break;
                            }
                        }
                        else if (j == 3) {
                            switch(cube.side[2][1][2]) {
                                case Cube::red:
                                    cube.sequenceOfTurns("F");
                                    break;
                                case Cube::green:
                                    cube.sequenceOfTurns("fuFRR");
                                    break;
                                case Cube::orange:
                                    cube.sequenceOfTurns("RRbRR");
                                    break;
                                case Cube::blue:
                                    cube.sequenceOfTurns("fUFLL");
                                    break;
                                default:
                                    break;
                            }
                        }
                        else if (j == 5) {
                            switch(cube.side[4][1][0]) {
                                case Cube::red:
                                    cube.sequenceOfTurns("RRFRR");
                                    break;
                                case Cube::green:
                                    cube.sequenceOfTurns("BUbRR");
                                    break;
                                case Cube::orange:
                                    cube.sequenceOfTurns("b");
                                    break;
                                case Cube::blue:
                                    cube.sequenceOfTurns("rUfLF");
                                    break;
                                default:
                                    break;
                            }
                        }
                        else if (j == 7) {
                            switch (cube.side[0][1][2]) {
                                case Cube::red:
                                    cube.sequenceOfTurns("RFr");
                                    break;
                                case Cube::green:
                                    cube.sequenceOfTurns("RRUFrf");
                                    break;
                                case Cube::orange:
                                    cube.sequenceOfTurns("rbR");
                                    break;
                                case Cube::blue:
                                    cube.sequenceOfTurns("RRUfLF");
                                    break;
                                default:
                                    break;
                            }
                        }
                        break;
                    case 4:
                        if (j == 1) {
                            switch(cube.side[1][0][1]) {
                                case Cube::red:
                                    cube.sequenceOfTurns("UrFR");
                                    break;
                                case Cube::green:
                                    cube.sequenceOfTurns("bRB");
                                    break;
                                case Cube::orange:
                                    cube.sequenceOfTurns("URbr");
                                    break;
                                case Cube::blue:
                                    cube.sequenceOfTurns("Blb");
                                    break;
                                default:
                                    break;
                            }
                        }
                        else if (j == 3) {
                            switch(cube.side[3][1][2]) {
                                case Cube::red:
                                    cube.sequenceOfTurns("rURFF");
                                    break;
                                case Cube::green:
                                    cube.sequenceOfTurns("R");
                                    break;
                                case Cube::orange:
                                    cube.sequenceOfTurns("ruRBB");
                                    break;
                                case Cube::blue:
                                    cube.sequenceOfTurns("rUURLL");
                                    break;
                                default:
                                    break;
                            }
                        }
                        else if (j == 5) {
                            switch(cube.side[5][1][0]) {
                                case Cube::red:
                                    cube.sequenceOfTurns("LulFF");
                                    break;
                                case Cube::green:
                                    cube.sequenceOfTurns("LUUlRR");
                                    break;
                                case Cube::orange:
                                    cube.sequenceOfTurns("LUlBB");
                                    break;
                                case Cube::blue:
                                    cube.sequenceOfTurns("l");
                                    break;
                                default:
                                    break;
                            }
                        }
                        else if (j == 7) {
                            switch (cube.side[0][2][1]) {
                                case Cube::red:
                                    cube.sequenceOfTurns("BBUrFR");
                                    break;
                                case Cube::green:
                                    cube.sequenceOfTurns("BRb");
                                    break;
                                case Cube::orange:
                                    cube.sequenceOfTurns("BBURbr");
                                    break;
                                case Cube::blue:
                                    cube.sequenceOfTurns("blB");
                                    break;
                                default:
                                    break;
                            }
                        }
                        break;
                    case 5:
                        if (j == 1) {
                            switch(cube.side[1][1][0]) {
                                case Cube::red:
                                    cube.sequenceOfTurns("LFl");
                                    break;
                                case Cube::green:
                                    cube.sequenceOfTurns("uFrf");
                                    break;
                                case Cube::orange:
                                    cube.sequenceOfTurns("lBL");
                                    break;
                                case Cube::blue:
                                    cube.sequenceOfTurns("ufLF");
                                    break;
                                default:
                                    break;
                            }
                        }
                        else if (j == 3) {
                            switch(cube.side[4][1][2]) {
                                case Cube::red:
                                    cube.sequenceOfTurns("LLfLL");
                                    break;
                                case Cube::green:
                                    cube.sequenceOfTurns("LuFrf");
                                    break;
                                case Cube::orange:
                                    cube.sequenceOfTurns("B");
                                    break;
                                case Cube::blue:
                                    cube.sequenceOfTurns("LufLF");
                                    break;
                                default:
                                    break;
                            }
                        }
                        else if (j == 5) {
                            switch(cube.side[2][1][0]) {
                                case Cube::red:
                                    cube.sequenceOfTurns("f");
                                    break;
                                case Cube::green:
                                    cube.sequenceOfTurns("FufRR");
                                    break;
                                case Cube::orange:
                                    cube.sequenceOfTurns("FUUfBB");
                                    break;
                                case Cube::blue:
                                    cube.sequenceOfTurns("FUfLL");
                                    break;
                                default:
                                    break;
                            }
                        }
                        else if (j == 7) {
                            switch (cube.side[0][1][0]) {
                                case Cube::red:
                                    cube.sequenceOfTurns("lfL");
                                    break;
                                case Cube::green:
                                    cube.sequenceOfTurns("LLUFrf");
                                    break;
                                case Cube::orange:
                                    cube.sequenceOfTurns("LBl");
                                    break;
                                case Cube::blue:
                                    cube.sequenceOfTurns("LLUfLF");
                                    break;
                                default:
                                    break;
                            }
                        }

                        break;

                    case 0:
                        if (j == 1) {
                            if (cube.side[2][2][1] != Cube::red) {
                                while (cube.side[2][0][1] == Cube::white || cube.side[1][2][1] == Cube::white)
                                    cube.sequenceOfTurns("U");
                                cube.sequenceOfTurns("FF");
                            }
                        }
                        else if (j == 5) {
                            if (cube.side[3][2][1] != Cube::green) {
                                while (cube.side[3][0][1] == Cube::white || cube.side[1][1][2] == Cube::white)
                                    cube.sequenceOfTurns("U");
                                cube.sequenceOfTurns("RR");
                            }
                        }
                        else if (j == 7) {
                            if (cube.side[4][2][1] != Cube::orange) {
                                while (cube.side[3][0][1] == Cube::white || cube.side[1][0][1] == Cube::white)
                                    cube.sequenceOfTurns("U");
                                cube.sequenceOfTurns("BB");
                            }
                        }
                        else if (j == 3) {
                            if (cube.side[5][2][1] != Cube::blue) {
                                while (cube.side[5][0][1] == Cube::white || cube.side[1][1][0] == Cube::white)
                                    cube.sequenceOfTurns("U");
                                cube.sequenceOfTurns("LL");
                            }
                        }

                        break;
                    default:
                        break;
                }
            }
        }
    }

}