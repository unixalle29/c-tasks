#include <stdio.h>

#define COUNT 4

struct name {
    char first[32];
    char last[32];
};

struct student {
    struct name name;
    int grade;
    int birth_year;
};

int main(void) {
    struct student students[COUNT] = {
        {{"Ivan", "Ivanov"}, 4, 2005},
        {{"Petr", "Petrov"}, 5, 2004},
        {{"Anna", "Sidorova"}, 3, 2006},
        {{"Olga", "Smirnova"}, 5, 2005},
    };

    for (int i = 0; i < COUNT - 1; i++) {
        for (int j = 0; j < COUNT - 1 - i; j++) {
            if (students[j].grade < students[j + 1].grade) {
                struct student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < COUNT; i++) {
        printf("%s %s, grade %d, born %d\n", students[i].name.first, students[i].name.last,
               students[i].grade, students[i].birth_year);
    }
    return 0;
}
