//quick sort on linked list
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void printList(struct Node* curr) {
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

struct Node* getTail(struct Node* cur) {
    while (cur != NULL && cur->next != NULL)
        cur = cur->next;
    return cur;
}

struct Node* partition(struct Node* head, struct Node* tail) {
    struct Node* pivot = head;
    struct Node* pre = head;
    struct Node* curr = head;

    while (curr != tail->next) {
        if (curr->data < pivot->data) {
            int temp = curr->data;
            curr->data = pre->next->data;
            pre->next->data = temp;
            pre = pre->next;
        }
        curr = curr->next;
    }

    int currData = pivot->data;
    pivot->data = pre->data;
    pre->data = currData;

    return pre;
}

void quickSortHelper(struct Node* head, struct Node* tail) {
    if (head == NULL || head == tail) {
        return;
    }

    struct Node* pivot = partition(head, tail);
    quickSortHelper(head, pivot);
    quickSortHelper(pivot->next, tail);
}

struct Node* quickSort(struct Node* head) {
    struct Node* tail = getTail(head);
    quickSortHelper(head, tail);
    return head;
}

struct Node* createNode(int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

int main() {
    int n;
    printf("Enter the number of elements in the linked list: ");
    scanf("%d", &n);

    struct Node* head = NULL;
    struct Node* temp = NULL;

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        struct Node* newNode = createNode(value);

        if (head == NULL) {
            head = newNode;
        } else {
            temp->next = newNode;
        }
        temp = newNode;
    }

    head = quickSort(head);
    printf("Sorted linked list: ");
    printList(head);

    return 0;
}
