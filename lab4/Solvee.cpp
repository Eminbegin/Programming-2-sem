#include "Solve.hpp"
#include "Cube.hpp"
#include "Rotate.hpp"


std::string Solve::fullSolve = std::string();
int Solve::rotateCount = 0;
void Solve::Left(Cube& cube) {
    Rotate::Left(cube);
    fullSolve.append("L");
}

void Solve::Right(Cube& cube){
    Rotate::Right(cube);
    fullSolve+='R';
}

void Solve::Front(Cube& cube){
    Rotate::Front(cube);
    fullSolve+='F';
}

void Solve::Back(Cube& cube){
    Rotate::Back(cube);
    fullSolve+='B';
}

void Solve::Up(Cube& cube){
    Rotate::Up(cube);
    fullSolve+='U';
}

void Solve::Down(Cube& cube){
    Rotate::Down(cube);
    fullSolve+='D';
}

void Solve::Xrot(Cube& cube){
    Rotate::Xrot(cube);
    fullSolve+='X';
}

void Solve::Yrot(Cube& cube){
    Rotate::Yrot(cube);
    fullSolve+='Y';
}

void Solve::Zrot(Cube& cube){
    Rotate::Zrot(cube);
    fullSolve+='Z';
}

void Solve::Left_(Cube& cube){
    Rotate::Left_(cube);
    fullSolve+='l';
}

void Solve::Right_(Cube& cube){
    Rotate::Right_(cube);
    fullSolve+='r';
}

void Solve::Front_(Cube& cube){
    Rotate::Front_(cube);
    fullSolve+='f';
}

void Solve::Back_(Cube& cube){
    Rotate::Back_(cube);
    fullSolve+='b';
}

void Solve::Up_(Cube& cube){
    Rotate::Up_(cube);
    fullSolve+='u';
}

void Solve::Down_(Cube& cube){
    Rotate::Down_(cube);
    fullSolve+='d';
}

void Solve::sequenceOfTurns(const std::string &sequence, Cube& cube) {
    cube.sequenceOfTurns(sequence);
}



void Solve::formatSolve() {
    std::string newSequence;
    int solveSize = fullSolve.size();
    for (int i = 0; i < solveSize; ++i) {
        if (i + 3 < solveSize) {
            if (fullSolve[i] == fullSolve[i + 1] &&
                fullSolve[i] == fullSolve[i + 2] &&
                fullSolve[i] == fullSolve[i + 3]) {
                i += 3;
                continue;
            }
        }
        if (i + 2 < solveSize) {
            if (fullSolve[i] == fullSolve[i + 1] && fullSolve[i] == fullSolve[i + 2]) {
                newSequence += (fullSolve[i] - 'A' + 'a');
                i += 2;
                continue;
            }
        }
        if (i + 1 < solveSize) {
            if (abs(fullSolve[i] - fullSolve[i + 1]) == abs('A' - 'a')) {
                i += 1;
                continue;
            }
        }
        newSequence += fullSolve[i];
    }
    fullSolve.clear();
    int count = 0;
    std::string finalStirng;
    for (char i: newSequence) {
        if ('A' <= i && i < 'X') {
            finalStirng += i;
            ++count;
            finalStirng += ' ';
        }
        if ('X' <= i && i <= 'Z') {
            finalStirng += (i + 32);
            finalStirng += '\'';
            ++count;
            finalStirng += ' ';
        }

        if ('a' < i && i < 'x') {
            finalStirng += (i - 32);
            finalStirng += '\'';
            ++count;
            finalStirng += ' ';
        }

        if ('x' <= i && i <= 'z') {
            finalStirng += i;
            ++count;
            finalStirng += ' ';
        }
    }
    fullSolve = finalStirng;
    rotateCount = count;
    fullSolve += std::to_string(rotateCount);
    fullSolve += " rotates";
}



std::string& Solve::getSolve() {
    Solve::formatSolve();
    return fullSolve;
}

void Solve::solve(Cube& cube) {
    Solve::solveRotate(cube);
    Solve::solveCross(cube);
    Solve::solveCorners(cube);
    Solve::solveEdges(cube);
    Solve::solveOLL(cube);
    Solve::solvePLL(cube);
}

void Solve::clearSolve() {
    fullSolve.clear();
}