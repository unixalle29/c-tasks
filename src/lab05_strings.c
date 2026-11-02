#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char line[256];
    char *copy;
    int length;

    printf("Text: ");
    if (fgets(line, sizeof(line), stdin) == NULL) {
        return 1;
    }
    line[strcspn(line, "\n")] = '\0';

    length = strlen(line);
    copy = malloc(length + 1);
    if (copy == NULL) {
        return 1;
    }

    strcpy(copy, line);
    for (int i = 0; i < length; i++) {
        copy[i] = line[length - 1 - i];
    }

    printf("Reverse: %s\n", copy);
    free(copy);
    return 0;
}
