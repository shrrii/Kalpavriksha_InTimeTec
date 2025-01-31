//Implement stack using one queue
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct Queue {
    int arr[MAX_SIZE];
    int front, rear;
} Queue;

void initQueue(Queue* q) {
    q->front = 0;
    q->rear = -1;
}

int isEmpty(Queue* q) {
    return q->front > q->rear;
}

int isFull(Queue* q) {
    return q->rear == MAX_SIZE - 1;
}

void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full!\n");
        return;
    }
    q->arr[++(q->rear)] = value;
}

int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    return q->arr[(q->front)++];
}

void push(Queue* q, int value) {
    enqueue(q, value);
    int n = q->rear - q->front;
    while (n--) {
        enqueue(q, dequeue(q));
    }
}

int pop(Queue* q) {
    if (isEmpty(q)) {
        printf("Stack is empty!\n");
        return -1;
    }
    return dequeue(q);
}

int peek(Queue* q) {
    if (isEmpty(q)) {
        printf("Stack is empty!\n");
        return -1;
    }
    return q->arr[q->front];
}

int size(Queue* q) {
    return q->rear - q->front + 1;
}

void display(Queue* q) {
    if (isEmpty(q)) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

int main() {
    Queue q;
    initQueue(&q);
    int choice, value;
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Check if Empty\n");
        printf("5. Size of Stack\n");
        printf("6. Display Stack\n");
        printf("7. Exit\n");

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&q, value);
                break;
            case 2:
                value = pop(&q);
                if (value != -1) {
                    printf("Popped element: %d\n", value);
                }
                break;
            case 3:
                value = peek(&q);
                if (value != -1) {
                    printf("Top element: %d\n", value);
                }
                break;
            case 4:
                if (isEmpty(&q)) {
                    printf("Stack is empty.\n");
                } else {
                    printf("Stack is not empty.\n");
                }
                break;
            case 5:
                printf("Size of stack: %d\n", size(&q));
                break;
            case 6:
                display(&q);
                break;
            case 7:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
