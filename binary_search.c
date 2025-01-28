//binary search using linked list
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void binary_search(struct Node* head, int k) {
    struct Node* slow = head;
    struct Node* fast = head;
    int n = 0;
    while (fast != NULL) {
        n++;
        fast = fast->next;
    }
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        slow = head;
        for (int i = 0; i < mid; i++) {
            slow = slow->next;
        }
        if (slow->data == k) {
            printf("Element found.\n");
            return;
        } else if (slow->data > k) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    printf("Element not found.\n");
}

void create_list(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int n, data, k;
    
    printf("Enter the size of the linked list: ");
    scanf("%d", &n);
    
    printf("Enter elements of the linked list (sorted):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        create_list(&head, data);
    }
    
    printf("Enter the element to search in the list: ");
    scanf("%d", &k);
    
    binary_search(head, k);
    
    return 0;
}
