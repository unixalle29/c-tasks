#include <stdio.h>

int main(void) {
    int n;
    int numbers[100];
    int minimum;
    int maximum;
    int sum = 0;

    printf("N: ");
    if (scanf("%d", &n) != 1 || n < 1 || n > 100) {
        printf("wrong N\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        if (scanf("%d", &numbers[i]) != 1) {
            printf("wrong number\n");
            return 1;
        }
    }

    minimum = numbers[0];
    maximum = numbers[0];
    for (int i = 0; i < n; i++) {
        if (numbers[i] < minimum) {
            minimum = numbers[i];
        }
        if (numbers[i] > maximum) {
            maximum = numbers[i];
        }
        sum += numbers[i];
    }

    printf("min = %d\n", minimum);
    printf("max = %d\n", maximum);
    printf("sum = %d\n", sum);
    return 0;
}
