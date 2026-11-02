#include <stdio.h>

double power(double base, int exponent) {
    if (exponent == 0) {
        return 1.0;
    }
    if (exponent < 0) {
        return 1.0 / power(base, -exponent);
    }
    if (base == 0.0) {
        return 0.0;
    }
    return base * power(base, exponent - 1);
}

int main(void) {
    double base;
    int exponent;

    printf("Enter base and exponent: ");
    if (scanf("%lf %d", &base, &exponent) != 2) {
        printf("invalid input\n");
        return 1;
    }

    printf("power = %.6f\n", power(base, exponent));
    printf("0^5 = %.6f\n", power(0.0, 5));
    printf("5^0 = %.6f\n", power(5.0, 0));
    return 0;
}
