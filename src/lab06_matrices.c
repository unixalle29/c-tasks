#include <stdio.h>

int A[3][4] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12},
};

int B[4][2] = {
    {1, 2},
    {3, 4},
    {5, 6},
    {7, 8},
};

int C[3][2];

int multiply(int a[3][4], int b[4][2], int c[3][2], int n, int m, int k, int l, int p, int q) {
    if (a == NULL || b == NULL || c == NULL) {
        return 1;
    }
    if (m != k || n != p || l != q) {
        return 2;
    }
    for (int row = 0; row < n; row++) {
        for (int column = 0; column < l; column++) {
            c[row][column] = 0;
            for (int index = 0; index < m; index++) {
                c[row][column] += a[row][index] * b[index][column];
            }
        }
    }
    return 0;
}

void print_matrix(int matrix[3][2], int rows, int cols) {
    for (int row = 0; row < rows; row++) {
        for (int column = 0; column < cols; column++) {
            printf("%4d", matrix[row][column]);
        }
        printf("\n");
    }
}

int main(void) {
    int code = multiply(A, B, C, 3, 4, 4, 2, 3, 2);
    int null_code;
    int size_code;

    printf("multiply: %d\n", code);
    if (code == 0) {
        printf("C:\n");
        print_matrix(C, 3, 2);
    }

    null_code = multiply(NULL, B, C, 3, 4, 4, 2, 3, 2);
    printf("NULL: %d\n", null_code);
    if (null_code == 1) {
        printf("error: NULL pointer\n");
    }

    size_code = multiply(A, B, C, 3, 4, 3, 2, 3, 2);
    printf("Wrong size: %d\n", size_code);
    if (size_code == 2) {
        printf("error: wrong dimensions\n");
    }

    printf("Other size: %d\n", multiply(A, B, C, 2, 2, 2, 2, 2, 2));
    return 0;
}
