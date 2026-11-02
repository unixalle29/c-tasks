#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double **allocate_matrix(int rows, int cols) {
    double **matrix = malloc((size_t)rows * sizeof(*matrix));
    if (matrix == NULL) {
        return NULL;
    }
    for (int row = 0; row < rows; row++) {
        matrix[row] = malloc((size_t)cols * sizeof(**matrix));
        if (matrix[row] == NULL) {
            for (int previous = 0; previous < row; previous++) {
                free(matrix[previous]);
            }
            free(matrix);
            return NULL;
        }
    }
    return matrix;
}

void free_matrix(double **matrix, int rows) {
    if (matrix == NULL) {
        return;
    }
    for (int row = 0; row < rows; row++) {
        free(matrix[row]);
    }
    free(matrix);
}

int read_matrix(FILE *file, double **matrix, int rows, int cols) {
    for (int row = 0; row < rows; row++) {
        for (int column = 0; column < cols; column++) {
            if (fscanf(file, "%lf", &matrix[row][column]) != 1) {
                return 0;
            }
        }
    }
    return 1;
}

int multiply(double **a, double **b, double **c, int n, int m, int k, int l, int p, int q) {
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

void write_matrix(FILE *stream, double **matrix, int rows, int cols) {
    for (int row = 0; row < rows; row++) {
        for (int column = 0; column < cols; column++) {
            fprintf(stream, "%8.2f", matrix[row][column]);
        }
        fprintf(stream, "\n");
    }
}

int main(void) {
    FILE *input = fopen("input.txt", "r");
    if (input == NULL) {
        printf("cannot open input.txt\n");
        return 1;
    }

    int n;
    int m;
    int k;
    int l;
    if (fscanf(input, "%d %d", &n, &m) != 2 || n <= 0 || m <= 0) {
        printf("invalid input.txt\n");
        fclose(input);
        return 1;
    }

    double **a = allocate_matrix(n, m);
    if (a == NULL) {
        printf("memory error\n");
        fclose(input);
        return 1;
    }
    if (!read_matrix(input, a, n, m)) {
        printf("invalid input.txt\n");
        free_matrix(a, n);
        fclose(input);
        return 1;
    }

    if (fscanf(input, "%d %d", &k, &l) != 2 || k <= 0 || l <= 0) {
        printf("invalid input.txt\n");
        free_matrix(a, n);
        fclose(input);
        return 1;
    }

    double **b = allocate_matrix(k, l);
    double **c = allocate_matrix(n, l);
    if (b == NULL || c == NULL) {
        printf("memory error\n");
        free_matrix(a, n);
        free_matrix(b, k);
        free_matrix(c, n);
        fclose(input);
        return 1;
    }

    if (!read_matrix(input, b, k, l)) {
        printf("invalid input.txt\n");
        free_matrix(a, n);
        free_matrix(b, k);
        free_matrix(c, n);
        fclose(input);
        return 1;
    }
    fclose(input);

    int code = multiply(a, b, c, n, m, k, l, n, l);
    printf("multiply: %d\n", code);

    if (code != 0) {
        if (code == 1) {
            printf("error: NULL pointer\n");
        } else {
            printf("error: wrong dimensions\n");
        }
    }

    if (code == 0) {
        FILE *output = fopen("output.txt", "w");
        if (output == NULL) {
            printf("cannot open output.txt\n");
            code = 1;
        } else {
            printf("C:\n");
            write_matrix(stdout, c, n, l);
            write_matrix(output, c, n, l);
            fclose(output);

            double sum = 0;
            for (int row = 0; row < n; row++) {
                for (int column = 0; column < l; column++) {
                    sum += c[row][column];
                }
            }
            double average = sum / (n * l);
            int best_row = 0;
            int best_col = 0;
            double best_difference = fabs(c[0][0] - average);
            for (int row = 0; row < n; row++) {
                for (int column = 0; column < l; column++) {
                    double difference = fabs(c[row][column] - average);
                    if (difference < best_difference) {
                        best_difference = difference;
                        best_row = row;
                        best_col = column;
                    }
                }
            }
            printf("closest: row=%d col=%d value=%.2f\n", best_row + 1, best_col + 1,
                   c[best_row][best_col]);

            int null_code = multiply(NULL, b, c, n, m, k, l, n, l);
            printf("NULL: %d\n", null_code);
            if (null_code == 1) {
                printf("error: NULL pointer\n");
            }

            int size_code = multiply(a, b, c, n, m, k, l, n, l - 1);
            printf("Wrong size: %d\n", size_code);
            if (size_code == 2) {
                printf("error: wrong dimensions\n");
            }

            printf("Other size: %d\n", multiply(a, b, c, 1, 1, 1, 1, 1, 1));
        }
    }

    free_matrix(a, n);
    free_matrix(b, k);
    free_matrix(c, n);
    return code;
}
