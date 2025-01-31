//Implementation of queue using two stack
#include<stdio.h>
#include<stdlib.h>
#define N 500
int s1[N];
int s2[N];
int top1 = -1;
int top2 = -1;
int count = 0;
int pop1() {
    return s1[top1--];
}
int pop2() {
    return s2[top2--];
}
void push2(int a) {
    if(top2 == N - 1) {
        printf("The queue is full \n");
    } else {
        top2++;
        s2[top2] = a;
    }
}
void push1(int a) {
    if(top1 == N - 1) {
        printf("The queue is full \n");
    } else {
        top1++;
        s1[top1] = a;
    }
}
void enqueue() {
    int data;
    if(top1 == N - 1) {
        printf("Overflow\n");
    } else {
        printf("Enter the data: ");
        scanf("%d", &data);
        push1(data);
        count++;
    }
}
void dequeue() {
    int i;
    int a;
    int b;
    if(top1 == -1) {
        printf("The queue is empty\n");
    } else {
        for(i = 0; i < count; i++) {
            a = pop1();
            push2(a);
        }
        b = pop2();
        printf("The dequeued element is: %d\n", b);
        count--;
        for(i = 0; i < count; i++) {
            push1(pop2());
        }
    }
}
void display() {
    int i;
    if(top1 == -1) {
        printf("There are no elements in the queue\n");
    } else {
        printf("Queue elements: ");
        for(i = 0; i <= top1; i++) {
            printf("%d ", s1[i]);
        }
        printf("\n");
    }
}
int isEmpty() {
    return top1 == -1;
}
int size() {
    return count;
}
void peek() {
    int i;
    int front;
    if(top1 == -1) {
        printf("The queue is empty\n");
    } else {
        for(i = 0; i < count; i++) {
            front = pop1();
            push2(front);
        }
        front = s2[top2];
        printf("The front element is: %d\n", front);
        for(i = 0; i < count; i++) {
            push1(pop2());
        }
    }
}

int main() {
    int choice;
    printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Peek\n5. Check if Queue is Empty\n6. Get Queue Size\n7. Exit\n");
    while(1) {
        printf("Enter the choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                peek();
                break;
            case 5:
                if(isEmpty()) {
                    printf("The queue is empty.\n");
                } else {
                    printf("The queue is not empty.\n");
                }
                break;
            case 6:
                printf("The size of the queue is: %d\n", size());
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
