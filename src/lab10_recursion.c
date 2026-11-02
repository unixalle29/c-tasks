#include <stdio.h>

long long factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

int digit_sum(int n) {
    if (n < 10) {
        return n;
    }
    return n % 10 + digit_sum(n / 10);
}

int main(void) {
    int n;

    printf("n: ");
    if (scanf("%d", &n) != 1 || n < 0 || n > 20) {
        printf("wrong n\n");
        return 1;
    }

    printf("factorial = %lld\n", factorial(n));
    printf("digit sum = %d\n", digit_sum(n));
    return 0;
}
