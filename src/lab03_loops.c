#include <stdio.h>

int main(void) {
    int code;

    printf("Enter text, ESC to stop:\n");
    while ((code = getchar()) != 27) {
        printf("%d ", code);
    }
    printf("\n");
    return 0;
}
