#include <stdio.h>

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    return a / b;
}

double apply(double a, double b, double (*operation)(double, double)) {
    return operation(a, b);
}

int main(void) {
    double a;
    double b;
    char operation;
    double (*function)(double, double);

    while (1) {
        printf("Enter a op b (q to quit): ");
        if (scanf("%lf", &a) != 1) {
            char quit;
            if (scanf(" %c", &quit) == 1 && quit == 'q') {
                break;
            }
            printf("invalid input\n");
            return 1;
        }
        if (scanf(" %c %lf", &operation, &b) != 2) {
            printf("invalid input\n");
            return 1;
        }

        function = NULL;
        if (operation == '+') {
            function = add;
        } else if (operation == '-') {
            function = subtract;
        } else if (operation == '*') {
            function = multiply;
        } else if (operation == '/') {
            function = divide;
        }

        if (function == NULL) {
            printf("unknown operation\n");
            continue;
        }
        if (operation == '/' && b == 0) {
            printf("division by zero\n");
            continue;
        }

        printf("result = %.2f\n", apply(a, b, function));
    }

    return 0;
}
