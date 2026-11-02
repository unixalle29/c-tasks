#include <stdio.h>

#include "harmonic.h"

#define MAX_VALUES 100

int main(void) {
    int count;
    double values[MAX_VALUES];

    printf("Count: ");
    if (scanf("%d", &count) != 1 || count < 1 || count > MAX_VALUES) {
        printf("invalid count\n");
        return 1;
    }

    for (int index = 0; index < count; index++) {
        printf("Value: ");
        if (scanf("%lf", &values[index]) != 1 || values[index] <= 0) {
            printf("invalid value\n");
            return 1;
        }
    }

    printf("Harmonic mean = %.6f\n", HARMONIC_MEAN(values, count));
    return 0;
}
