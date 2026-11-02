#include <stdio.h>

int main(void) {
    int ch;

    printf("Enter text, ESC to stop:\n");
    while ((ch = getchar()) != 27) {
        if (ch == '\n') {
            continue;
        }
        printf("%c: oct=%o dec=%d hex=%x\n", ch, ch, ch, ch);
    }

    return 0;
}
