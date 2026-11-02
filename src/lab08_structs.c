#include <stdio.h>

#define CSIZE 4

struct name {
    char surname[32];
    char first_name[32];
};

struct student {
    struct name name;
    float grade[3];
    float average;
};

int input_grades(struct student *student) {
    printf("Grades for %s %s: ", student->name.first_name, student->name.surname);
    for (int index = 0; index < 3; index++) {
        if (scanf("%f", &student->grade[index]) != 1) {
            return 0;
        }
        if (student->grade[index] < 2 || student->grade[index] > 5) {
            return 0;
        }
    }
    return 1;
}

void compute_average(struct student *student) {
    student->average = (student->grade[0] + student->grade[1] + student->grade[2]) / 3.0f;
}

void print_student(const struct student *student) {
    printf("%s %s: %.2f %.2f %.2f average %.2f\n", student->name.first_name,
           student->name.surname, student->grade[0], student->grade[1], student->grade[2],
           student->average);
}

void print_class_averages(const struct student students[CSIZE]) {
    printf("Class averages:");
    for (int subject = 0; subject < 3; subject++) {
        float sum = 0;
        for (int index = 0; index < CSIZE; index++) {
            sum += students[index].grade[subject];
        }
        printf(" %.2f", sum / CSIZE);
    }
    printf("\n");
}

int main(void) {
    struct student students[CSIZE] = {
        {{"Ivanov", "Ivan"}, {0, 0, 0}, 0},
        {{"Petrov", "Petr"}, {0, 0, 0}, 0},
        {{"Sidorova", "Anna"}, {0, 0, 0}, 0},
        {{"Smirnova", "Olga"}, {0, 0, 0}, 0},
    };

    for (int index = 0; index < CSIZE; index++) {
        if (!input_grades(&students[index])) {
            printf("invalid grades\n");
            return 1;
        }
        compute_average(&students[index]);
    }

    for (int index = 0; index < CSIZE; index++) {
        print_student(&students[index]);
    }
    print_class_averages(students);
    return 0;
}
