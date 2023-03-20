#include "Rotate.hpp"

void Rotate::Rot1(Cube& cube, int a) {
    int i, k, j;
    Cube::Colors save[9];
    for (i = 0; i < 3; ++i)
        for (j = 0; j < 3; ++j)
            save[3 * i + j] = cube.side[a][i][j];
    k = 0;
    for (i = 2; i >= 0; --i) {
        for (j = 0; j < 3; ++j) {
            cube.side[a][j][i] = save[k]; //[k/3][k%3];
            ++k;
        }
    }
}

void Rotate::Rot1_(Cube& cube, int a) {
    int i, j, k;
    Cube::Colors save[9];
    for (i = 0; i < 3; ++i)
        for (j = 0; j < 3; ++j)
            save[3 * i + j] = cube.side[a][i][j];

    k = 0;
    for (i = 0; i < 3; ++i) {
        for (j = 2; j >= 0; --j) {
            cube.side[a][j][i] = save[k]; //[k/3][k%3];
            ++k;
        }
    }
}

void Rotate::Rot2(Cube& cube, int a, int b, int c, int d) {
    Cube::Colors save[9];
    for (int i = 0; i < 9; ++i) {
        save[i] = cube.side[a][i / 3][i % 3];
        cube.side[a][i / 3][i % 3] = cube.side[b][i / 3][i % 3];
        cube.side[b][i / 3][i % 3] = cube.side[c][i / 3][i % 3];
        cube.side[c][i / 3][i % 3] = cube.side[d][i / 3][i % 3];
        cube.side[d][i / 3][i % 3] = save[i];
    }
}

void Rotate::Left(Cube& cube) {
    Rot1(cube, 5);
    int i;
    Cube::Colors save[3];
    for (i = 0; i < 3; ++i) {
        save[i] = cube.side[4][i][2];
        cube.side[4][i][2] = cube.side[0][2 - i][0];
        cube.side[0][2 - i][0] = cube.side[2][2 - i][0];
        cube.side[2][2 - i][0] = cube.side[1][2 - i][0];
        cube.side[1][2 - i][0] = save[i];
    }
}

void Rotate::Right(Cube& cube) {
    Rot1(cube, 3);
    int i;
    Cube::Colors save[3];
    for (i = 0; i < 3; ++i) {
        save[i] = cube.side[4][i][0];
        cube.side[4][i][0] = cube.side[1][2 - i][2];
        cube.side[1][2 - i][2] = cube.side[2][2 - i][2];
        cube.side[2][2 - i][2] = cube.side[0][2 - i][2];
        cube.side[0][2 - i][2] = save[i];
    }
}

void Rotate::Front(Cube& cube) {
    Rot1(cube, 2);
    int i;
    Cube::Colors save[3];
    for (i = 0; i < 3; ++i) {
        save[i] = cube.side[1][2][i];
        cube.side[1][2][i] = cube.side[5][2 - i][2];
        cube.side[5][2 - i][2] = cube.side[0][0][2 - i];
        cube.side[0][0][2 - i] = cube.side[3][i][0];
        cube.side[3][i][0] = save[i];
    }
}

void Rotate::Back(Cube& cube) {
    Rot1(cube, 4);
    int i;
    Cube::Colors save[3];
    for (i = 0; i < 3; ++i) {
        save[i] = cube.side[1][0][i];
        cube.side[1][0][i] = cube.side[3][i][2];
        cube.side[3][i][2] = cube.side[0][2][2 - i];
        cube.side[0][2][2 - i] = cube.side[5][2 - i][0];
        cube.side[5][2 - i][0] = save[i];
    }
}

void Rotate::Up(Cube& cube) {
    Rot1(cube, 1);
    int i;
    Cube::Colors save[3];
    for (i = 0; i < 3; ++i) {
        save[i] = cube.side[5][0][i];
        cube.side[5][0][i] = cube.side[2][0][i];
        cube.side[2][0][i] = cube.side[3][0][i];
        cube.side[3][0][i] = cube.side[4][0][i];
        cube.side[4][0][i] = save[i];
    }
}

