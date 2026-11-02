#include <stdio.h>

int main(void) {
    int code;
    double volume;

    printf("Enter ASCII code: ");
    if (scanf("%d", &code) != 1) {
        printf("invalid code\n");
        return 1;
    }
    printf("%c\n", code);

    printf("Enter volume in liters: ");
    if (scanf("%lf", &volume) != 1 || volume < 0) {
        printf("invalid volume\n");
        return 1;
    }
    printf("molecules = %.2e\n", volume * 1000.0 / 3.0e-23);

    for (int row = 1; row <= 4; row++) {
        for (int star = 0; star < row; star++) {
            putchar('*');
        }
        putchar('\n');
    }

    return 0;
}
