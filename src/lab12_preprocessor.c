#include <stdio.h>

#include "harmonic.h"

int main(void) {
    int count;
    double sum = 0;

    printf("Count: ");
    if (scanf("%d", &count) != 1 || count < 1) {
        printf("invalid count\n");
        return 1;
    }

    for (int index = 0; index < count; index++) {
        double value;
        printf("Value: ");
        if (scanf("%lf", &value) != 1 || value <= 0) {
            printf("invalid value\n");
            return 1;
        }
        sum += 1.0 / value;
    }

    printf("Harmonic mean = %.6f\n", HARMONIC_MEAN(count, sum));
    return 0;
}