void Rotate::Down(Cube& cube) {
    Rot1(cube, 0);
    int i;
    Cube::Colors save[3];
    for (i = 0; i < 3; ++i) {
        save[i] = cube.side[5][2][i];
        cube.side[5][2][i] = cube.side[4][2][i];
        cube.side[4][2][i] = cube.side[3][2][i];
        cube.side[3][2][i] = cube.side[2][2][i];
        cube.side[2][2][i] = save[i];
    }
}

void Rotate::Left_(Cube& cube) {
    Rot1_(cube, 5);
    int i;
    Cube::Colors save[3];
    for (i = 0; i < 3; ++i) {
        save[i] = cube.side[4][i][2];
        cube.side[4][i][2] = cube.side[1][2 - i][0];
        cube.side[1][2 - i][0] = cube.side[2][2 - i][0];
        cube.side[2][2 - i][0] = cube.side[0][2 - i][0];
        cube.side[0][2 - i][0] = save[i];
    }
}

void Rotate::Right_(Cube& cube) {
    Rot1_(cube, 3);
    int i;
    Cube::Colors save[3];
    for (i = 0; i < 3; ++i) {
        save[i] = cube.side[4][i][0];
        cube.side[4][i][0] = cube.side[0][2 - i][2];
        cube.side[0][2 - i][2] = cube.side[2][2 - i][2];
        cube.side[2][2 - i][2] = cube.side[1][2 - i][2];
        cube.side[1][2 - i][2] = save[i];
    }
}

void Rotate::Front_(Cube& cube) {
    Rot1_(cube, 2);
    int i;
    Cube::Colors save[3];
    for (i = 0; i < 3; ++i) {
        save[i] = cube.side[1][2][i];
        cube.side[1][2][i] = cube.side[3][i][0];
        cube.side[3][i][0] = cube.side[0][0][2 - i];
        cube.side[0][0][2 - i] = cube.side[5][2 - i][2];
        cube.side[5][2 - i][2] = save[i];
    }
}

void Rotate::Back_(Cube& cube) {
    Rot1_(cube, 4);
    int i;
    Cube::Colors save[3];
    for (i = 0; i < 3; ++i) {
        save[i] = cube.side[1][0][i];
        cube.side[1][0][i] = cube.side[5][2 - i][0];
        cube.side[5][2 - i][0] = cube.side[0][2][2 - i];
        cube.side[0][2][2 - i] = cube.side[3][i][2];
        cube.side[3][i][2] = save[i];
    }
}

void Rotate::Up_(Cube& cube) {
    Rot1_(cube, 1);
    int i;
    Cube::Colors save[3];
    for (i = 0; i < 3; ++i) {
        save[i] = cube.side[5][0][i];
        cube.side[5][0][i] = cube.side[4][0][i];
        cube.side[4][0][i] = cube.side[3][0][i];
        cube.side[3][0][i] = cube.side[2][0][i];
        cube.side[2][0][i] = save[i];
    }
}

void Rotate::Down_(Cube& cube) {
    Rot1_(cube, 0);
    int i;
    Cube::Colors save[3];
    for (i = 0; i < 3; ++i) {
        save[i] = cube.side[5][2][i];
        cube.side[5][2][i] = cube.side[2][2][i];
        cube.side[2][2][i] = cube.side[3][2][i];
        cube.side[3][2][i] = cube.side[4][2][i];
        cube.side[4][2][i] = save[i];
    }
}

void Rotate::Xrot(Cube& cube) {
    Rot2(cube, 0, 4, 1, 2);
    Rot1(cube, 3);
    Rot1_(cube, 5);
    Rot1(cube, 4);
    Rot1(cube, 4);
    Rot1(cube, 0);
    Rot1(cube, 0);
}

void Rotate::Yrot(Cube& cube) {
    Rot2(cube, 2, 3, 4, 5);
    Rot1_(cube, 0);
    Rot1(cube, 1);
}

void Rotate::Zrot(Cube& cube) {
    Rot2(cube, 0, 3, 1, 5);
    Rot1(cube, 2);
    Rot1(cube, 3);
    Rot1(cube, 1);
    Rot1(cube, 0);
    Rot1_(cube, 4);
    Rot1(cube, 5);
}