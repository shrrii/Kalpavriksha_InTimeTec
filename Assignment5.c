//Implement a program in C that performs advanced CRUD (Create, Read, Update, Delete) operations on a singly linked list.
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};

void add_end(struct Node** head, int element) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = element;
    newnode->next = NULL;
    if (*head == NULL) { 
        *head = newnode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
}

void add_beginning(struct Node** head, int element) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = element;
    newnode->next = *head;
    *head = newnode;
}

void add_pos(struct Node** head, int element, int pos) {
    if (pos <= 0) {
        printf("Invalid position.\n");
        return;
    }
    if (pos == 1) {
        add_beginning(head, element);
        return;
    }
    struct Node* temp = *head;
    for (int i = 1; i < pos - 1; i++) {
        if (temp == NULL) {
            printf("Invalid position.\n");
            return;
        }
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Invalid position.\n");
        return;
    }
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = element;
    newnode->next = temp->next;
    temp->next = newnode;
}

void display(struct Node* head) {
    if (head == NULL) {
        printf("No element.\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void update_pos(struct Node* head, int pos, int element) {
    if (pos <= 0) {
        printf("Invalid position.\n");
        return;
    }
    struct Node* temp = head;
    for (int i = 1; i < pos; i++) {
        if (temp == NULL) {
            printf("Invalid position.\n");
            return;
        }
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Invalid position.\n");
        return;
    }
    temp->data = element;
}

void delete_first(struct Node** head) {
    if (*head == NULL) {
        printf("No element in the list.\n");
        return;
    }
    struct Node* temp = *head;
    *head = temp->next;
    free(temp);
}

void delete_last(struct Node** head) {
    if (*head == NULL) {
        printf("No element in the list.\n");
        return;
    }
    if ((*head)->next == NULL) { 
        free(*head);
        *head = NULL;
        return;
    }
    struct Node* temp = *head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

void delete_pos(struct Node** head, int pos) {
    if (*head == NULL) {
        printf("No element in the list.\n");
        return;
    }
    if (pos <= 0) {
        printf("Invalid position.\n");
        return;
    }
    if (pos == 1) {
        delete_first(head);
        return;
    }
    struct Node* ptr1 = *head;
    struct Node* ptr2 = ptr1->next;
    for (int i = 1; i < pos - 1; i++) {
        if (ptr2 == NULL) {
            printf("Invalid position.\n");
            return;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    if (ptr2 == NULL) {
        printf("Invalid position.\n");
        return;
    }
    ptr1->next = ptr2->next;
    free(ptr2);
}

int main() {
    struct Node* head = NULL;
    int n;
    printf("Enter the number of operations: ");
    scanf("%d", &n);
    if(n<1||n>100)
    {
      printf("please enter number of operations in range 1<=n<=100.\n");
      scanf("%d", &n);
    }
    printf("_____Menu_____\n");
    printf("1. Add element to the end.\n");
    printf("2. Add element at the beginning.\n");
    printf("3. Add element at position.\n");
    printf("4. Display all elements.\n");
    printf("5. Update element at position.\n");
    printf("6. Delete the first element.\n");
    printf("7. Delete the last element.\n");
    printf("8. Delete the element at position.\n");

    int query, element, pos;
    while (n--) {
        printf("Choose one option: ");
        scanf("%d", &query);
        switch (query) {
            case 1:
                printf("Enter the element to add at the end: ");
                scanf("%d", &element);
                add_end(&head, element);
                break;
            case 2:
                printf("Enter the element to add at the beginning: ");
                scanf("%d", &element);
                add_beginning(&head, element);
                break;
            case 3:
                printf("Enter the element to add: ");
                scanf("%d", &element);
                printf("Enter position to add element: ");
                scanf("%d", &pos);
                add_pos(&head, element, pos);
                break;
            case 4:
                display(head);
                break;
            case 5:
                printf("Enter position to update element: ");
                scanf("%d", &pos);
                printf("Enter element for update: ");
                scanf("%d", &element);
                update_pos(head, pos, element);
                break;
            case 6:
                delete_first(&head);
                break;
            case 7:
                delete_last(&head);
                break;
            case 8:
                printf("Enter position to delete element: ");
                scanf("%d", &pos);
                delete_pos(&head, pos);
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
    printf("All operations completed.\n");
    return 0;
}
