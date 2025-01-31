//Implementation of stack using two queue
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
typedef struct Queue {
    int arr[MAX_SIZE];
    int front, rear;
} Queue;

void initQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

int isEmptyQueue(Queue* q) {
    return q->front == -1;
}

int sizeQueue(Queue* q) {
    if (isEmptyQueue(q)) return 0;
    return q->rear - q->front + 1;
}

void enqueue(Queue* q, int value) {
    if (q->rear == MAX_SIZE - 1) {
        printf("Queue is full\n");
        return;
    }
    if (q->front == -1) q->front = 0;
    q->arr[++q->rear] = value;
}

int dequeue(Queue* q) {
    if (isEmptyQueue(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    int value = q->arr[q->front++];
    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }
    return value;
}

int front(Queue* q) {
    if (isEmptyQueue(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    return q->arr[q->front];
}

typedef struct Stack {
    Queue q1, q2;
    int N;
} Stack;

void initStack(Stack* s) {
    initQueue(&s->q1);
    initQueue(&s->q2);
    s->N = 0;
}

void push(Stack* s, int value) {
    enqueue(&s->q1, value);
    s->N++;
}

void pop(Stack* s) {
    if (isEmptyQueue(&s->q1)) {
        printf("Stack is empty\n");
        return;
    }

    while (sizeQueue(&s->q1) > 1) {
        enqueue(&s->q2, dequeue(&s->q1));
    }
    dequeue(&s->q1); 
    s->N--;

    Queue temp = s->q1;
    s->q1 = s->q2;
    s->q2 = temp;
}

int top(Stack* s) {
    if (isEmptyQueue(&s->q1)) {
        printf("Stack is empty\n");
        return -1;
    }

    while (sizeQueue(&s->q1) > 1) {
        enqueue(&s->q2, dequeue(&s->q1));
    }

    int value = front(&s->q1);
    enqueue(&s->q2, dequeue(&s->q1));

    Queue temp = s->q1;
    s->q1 = s->q2;
    s->q2 = temp;

    return value;
}

int size(Stack* s) {
    return s->N;
}

int isEmpty(Stack* s) {
    return s->N == 0;
}

void display(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return;
    }
    for (int i = s->q1.front; i <= s->q1.rear; i++) {
        printf("%d ", s->q1.arr[i]);
    }
    printf("\n");
}

int main() {
    Stack s;
    initStack(&s);

    int choice, value;
        printf("\nChoose operation:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Top (Peek)\n");
        printf("4. Size\n");
        printf("5. Check if Empty\n");
        printf("6. Display Stack\n");
        printf("7. Exit\n");
    while (1) {
       

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&s, value);
                break;
            case 2:
                pop(&s);
                break;
            case 3:
                if(top(&s)!=-1)
                {
                 printf("Top element: %d\n", top(&s));   
                }
                break;
            case 4:
                printf("Size of stack: %d\n", size(&s));
                break;
            case 5:
                if (isEmpty(&s)) {
                    printf("Stack is empty\n");
                } else {
                    printf("Stack is not empty\n");
                }
                break;
            case 6:
                printf("Stack elements: ");
                display(&s);
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
