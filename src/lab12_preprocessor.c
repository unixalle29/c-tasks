#include <stdio.h>

#define SQUARE(x) ((x) * (x))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define PRINT_INT(x) printf(#x " = %d\n", (x))

int main(void) {
    int value = 5;

    PRINT_INT(value);
    printf("square = %d\n", SQUARE(value));
    printf("max = %d\n", MAX(3, 7));

#ifdef DEBUG
    printf("debug: %s:%d\n", __FILE__, __LINE__);
#endif

    return 0;
}
