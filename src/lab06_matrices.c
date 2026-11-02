#include <stdio.h>

int main(void) {
    int a[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
    };
    int b[4][2] = {
        {1, 2},
        {3, 4},
        {5, 6},
        {7, 8},
    };
    int c[3][2] = {0};

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 4; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%4d", c[i][j]);
        }
        printf("\n");
    }
    return 0;
}
