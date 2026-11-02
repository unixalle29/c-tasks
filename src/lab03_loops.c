#include <stdio.h>

int main(void) {
    char answer;
    int show_enter;
    int ch;

    printf("Show Enter code? (y/n): ");
    if (scanf(" %c", &answer) != 1) {
        return 1;
    }
    getchar();

    show_enter = (answer == 'y' || answer == 'Y');
    printf("Enter text, ESC to stop:\n");

    while ((ch = getchar()) != 27) {
        if (ch == '\n' && !show_enter) {
            continue;
        }
        printf("oct=%o dec=%d hex=%x\n", ch, ch, ch);
    }

    return 0;
}
