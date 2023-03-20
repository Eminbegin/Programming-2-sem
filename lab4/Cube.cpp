#include <iostream>
#include "Cube.hpp"
#include <ctime>
#include "Solve.hpp"

#include <string>


// #include <glut.h>
/*                                              _______
        0 1 2                                  |       |
        3 4 5                                  |  Up   |
        6 7 8                          _______ |_______| _______  _______
 0 1 2  0 1 2  0 1 2  0 1 2           |       ||       ||       ||       |
 3 4 5  3 4 5  3 4 5  3 4 5           | Left  || Front || Right || Back  |
 6 7 8  6 7 8  6 7 8  6 7 8           |_______||_______||_______||_______|
        0 1 2                                  |       |
        3 4 5                                  | Down  |
        6 7 8                                  |_______|

 0 - d(white); 1 - u(yellow); 2 - f(red); 3 - r(green); 4 - b(orange); 5 - l(blue)
 */

char charFromEnum(int i) {
    switch (i) {
        case 0:
            return 'w';
        case 1:
            return 'y';
        case 2:
            return 'r';
        case 3:
            return 'g';
        case 4:
            return 'o';
        case 5:
            return 'b';
        default:
            throw std::logic_error("Unexpected color");
    }
}

char enumFromEChar(char i) {
    switch (i) {
        case 'w':
            return 0;
        case 'y':
            return 1;
        case 'r':
            return 2;
        case 'g':
            return 3;
        case 'o':
            return 4;
        case 'b':
            return 5;
        default:
            throw std::logic_error("Unexpected color");
    }
}


Cube::Cube() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            side[0][i][j] = white;
            side[1][i][j] = yellow;
            side[2][i][j] = red;
            side[3][i][j] = green;
            side[4][i][j] = orange;
            side[5][i][j] = blue;
        }
    }
}

/*void Cube::show() {
    for (int i = 0; i < 3; i++) {
        std::cout << "    ";
        for (int j = 0; j < 3; j++)
            std::cout << side[1][i][j];
        std::cout << "\n";
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            std::cout << side[5][i][j];
        std::cout << " ";
        for (int j = 0; j < 3; j++)
            std::cout << side[2][i][j];
        std::cout << " ";
        for (int j = 0; j < 3; j++)
            std::cout << side[3][i][j];
        std::cout << " ";
        for (int j = 0; j < 3; j++)
            std::cout << side[4][i][j];
        std::cout << "\n";
    }
    for (int i = 0; i < 3; i++) {
        std::cout << "    ";
        for (int j = 0; j < 3; j++)
            std::cout << side[0][i][j];
        std::cout << "\n";
    }
    std::cout << "\n";
}
*/

std::ostream &operator<<(std::ostream &out, const Cube &other) {
    out << "\n";
    for (int i = 0; i < 3; i++) {
        out << "    ";
        for (int j = 0; j < 3; j++) {
            out << charFromEnum(other.side[1][i][j]);
        }
        out << "\n";
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            out << charFromEnum(other.side[5][i][j]);
        out << " ";
        for (int j = 0; j < 3; j++)
            out << charFromEnum(other.side[2][i][j]);
        out << " ";
        for (int j = 0; j < 3; j++)
            out << charFromEnum(other.side[3][i][j]);
        out << " ";
        for (int j = 0; j < 3; j++)
            out << charFromEnum(other.side[4][i][j]);
        out << "\n";
    }
    for (int i = 0; i < 3; i++) {
        out << "    ";
        for (int j = 0; j < 3; j++)
            out << charFromEnum(other.side[0][i][j]);
        out << "\n";
    }
    out << "\n";
    return out;
}

