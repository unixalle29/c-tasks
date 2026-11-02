#include <stdio.h>

int main(void) {
    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");
    int n;
    int sum = 0;

    if (input == NULL || output == NULL) {
        printf("cannot open file\n");
        return 1;
    }

    if (fscanf(input, "%d", &n) != 1 || n < 0) {
        printf("wrong input\n");
        fclose(input);
        fclose(output);
        return 1;
    }

    for (int i = 0; i < n; i++) {
        int value;
        if (fscanf(input, "%d", &value) != 1) {
            printf("wrong input\n");
            fclose(input);
            fclose(output);
            return 1;
        }
        sum += value;
    }

    fprintf(output, "sum = %d\n", sum);
    fclose(input);
    fclose(output);
    return 0;
}
