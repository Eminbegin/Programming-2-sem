#include "Cube.hpp"
#include "Solve.hpp"
#include "Rotate.hpp"
#include <iostream>
#include <fstream>

//0 - d(white); 1 - u(yellow); 2 - f(red); 3 - r(green); 4 - b(orange); 5 - l(blue)

void allturnes() {
    std::cout << "F, B, R, L, U, D \t- rotate appropriate side clockwise\n";
    std::cout << "F', B', R', L', U', D' \t- rotate appropriate side counterclockwise\n";
    std::cout << "F2, B2, R2, L2, U2, D2 \t- rotate appropriate side twice\n";
    std::cout << "x, y, z, x', y', z' \t- rotate cube entirely\n";
}

void help() {
    std::cout << "clear \t-returns cube to the starting position\n";
    std::cout << "read \t-input cube's position from console\n";
    std::cout << "readf \t-input cube's position from file\n";
    std::cout << "show \t-output cube's position to console\n";
    std::cout << "save \t-output cube's position to console\n";
    std::cout << "solve \t-solve cube\n";
    std::cout << "solver \t-output cube's solve\n";
    std::cout << "turn \t-input sequence of turns\n";
    std::cout << "mix \t-mix cube\n";
    std::cout << "exit \t-for exit\n";


}

int main() {
    int countWI = 0;
    std::string input;
    Cube cube;
    std::cout << "KUBIK HUIBIK, enter \"info\" for info, OK?\n";
    while (input != "exit") {
        std::cin >> input;
        if (input == "info") {
            help();
        } else if (input == "clear") {
            std::cout << "Cube in the starting position\n";
            cube = Cube();
        } else if (input == "readf") {
            std::cout << "Enter filename\n";
            std::cin >> input;
            std::ifstream file(input);
            if (!file) {
                std::cout << "File didn't open\n";
            } else {
                file >> cube;
                std::cout << "Cube read from file\n";
            }
        } else if (input == "read") {
            std::cout << "Enter cube position\n";
            std::cin >> cube;
        } else if (input == "save") {
            std::cout << "Enter filename\n";
            std::cin >> input;
            std::ofstream file(input);
            if (!file) {
                std::cout << "File didn't open\n";
            } else {
                file << cube;
                std::cout << "Cube save to file\n";
            }
        } else if (input == "show") {
            std::cout << "Now position:\n";
            std::cout << cube;
        } else if (input == "solve") {
            std::cout << "Trying to solve\n";
            Solve::solve(cube);
            std::cout << "Solving is complete\n";
            std::cout << "Enter \"solver\" to see turns for solving cube\n";
        } else if (input == "solver") {
            std::cout << Solve::getSolve();
            Solve::clearSolve();
            std::cout << "\n";
        } else if (input == "mix") {
            cube.scramble();
        } else if (input == "turn") {
            std::cout << "Enter \"end\" for end changing cube\n";
            std::cout << "Or enter \"turnes\" for showing all available turnes\n";
            std::cout << "Or enter turn\n";
            std::cin >> input;
            while (input != "end") {
                if (input == "turnes") {
                    allturnes();
                } else if (input == "F") {
                    cube.sequenceOfTurns("F");
                    std::cout << ">\n";
                } else if (input == "B") {
                    cube.sequenceOfTurns("B");
                    std::cout << ">\n";
                } else if (input == "R") {
                    cube.sequenceOfTurns("R");
                    std::cout << ">\n";
                } else if (input == "L") {
                    cube.sequenceOfTurns("L");
                    std::cout << ">\n";
                } else if (input == "U") {
                    cube.sequenceOfTurns("U");
                    std::cout << ">\n";
                } else if (input == "D") {
                    cube.sequenceOfTurns("D");
                    std::cout << ">\n";
                } else if (input == "F'") {
                    cube.sequenceOfTurns("f");
                    std::cout << ">\n";
                } else if (input == "B'") {
                    cube.sequenceOfTurns("b");
                    std::cout << ">\n";
                } else if (input == "R'") {
                    cube.sequenceOfTurns("r");
                    std::cout << ">\n";
                } else if (input == "L'") {
                    cube.sequenceOfTurns("l");
                    std::cout << ">\n";
                } else if (input == "U'") {
                    cube.sequenceOfTurns("u");
                    std::cout << ">\n";
                } else if (input == "D'") {
                    cube.sequenceOfTurns("d");
                    std::cout << ">\n";
                } else if (input == "x") {
                    cube.sequenceOfTurns("x");
                    std::cout << ">\n";
                } else if (input == "y") {
                    cube.sequenceOfTurns("y");
                    std::cout << ">\n";
                } else if (input == "z") {
                    cube.sequenceOfTurns("z");
                    std::cout << ">\n";
                } else if (input == "x'") {
                    cube.sequenceOfTurns("X");
                    std::cout << ">\n";
                } else if (input == "y'") {
                    cube.sequenceOfTurns("Y");
                    std::cout << ">\n";
                } else if (input == "z'") {
                    cube.sequenceOfTurns("Z");
                    std::cout << ">\n";
                } else {
                    std::cout << "Unknown command\n";
                    std::cout << "Don't forget about \"end\"\n";
                }
                std::cin >> input;
            }
            std::cout << "Turns are over\n";
        } else if (input == "exit") {
            std::cout << "Don't forget watch this video https://clck.ru/9TFat";
        } else {
            countWI += 1;
            std::cout << "Wrong input\n";
            if (countWI == 5) {
                std::cout << "Try watch https://clck.ru/9TFat for more information about this program\n";
            }
        }
    }
    return 0;
}