Cube &operator>>(std::istream &in, Cube &other) {
    std::string s;
    char i_hate_enum;
    int checkSides = 0;
    char variation;
    in >> variation;
    if ('0' <= variation && variation <= '9') {
        for (int i = 0; i < 6; ++i) {
            in >> s;
            switch (s[0]) {
                case 'f':
                    checkSides += 1;
                    for (int j = 0; j < 3; ++j)
                        for (int k = 0; k < 3; ++k) {
                            in >> i_hate_enum;
                            other.side[2][j][k] = static_cast<Cube::Colors>(i_hate_enum - 48);
                        }
                    break;
                case 'b':
                    checkSides += 10;
                    for (int j = 0; j < 3; ++j)
                        for (int k = 0; k < 3; ++k) {
                            in >> i_hate_enum;
                            other.side[4][j][k] = static_cast<Cube::Colors>(i_hate_enum - 48);
                        }
                    break;
                case 'r':
                    checkSides += 100;
                    for (int j = 0; j < 3; ++j)
                        for (int k = 0; k < 3; ++k) {
                            in >> i_hate_enum;
                            other.side[3][j][k] = static_cast<Cube::Colors>(i_hate_enum - 48);
                        }
                    break;
                case 'l':
                    checkSides += 1000;
                    for (int j = 0; j < 3; ++j)
                        for (int k = 0; k < 3; ++k) {
                            in >> i_hate_enum;
                            other.side[5][j][k] = static_cast<Cube::Colors>(i_hate_enum - 48);
                        }
                    break;
                case 'u':
                    checkSides += 10000;
                    for (int j = 0; j < 3; ++j)
                        for (int k = 0; k < 3; k++) {
                            in >> i_hate_enum;
                            other.side[1][j][k] = static_cast<Cube::Colors>(i_hate_enum - 48);
                        }
                    break;
                case 'd':
                    checkSides += 100000;
                    for (int j = 0; j < 3; ++j)
                        for (int k = 0; k < 3; ++k) {
                            in >> i_hate_enum;
                            other.side[0][j][k] = static_cast<Cube::Colors>(i_hate_enum - 48);
                        }
                    break;
                default:
                    throw std::logic_error("invalid input");
            }
        }
        if (checkSides != 111111)
            throw std::logic_error("invalid input");
    } else if ('a' <= variation && variation <= 'z') {
        for (int i = 0; i < 6; ++i) {
            in >> s;
            switch (s[0]) {
                case 'f':
                    checkSides += 1;
                    for (int j = 0; j < 3; ++j)
                        for (int k = 0; k < 3; ++k) {
                            in >> i_hate_enum;
                            other.side[2][j][k] = static_cast<Cube::Colors>(enumFromEChar(i_hate_enum));
                        }
                    break;
                case 'b':
                    checkSides += 10;
                    for (int j = 0; j < 3; ++j)
                        for (int k = 0; k < 3; ++k) {
                            in >> i_hate_enum;
                            other.side[4][j][k] = static_cast<Cube::Colors>(enumFromEChar(i_hate_enum));
                        }
                    break;
                case 'r':
                    checkSides += 100;
                    for (int j = 0; j < 3; ++j)
                        for (int k = 0; k < 3; ++k) {
                            in >> i_hate_enum;
                            other.side[3][j][k] = static_cast<Cube::Colors>(enumFromEChar(i_hate_enum));
                        }
                    break;
                case 'l':
                    checkSides += 1000;
                    for (int j = 0; j < 3; ++j)
                        for (int k = 0; k < 3; ++k) {
                            in >> i_hate_enum;
                            other.side[5][j][k] = static_cast<Cube::Colors>(enumFromEChar(i_hate_enum));
                        }
                    break;
                case 'u':
                    checkSides += 10000;
                    for (int j = 0; j < 3; ++j)
                        for (int k = 0; k < 3; k++) {
                            in >> i_hate_enum;
                            other.side[1][j][k] = static_cast<Cube::Colors>(enumFromEChar(i_hate_enum));
                        }
                    break;
                case 'd':
                    checkSides += 100000;
                    for (int j = 0; j < 3; ++j)
                        for (int k = 0; k < 3; ++k) {
                            in >> i_hate_enum;
                            other.side[0][j][k] = static_cast<Cube::Colors>(enumFromEChar(i_hate_enum));
                        }
                    break;
                default:
                    throw std::logic_error("invalid input");
            }
        }
        if (checkSides != 111111)
            throw std::logic_error("invalid input");
    }
    return other;
}


void Cube::sequenceOfTurns(const std::string &sequence) {
    int n = sequence.size();
    int i = 0;
    while (i < n) {
        switch (sequence[i]) {
            case 'U':
                Solve::Up(*this);
                break;
            case 'D':
                Solve::Down(*this);
                break;
            case 'B':
                Solve::Back(*this);
                break;
            case 'F':
                Solve::Front(*this);
                break;
            case 'L':
                Solve::Left(*this);
                break;
            case 'R':
                Solve::Right(*this);
                break;
            case 'x':
                Solve::Xrot(*this);
                break;
            case 'y':
                Solve::Yrot(*this);
                break;
            case 'z':
                Solve::Zrot(*this);
                break;
            case 'u':
                Solve::Up_(*this);
                break;
            case 'd':
                Solve::Down_(*this);
                break;
            case 'b':
                Solve::Back_(*this);
                break;
            case 'f':
                Solve::Front_(*this);
                break;
            case 'l':
                Solve::Left_(*this);
                break;
            case 'r':
                Solve::Right_(*this);
                break;
            case 'X':
                Solve::Xrot(*this);
                Solve::Xrot(*this);
                Solve::Xrot(*this);
                break;
            case 'Y':
                Solve::Yrot(*this);
                Solve::Yrot(*this);
                Solve::Yrot(*this);
                break;
            case 'Z':
                Solve::Zrot(*this);
                Solve::Zrot(*this);
                Solve::Zrot(*this);
                break;
            default:
                throw std::logic_error("invalid input");
        }
        ++i;
    }

}

void Cube::scramble() {
    std::string rotates = "UDRLFBudrlfbUDRLFBudrlfbUDRLFBudrlfbUDRLFBudrlfbUDRLFBudrlfbxyzxyz";
    std::string finishScramble;
    srand((unsigned) time(0));
    int i = (rand() % 41) + 40;
    char move;
    for (int j = 0; j < i; ++j) {
        move = rotates[(rand() % rotates.size())];
        finishScramble += move;
    }
    std::cout << "Random scramble: " << i << " rotates: ";
    sequenceOfTurns(finishScramble);

    std::string finalStirng;
    for (char i: finishScramble) {
        if ('A' <= i && i < 'X') {
            finalStirng += i;
            finalStirng += ' ';
        }
        if ('X' <= i && i <= 'Z') {
            finalStirng += (i + 32);
            finalStirng += '\'';
            finalStirng += ' ';
        }

        if ('a' < i && i < 'x') {
            finalStirng += (i - 32);
            finalStirng += '\'';
            finalStirng += ' ';
        }

        if ('x' <= i && i <= 'z') {
            finalStirng += i;
            finalStirng += ' ';
        }
    }
    std::cout << finalStirng << "\n";
}

