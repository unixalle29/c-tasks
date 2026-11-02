#include <stdio.h>

double add(double a, double b) {
    return a + b;
}

double sub(double a, double b) {
    return a - b;
}

double mul(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    return a / b;
}

int main(void) {
    double (*operations[4])(double, double) = {add, sub, mul, divide};
    char symbols[4] = {'+', '-', '*', '/'};
    double a;
    double b;
    char operation;

    if (scanf("%lf %c %lf", &a, &operation, &b) != 3) {
        printf("wrong input\n");
        return 1;
    }

    for (int i = 0; i < 4; i++) {
        if (operation == symbols[i]) {
            if (operation == '/' && b == 0) {
                printf("division by zero\n");
                return 1;
            }
            printf("%.2f\n", operations[i](a, b));
            return 0;
        }
    }

    printf("unknown operation\n");
    return 1;
}
