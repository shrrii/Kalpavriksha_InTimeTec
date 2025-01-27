//27-jan-25 Qus-Given two singly Linked Lists, create union and intersection lists that contain the union and intersection of the 
//elements present in the given lists. Each of the two linked lists contains distinct node values.
//Note: The order of elements in output lists doesn’t matter. 
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;   
    struct Node* next;  
};

struct Node* createNode(int x);

int isPresent(struct Node* head, int value) {
    struct Node* curr = head;
    while (curr != NULL) {
        if (curr->data == value) {
            return 1;
        }
        curr = curr->next;
    }
    return 0;
}

struct Node* findUnion(struct Node* head1, struct Node* head2) {
    struct Node* result = NULL;
    struct Node* curr1 = head1;
    struct Node* curr2 = head2;

    while (curr1 != NULL) {
        if (!isPresent(result, curr1->data)) {
            struct Node* newNode = createNode(curr1->data);
            newNode->next = result;
            result = newNode;
        }
        curr1 = curr1->next;
    }

    while (curr2 != NULL) {
        if (!isPresent(result, curr2->data)) {
            struct Node* newNode = createNode(curr2->data);
            newNode->next = result;
            result = newNode;
        }
        curr2 = curr2->next;
    }

    return result;
}

struct Node* findIntersection(struct Node* head1, struct Node* head2) {
    struct Node* result = NULL;
    struct Node* curr1 = head1;

    while (curr1 != NULL) {
        if (isPresent(head2, curr1->data) && !isPresent(result, curr1->data)) {
            struct Node* newNode = createNode(curr1->data);
            newNode->next = result;
            result = newNode;
        }
        curr1 = curr1->next;
    }

    return result;
}

void printList(struct Node* head) {
    struct Node* curr = head;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

struct Node* createNode(int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

struct Node* inputList() {
    struct Node* head = NULL;
    struct Node* temp = NULL;
    int n, value;
    
    printf("Enter the number of elements in the list: ");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &value);
        
        struct Node* newNode = createNode(value);
        
        if (head == NULL) {
            head = newNode;
        } else {
            temp->next = newNode;
        }
        temp = newNode;
    }

    return head;
}

int main() {
    struct Node* head1 = inputList();
    struct Node* head2 = inputList();

    struct Node* unionList = findUnion(head1, head2);
    struct Node* intersectionList = findIntersection(head1, head2);

    printf("Union: ");
    printList(unionList);

    printf("Intersection: ");
    printList(intersectionList);

    return 0;
}
