#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_SIZE 256
#define SENTENCE_SIZE 4096

int main(void) {
    char *line = malloc(LINE_SIZE);
    char *sentence = malloc(SENTENCE_SIZE);
    char *end;
    int first = 1;

    if (line == NULL || sentence == NULL) {
        printf("memory error\n");
        free(line);
        free(sentence);
        return 1;
    }

    end = sentence;
    *end = '\0';
    printf("Enter words, finish with a period:\n");

    while (fgets(line, LINE_SIZE, stdin) != NULL) {
        char *dot = strchr(line, '.');
        if (dot != NULL) {
            *dot = '\0';
        }
        line[strcspn(line, "\n")] = '\0';

        if (line[0] != '\0') {
            if (!first) {
                *end++ = ' ';
            }
            char *p = line;
            while (*p != '\0') {
                *end++ = *p++;
            }
            *end = '\0';
            first = 0;
        }

        if (dot != NULL) {
            break;
        }
    }

    printf("Sentence: %s\n", sentence);
    free(line);
    free(sentence);
    return 0;
}
