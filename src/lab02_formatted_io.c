#include <math.h>
#include <stdio.h>

#define PI 3.14159265358979323846

static void print_ascii(int code) {
    putchar(code);
}

static void print_star_triangle(int rows) {
    for (int row = 1; row <= rows; row++) {
        for (int star = 0; star < row; star++) {
            putchar('*');
        }
        putchar('\n');
    }
}

static double sphere_mass(double radius, double density) {
    double volume = 4.0 / 3.0 * PI * radius * radius * radius;
    return density * volume;
}

int main(void) {
    print_ascii(66);
    putchar('\n');

    print_star_triangle(4);

    printf("mass = %.6f\n", sphere_mass(2.0, 1000.0));
    return 0;
}
