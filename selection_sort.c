//selection sort on linked list
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void selection_sort(struct Node* head) {
    if (head == NULL) return;

    struct Node* i;
    struct Node* j;
    struct Node* min_node;
    int temp;

    for (i = head; i != NULL; i = i->next) {
        min_node = i;
        for (j = i->next; j != NULL; j = j->next) {
            if (j->data < min_node->data) {
                min_node = j;
            }
        }
        
        if (min_node != i) {
            temp = i->data;
            i->data = min_node->data;
            min_node->data = temp;
        }
    }
}

void create_list(struct Node** head, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = *head;
    *head = new_node;
}

void print_list(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int n, value;

    printf("Enter the size of the linked list: ");
    scanf("%d", &n);

    printf("Enter the elements of the linked list:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        create_list(&head, value);
    }

    selection_sort(head);

    printf("Sorted linked list is:\n");
    print_list(head);

    return 0;
}
