#include <stdio.h>

int month_length_switch(int month) {
    switch (month) {
        case 2:
            return 28;
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        default:
            return 31;
    }
}

int days_left_switch(int day, int month) {
    int total = month_length_switch(month) - day;
    for (int current = month + 1; current <= 12; current++) {
        total += month_length_switch(current);
    }
    return total;
}

int days_left_array(int day, int month) {
    int lengths[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int total = lengths[month - 1] - day;
    for (int current = month; current < 12; current++) {
        total += lengths[current];
    }
    return total;
}

int main(void) {
    int day;
    int month;

    printf("Enter day and month: ");
    if (scanf("%d %d", &day, &month) != 2) {
        printf("invalid date\n");
        return 1;
    }
    if (month < 1 || month > 12 || day < 1 || day > month_length_switch(month)) {
        printf("invalid date\n");
        return 1;
    }

    printf("Switch: %d\n", days_left_switch(day, month));
    printf("Array: %d\n", days_left_array(day, month));
    return 0;
}
