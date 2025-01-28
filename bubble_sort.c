//bubble sort on linked list
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void swap(struct Node* a, struct Node* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

void bubble_sort(struct Node* head) {
    if (head == NULL) return;

    struct Node* i;
    struct Node* j;
    int swapped;
    
    do {
        swapped = 0;
        i = head;
        
        while (i != NULL && i->next != NULL) {
            j = i->next;
            if (i->data > j->data) {
                swap(i, j);
                swapped = 1;
            }
            i = i->next;
        }
    } while (swapped);
}

void create_list(struct Node** head, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head;
    
    new_node->data = new_data;
    new_node->next = NULL;
    
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    
    while (last->next != NULL) {
        last = last->next;
    }
    
    last->next = new_node;
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

    bubble_sort(head);

    printf("Sorted linked list is:\n");
    print_list(head);

    return 0;
}
