#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct name {
    char surname[32];
    char first_name[32];
};

struct student {
    struct name name;
    float grade[3];
    float average;
    struct student *next;
};

void compute_average(struct student *student) {
    student->average = (student->grade[0] + student->grade[1] + student->grade[2]) / 3.0f;
}

struct student *create_student(void) {
    struct student *student = malloc(sizeof(*student));
    if (student == NULL) {
        return NULL;
    }

    printf("Surname: ");
    if (scanf("%31s", student->name.surname) != 1) {
        free(student);
        return NULL;
    }
    printf("Name: ");
    if (scanf("%31s", student->name.first_name) != 1) {
        free(student);
        return NULL;
    }
    printf("Grades: ");
    for (int index = 0; index < 3; index++) {
        if (scanf("%f", &student->grade[index]) != 1) {
            free(student);
            return NULL;
        }
    }

    compute_average(student);
    student->next = NULL;
    return student;
}

void append_student(struct student **head, struct student *student) {
    if (*head == NULL) {
        *head = student;
        return;
    }
    struct student *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = student;
}

void print_student(const struct student *student) {
    printf("%s %s: %.2f %.2f %.2f average %.2f\n", student->name.first_name,
           student->name.surname, student->grade[0], student->grade[1], student->grade[2],
           student->average);
}

void print_list(const struct student *head) {
    if (head == NULL) {
        printf("list is empty\n");
        return;
    }
    for (const struct student *current = head; current != NULL; current = current->next) {
        print_student(current);
    }
}

void swap_data(struct student *first, struct student *second) {
    struct name name = first->name;
    float grade[3];
    float average;

    first->name = second->name;
    second->name = name;

    for (int index = 0; index < 3; index++) {
        grade[index] = first->grade[index];
        first->grade[index] = second->grade[index];
        second->grade[index] = grade[index];
    }

    average = first->average;
    first->average = second->average;
    second->average = average;
}

void sort_list(struct student *head) {
    for (struct student *first = head; first != NULL; first = first->next) {
        for (struct student *second = first->next; second != NULL; second = second->next) {
            if (strcmp(first->name.surname, second->name.surname) > 0) {
                swap_data(first, second);
            }
        }
    }
}

struct student *find_student(struct student *head, const char *surname) {
    for (struct student *current = head; current != NULL; current = current->next) {
        if (strcmp(current->name.surname, surname) == 0) {
            return current;
        }
    }
    return NULL;
}

void delete_student(struct student **head, const char *surname) {
    struct student **current = head;
    while (*current != NULL && strcmp((*current)->name.surname, surname) != 0) {
        current = &(*current)->next;
    }
    if (*current == NULL) {
        printf("not found\n");
        return;
    }
    struct student *deleted = *current;
    *current = deleted->next;
    free(deleted);
    printf("deleted\n");
}

void insert_after(struct student *head, const char *surname) {
    struct student *current = find_student(head, surname);
    if (current == NULL) {
        printf("not found\n");
        return;
    }
    struct student *student = create_student();
    if (student == NULL) {
        printf("memory error\n");
        return;
    }
    student->next = current->next;
    current->next = student;
    printf("inserted\n");
}

int count_students(const struct student *head) {
    int count = 0;
    for (const struct student *current = head; current != NULL; current = current->next) {
        count++;
    }
    return count;
}

void free_list(struct student *head) {
    while (head != NULL) {
        struct student *next = head->next;
        free(head);
        head = next;
    }
}

int main(void) {
    struct student *head = malloc(sizeof(*head));
    if (head == NULL) {
        printf("memory error\n");
        return 1;
    }

    strcpy(head->name.surname, "Ivanov");
    strcpy(head->name.first_name, "Ivan");
    head->grade[0] = 4;
    head->grade[1] = 5;
    head->grade[2] = 4;
    compute_average(head);
    head->next = NULL;

    int choice;
    while (1) {
        printf("1 add, 2 print, 3 sort, 4 delete, 5 insert, 6 search, 7 count, 0 exit\n");
        printf("Choice: ");
        if (scanf("%d", &choice) != 1) {
            break;
        }
        if (choice == 0) {
            break;
        }
        if (choice == 1) {
            struct student *student = create_student();
            if (student == NULL) {
                printf("memory error\n");
                break;
            }
            append_student(&head, student);
        } else if (choice == 2) {
            print_list(head);
        } else if (choice == 3) {
            sort_list(head);
            printf("sorted\n");
        } else if (choice == 4) {
            char surname[32];
            printf("Surname: ");
            if (scanf("%31s", surname) != 1) {
                break;
            }
            delete_student(&head, surname);
        } else if (choice == 5) {
            char surname[32];
            printf("Insert after surname: ");
            if (scanf("%31s", surname) != 1) {
                break;
            }
            insert_after(head, surname);
        } else if (choice == 6) {
            char surname[32];
            printf("Surname: ");
            if (scanf("%31s", surname) != 1) {
                break;
            }
            struct student *student = find_student(head, surname);
            if (student == NULL) {
                printf("not found\n");
            } else {
                print_student(student);
            }
        } else if (choice == 7) {
            printf("count: %d\n", count_students(head));
        } else {
            printf("unknown choice\n");
        }
    }

    free_list(head);
    return 0;
}
