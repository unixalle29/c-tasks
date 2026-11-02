#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};

int main(void) {
    struct node *head = NULL;

    for (int i = 1; i <= 5; i++) {
        struct node *item = malloc(sizeof(*item));
        if (item == NULL) {
            return 1;
        }
        item->value = i;
        item->next = head;
        head = item;
    }

    for (struct node *item = head; item != NULL; item = item->next) {
        printf("%d ", item->value);
    }
    printf("\n");

    while (head != NULL) {
        struct node *next = head->next;
        free(head);
        head = next;
    }
    return 0;
}
