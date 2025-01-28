//merge sort on linked list
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* merge(struct Node* left, struct Node* right) {
    if (left == NULL) return right;
    if (right == NULL) return left;

    struct Node* result = NULL;

    if (left->data <= right->data) {
        result = left;
        result->next = merge(left->next, right);
    } else {
        result = right;
        result->next = merge(left, right->next);
    }
    return result;
}

struct Node* merge_sort(struct Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    struct Node* mid = head;
    struct Node* fast = head->next;

    while (fast != NULL && fast->next != NULL) {
        mid = mid->next;
        fast = fast->next->next;
    }

    struct Node* left = head;
    struct Node* right = mid->next;
    mid->next = NULL;

    left = merge_sort(left);
    right = merge_sort(right);

    return merge(left, right);
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

    head = merge_sort(head);

    printf("Sorted linked list is:\n");
    print_list(head);

    return 0;
}
